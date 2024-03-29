/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:10:33 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/23 17:33:26 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**malloc_map(t_all *s)
{
	int		i;
	char	**tab_map;

	tab_map = NULL;
	tab_map = malloc(sizeof(char *) * (s->map.size.y + 4 + 1));
	if (tab_map == NULL)
		ft_quit(s, "Error\nMalloc");
	i = 0;
	while (i < s->map.size.y + 4)
	{
		tab_map[i] = malloc(sizeof(char) * (s->map.size.x + 4 + 1));
		if (tab_map[i] == NULL)
			ft_quit(s, "Error\nMalloc");
		i++;
	}
	tab_map[i] = NULL;
	return (tab_map);
}

void	space_map(t_all *s)
{
	int	y;
	int	x;

	y = 0;
	while (y < s->map.size.y + 4)
	{
		x = 0;
		while (x < s->map.size.x + 4)
		{
			s->map.map[y][x] = ' ';
			x++;
		}
		y++;
	}
}

void	frame_map(t_all *s)
{
	int	y;
	int	x;

	y = 0;
	while (y < s->map.size.y + 4)
	{
		x = 0;
		while (x < s->map.size.x + 4)
		{
			if (x == 0 || x == s->map.size.x + 4 - 1 || y == 0
				|| y == s->map.size.y + 4 - 1)
				s->map.map[y][x] = '*';
			x++;
		}
		y++;
	}
}

void	fill_map(t_all *s)
{
	t_list	*t;

	t = s->list;
	s->axe.y = 0;
	while (s->axe.y < s->map.size.y)
	{
		s->axe.x = 0;
		while (((char *)s->list->content)[s->axe.x])
		{
			s->map.map[s->axe.y + 2][s->axe.x + 2]
				= ((char *)s->list->content)[s->axe.x];
			s->axe.x++;
		}
		s->list = s->list->next;
		s->axe.y++;
	}
	s->list = t;
}

int	make_map(t_all *s)
{
	s->map.size.x = ft_lstsize_longer(s->list);
	s->map.size.y = ft_lstsize(s->list);
	s->map.map = malloc_map(s);
	space_map(s);
	frame_map(s);
	fill_map(s);
	return (0);
}
