/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:15:13 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/08 21:33:42 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
float	fmodule(float i)
{
	if (i < 0)
		i = -i;
	return (i);
}

float	maxx(float a, float b)
{
	if (a > b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

void	draw_line(t_point p1, t_point p2, t_data img, int color)
{
	float	x_step;
	float	y_step;
	float	max;

	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = maxx(fmodule(x_step), fmodule(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		my_mlx_pixel_put(&img, p1.x, p1.y, color);
		p1.x += x_step;
		p1.y += y_step;
	}
}
