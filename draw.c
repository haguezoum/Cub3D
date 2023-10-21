/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:56:31 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/21 10:31:25 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	distance(int x1, int y1, int x2, int y2)
{
	float	x;
	float	y;
	float	z;

	x = x2 - x1;
	y = y2 - y1;
	z = sqrt((x * x) + (y * y));
	return (z);
}

void scan(t_mlx *mlxx, double angle, int i)
{
    t_point h_point = horizontal_ray(mlxx, angle);
    t_point v_point = vertical_ray(mlxx, angle);
    t_point point;
   	double new_dest;

    if (distance(mlxx->player_x, mlxx->player_y, h_point.x, h_point.y) <
         distance(mlxx->player_x, mlxx->player_y, v_point.x, v_point.y))
    {
        point.x = h_point.x;
        point.y = h_point.y;
		point.type = 'h';

		point.x_offset = (int)h_point.x % 40;
		
		if (angle >= 0 && angle <= M_PI)
		{
			point.color = 0xa2add0;
			point.color_array = mlxx->color1;
		}
		else
		{
			point.color_array = mlxx->color2;
		}	
    }
    if (distance(mlxx->player_x, mlxx->player_y, h_point.x, h_point.y) >
         distance(mlxx->player_x, mlxx->player_y, v_point.x, v_point.y))
    {
        point.x = v_point.x;
        point.y = v_point.y;
		point.type = 'v';
		
		point.x_offset = (int)v_point.y % 40;
		
		
		if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
		{
			point.color = 0x02e0d9;
			point.color_array = mlxx->color3;
		}
		else
		{
			point.color = 0x02e075;
			point.color_array = mlxx->color4;
		}
    }
	
	
	int distaproj = (mlxx->weight / 2) / tan(M_PI / 6);
	double dist = distance(mlxx->player_x, mlxx->player_y, point.x, point.y);

	// fish eye effect--------------------
	if (mlxx->angle > angle)
		new_dest = dist * cos(mlxx->angle - angle);
	else
		new_dest = dist * cos(angle - mlxx->angle);
	// -----------------------------------

	int wall_h = (40 / new_dest) * distaproj;
	
	draw_line(i, 0 , i, (mlxx->height / 2) , mlxx->img, 0x6fa8dc);
	draw_line(i,(mlxx->height / 2) , i, mlxx->height , mlxx->img, 0x999999);
	
    draw_line_x(i, (mlxx->height / 2) + (wall_h / 2), i, (mlxx->height / 2) - (wall_h / 2), mlxx->img, point.color_array,  point.x_offset);
	
}

void	drow_player(t_mlx mlxx)
{	
	double	angle = mlxx.angle - (M_PI / 6);
	double inc = (M_PI / 3) / mlxx.weight;
	double send_angle = angle;
	int i = 0;

	while (angle < mlxx.angle + (M_PI / 6))
	{
		if (send_angle > 2 * M_PI)
			send_angle = send_angle - (2 * M_PI);
		else if (send_angle < 0)
			send_angle = send_angle + (2 * M_PI);
		scan(&mlxx, send_angle, i);
		angle += inc;
		send_angle = angle;
		i++;
	}
}


int    drow(void *param)
{
	t_mlx *mlxx;

	mlxx = (t_mlx *)param;

	drow_player (*mlxx);
	drow_mini_map(mlxx);
	
	mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
	return 0;
}
