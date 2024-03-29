/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:27:09 by gefaivre          #+#    #+#             */
/*   Updated: 2022/02/10 19:43:04 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(t_all *s, int x, int y, int color)
{
	s->mlx.addr[y * s->mlx.line_length / 4 + x] = color;
}

void	printceiling(t_all *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < (H_WINDOW / 2))
	{
		y = 0;
		while (y < W_WINDOW)
		{
			pixel_put(s, y, x, s->parse.rgb_c);
			y++;
		}
		x++;
	}
}

void	printfloor(t_all *s)
{
	int	x;
	int	y;

	x = H_WINDOW / 2;
	while (x < H_WINDOW)
	{
		y = 0;
		while (y < W_WINDOW)
		{
			pixel_put(s, y, x, s->parse.rgb_f);
			y++;
		}
		x++;
	}
}

void	drawline(t_all *s)
{
	if (s->axe.y == 0)
	{
		while (s->axe.y < s->rc.drawstart)
		{
			pixel_put(s, s->axe.x, s->axe.y, s->parse.rgb_c);
			s->axe.y++;
		}
	}
	else if (s->axe.y == s->rc.drawend + 1)
	{
		while (s->axe.y < H_WINDOW)
		{
			pixel_put(s, s->axe.x, s->axe.y, s->parse.rgb_f);
			s->axe.y++;
		}
	}
}
