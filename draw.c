/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:56:31 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/17 18:29:41 by abdel-ou         ###   ########.fr       */
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
		
		if (angle >= 0 && angle <= M_PI)
		{
			point.color = 0xa2add0;
		}
		else
		{
			point.color = 0xffdd45;
		}	
    }
    if (distance(mlxx->player_x, mlxx->player_y, h_point.x, h_point.y) >
         distance(mlxx->player_x, mlxx->player_y, v_point.x, v_point.y))
    {
        point.x = v_point.x;
        point.y = v_point.y;
		
		if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
		{
			point.color = 0x02e0d9;
		}
		else
		{
			point.color = 0x02e075;
		}
    }
	
	
	int distaproj = (mlxx->weight / 2) / tan(M_PI / 6);
	double dist = distance(mlxx->player_x, mlxx->player_y, point.x, point.y);
	
	if (mlxx->angle > angle)
		new_dest = dist * cos(mlxx->angle - angle);
	else
		new_dest = dist * cos(angle - mlxx->angle);
	
	int wall_h = (40 / new_dest) * distaproj;
	if (wall_h > mlxx->height)
	{
		wall_h = mlxx->height;
	}
	draw_line(i, 0 , i, (mlxx->height / 2) , mlxx->img, 0x6fa8dc);
	draw_line(i,(mlxx->height / 2) , i, mlxx->height , mlxx->img, 0x999999);
	
    draw_line(i, (mlxx->height / 2) + (wall_h / 2), i, (mlxx->height / 2) - (wall_h / 2), mlxx->img, point.color);
	// printf("butom = %d  || top = %d \n", (mlxx->height / 2) + (wall_h / 2), (mlxx->height / 2) - (wall_h / 2));
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
	unsigned int *img_data = load_color(mlxx, "/Users/abdel-ou/Desktop/wall_40.xpm");
	 int x = 0;
	 int y = 0;
    while (y < 40)
	{
        while (x < 40)
		{
			my_mlx_pixel_put(&mlxx->img, x, y, img_data[y * 40 + x]);
			x++;
        }
		x = 0;
		y++;
    }
	

	mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
	return 0;
}
