/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:56:36 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/10 20:02:31 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void drow_rays(t_mlx *mlxx, double angle, int color)
{
	int x;
	int y;
	int z;
	int xx;
	int yy;


	x = mlxx->player_x;
	y = mlxx->player_y;
	z = 1;
	xx = x - (z * cos(angle));
	yy = y - (z * sin(angle));
	while (z < 100)
	{
		xx = x - (z * cos(angle));
		yy = y - (z * sin(angle));
		my_mlx_pixel_put(&mlxx->img,xx  , yy, color);
		z++;
	}
}

void horizontal_ray(t_mlx *mlxx)
{
    // t_data img;
    int y_intercept;
    int x_intercept;
    // int x_step;
    // img = ;
    y_intercept = (int)(mlxx->player_y / 40) * 40;
    x_intercept = mlxx->player_x + (y_intercept - mlxx->player_y) / tan(mlxx->angle);
    // x_step = 40 / tan(mlxx->angle);
	// draw_line(10, 10, 400, 100, mlxx->img, 0x00ff00);
	if (!(mlxx->angle >= 0 && mlxx->angle < M_PI))
	{
		x_intercept = mlxx->player_x + (y_intercept - mlxx->player_y) / tan(M_PI - mlxx->angle);
		y_intercept += 40;
	}
	// drow_rays(mlxx, mlxx->angle, 0x00ff);

	draw_line(mlxx->player_x, mlxx->player_y, x_intercept, y_intercept, mlxx->img, 0x00ff00);
    
    printf("x_intercept = %d || y_intercept = %d || angle = %f \n",x_intercept, y_intercept, mlxx->angle * ( 180 / M_PI));    
}