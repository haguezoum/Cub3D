/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:56:36 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/12 17:05:49 by abdel-ou         ###   ########.fr       */
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
    int y_intercept;
    int x_intercept;
    int x_step;

	x_step = 40 / tan(M_PI - mlxx->angle);
    if (mlxx->angle >= 0 && mlxx->angle < M_PI)
    {
        y_intercept = (int)(mlxx->player_y / 40) * 40;
        x_intercept = mlxx->player_x + (y_intercept - mlxx->player_y) / tan(mlxx->angle);
    }
    else
    {
        y_intercept = (int)((mlxx->player_y / 40) + 1) * 40;
        x_intercept = mlxx->player_x + (y_intercept - mlxx->player_y) / tan(mlxx->angle);
    }

    while (x_intercept >= 0 && x_intercept < mlxx->weight &&
           y_intercept >= 0 && y_intercept < mlxx->height * 40)
    {
        if (mlxx->map[(int)(y_intercept / 40)][(int)(x_intercept / 40)] == '1' || mlxx->map[(int)(y_intercept / 40) - 1][(int)(x_intercept / 40)] == '1')
            break;

        if (mlxx->angle >= 0 && mlxx->angle < M_PI)
        {
            x_intercept += x_step;
            y_intercept -= 40;
        }
        else
        {
            x_intercept -= x_step;
            y_intercept += 40;
        }
    }
    if (x_intercept <= 0 || x_intercept >= mlxx->weight || y_intercept <= 0 || y_intercept >= mlxx->height)
        return;

    draw_line(mlxx->player_x, mlxx->player_y, x_intercept, y_intercept, mlxx->img, 0x00ff00);
}
