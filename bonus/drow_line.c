/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:15:13 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/15 10:33:06 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(int x0, int x, int color, t_mlx *mlxx)
{
	double	y_increment;
	int		i;
	int		y0;
	int		y1;

	if (x == 0)
	{
		y0 = 0;
		y1 = mlxx->w_height / 2;
	}
	if (x == 1)
	{
		y0 = mlxx->w_height / 2;
		y1 = mlxx->w_height;
	}
	y_increment = (y1 - y0) / (double)(mlxx->w_height / 2);
	i = 0;
	while (i <= mlxx->w_height / 2)
	{
		if (x0 >= 0 && x0 < mlxx->w_weight && y0 >= 0 && y0 < mlxx->w_height)
			my_mlx_pixel_put(&mlxx->img, round(x0), round(y0), color);
		y0 += y_increment;
		i++;
	}
}

void	drow_buttom(int x0, unsigned int *color, t_mlx *mlxx, int tmp_wall_h)
{
	int		i;
	double	conter;
	float	coff;
	float	ii;
	int		colors;

	i = 0;
	conter = mlxx->w_height / 2;
	coff = 40.0 / (tmp_wall_h);
	ii = coff * (tmp_wall_h / 2);
	while (i <= (mlxx->wall_h / 2))
	{
		colors = (int)ii * 40 + mlxx->x_offset;
		if (x0 >= 0 && x0 < mlxx->w_weight && conter >= 0 && conter
			< mlxx->w_height && colors < 1600)
			my_mlx_pixel_put(&mlxx->img, round(x0),
				round(conter), color[colors]);
		conter -= ((-mlxx->wall_h) / (double)mlxx->wall_h);
		ii += coff;
		i++;
	}
}

void	draw_line_x(int x0, unsigned int *color, t_mlx *mlxx, int tmp_wall_h)
{
	int		i;
	double	conter;
	float	coff;
	float	ii;
	int		colors;

	i = 0;
	conter = mlxx->w_height / 2;
	coff = 40.0 / (tmp_wall_h);
	ii = coff * (tmp_wall_h / 2);
	while (i <= (mlxx->wall_h / 2))
	{
		colors = (int)ii * 40 + mlxx->x_offset;
		if (x0 >= 0 && x0 < mlxx->w_weight && conter >= 0 && conter
			< mlxx->w_height && colors < 1600)
			my_mlx_pixel_put(&mlxx->img, round(x0),
				round(conter), color[colors]); 
		conter += ((-mlxx->wall_h) / (double)mlxx->wall_h);
		ii -= coff;
		i++;
	}
	drow_buttom(x0, color, mlxx, tmp_wall_h);
}
