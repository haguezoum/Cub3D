/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:22:45 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/15 15:22:07 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	drow_rays(t_mlx *mlxx, double angle, int color)
{
	int		xx;
	int		yy;
	int		x;
	int		y;
	double	z;

	x = mlxx->player_x / 4 + (1180 - mlxx->player_x / 4);
	y = mlxx->player_y / 4 + (620 - mlxx->player_y / 4);
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
		xx = x - (100 * cos(angle + z));
		yy = y - (100 * sin(angle + z));
		my_mlx_pixel_put(&mlxx->img, xx, yy, color);
		z += 0.001;
	}
}

void	drow_square(t_mlx *mlxx, int startx, int starty, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	startx = (startx * 10) + (1180 - mlxx->player_x / 4);
	starty = (starty * 10) + (620 - mlxx->player_y / 4);
	while (j < 10)
	{
		while (i < 10)
		{
			if ((startx + i) >= 0 && (startx + i) <= 1280 && (starty + j) >= 0
				&& (starty + j) <= 720)
			{
				if (distance(startx + i, starty + j,
						mlxx->player_x / 4 + (1180 - mlxx->player_x / 4),
						mlxx->player_y / 4 + (620 - mlxx->player_y / 4)) < 100)
					my_mlx_pixel_put(&mlxx->img, (startx + i),
						(starty + j), color);
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
	int	z;

	i = 0;
	j = 0;
	z = 1;
	while (mlxx->map[i])
	{
		while (mlxx->map[i][j])
		{
			if (mlxx->map[i][j] == '1')
				drow_square(mlxx, j, i, 0xffffff);
			if (mlxx->map[i][j] != '1')
				drow_square(mlxx, j, i, 0x000000);
			j++;
		}
		j = 0;
		i++;
	}
	drow_rays(mlxx, mlxx->angle, 0x00ff00);
}
