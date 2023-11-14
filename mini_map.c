/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:22:45 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/14 11:04:33 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drow_rays(t_mlx *mlxx, double angle, int color)
{
	int		xx;
	int		yy;
	int		x;
	int		y;
	double	z;

	x = mlxx->player_x / 4 + (50 - mlxx->player_x / 4);
	y = mlxx->player_y / 4 + (50 - mlxx->player_y / 4);
	z = 0;
	while (z < 2 * M_PI) 
	{
		xx = x - (4 * cos(angle + z));
		yy = y - (4 * sin(angle + z));
		my_mlx_pixel_put(&mlxx->img, xx, yy, color);
		z += 0.01;
	}
	z = 0;
	while (z < 2 * M_PI) 
	{
		xx = x - (50 * cos(angle + z));
		yy = y - (50 * sin(angle + z));
		my_mlx_pixel_put(&mlxx->img, xx, yy, color);
		z += 0.001;
	}
}

void	drow_square(t_mlx *mlxx, int startx, int starty, t_data img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	startx = (startx * 10) + (50 - mlxx->player_x / 4);
	starty = (starty * 10) + (50 - mlxx->player_y / 4);
	while (j < 10)
	{
		while (i < 10)
		{ 	
			if ((startx + i) >= 0 && (startx + i) <= 100 && (starty + j) >= 0 && (starty + j) <= 100)
			{
				if (distance(startx + i, starty + j, mlxx->player_x / 4 + (50 - mlxx->player_x / 4), mlxx->player_y / 4 + (50 - mlxx->player_y / 4)) < 50)
				{
					my_mlx_pixel_put(&img, (startx + i), (starty + j), color);
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	drow_mini_map(t_mlx	*mlxx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlxx->map[i])
	{
		while (mlxx->map[i][j])
		{
			if (mlxx->map[i][j] == '1')
				drow_square(mlxx, j, i, mlxx->img, 0xffffff);
			if (mlxx->map[i][j] != '1')
				drow_square(mlxx, j, i, mlxx->img, 0x000000);
			j++;
		}
		j = 0;
		i++;
	}
	drow_rays(mlxx, mlxx->angle, 0x00ff00);
}
