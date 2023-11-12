/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:56:31 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/12 18:56:11 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance(int x1, int y1, int x2, int y2)
{
	double	x;
	double	y;
	double	z;

	x = x2 - x1;
	y = y2 - y1;
	z = sqrt((x * x) + (y * y));
	return (z);
}

void	scan(t_mlx *mlxx, double angle, int i)
{
    t_point h_point = horizontal_ray(mlxx, angle);
    t_point v_point = vertical_ray(mlxx, angle);
    t_point point;
	
   	double new_dest;

    if (distance(mlxx->player_x, mlxx->player_y, h_point.x, h_point.y) <
        	 distance(mlxx->player_x, mlxx->player_y, v_point.x, v_point.y) )
    {
        point.x = h_point.x;
        point.y = h_point.y;
		mlxx->x_offset = (int)h_point.x % 40 ;
		if (angle > 0 && angle < M_PI)
		{
			point.color = 0xa2add0;
			mlxx->color_select = 1;
		}
		else
		{
			point.color = 0xffdd45;
			mlxx->color_select = 2;
		}
    }
    if (distance(mlxx->player_x, mlxx->player_y, h_point.x, h_point.y) >
         distance(mlxx->player_x, mlxx->player_y, v_point.x, v_point.y))
    {
        point.x = v_point.x;
        point.y = v_point.y;
		
		mlxx->x_offset = (int)v_point.y % 40;
		
		if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
		{
			point.color = 0x02e0d9;
			mlxx->color_select = 3;
		}
		else
		{
			point.color = 0x02e075;
			mlxx->color_select = 4;
		}
    }
	int distaproj = (mlxx->w_weight / 2) / tan(M_PI / 6);
	double dist = distance(mlxx->player_x, mlxx->player_y, point.x, point.y);

	if (mlxx->angle > angle)
		new_dest = dist * cos(mlxx->angle - angle);
	else
		new_dest = dist * cos(angle - mlxx->angle);
	int wall_h = (40 / new_dest) * distaproj;
	int tmp_wall_h = wall_h;
	if (wall_h > mlxx->w_height)
		wall_h = mlxx->w_height;
	
	draw_line(i, 0 ,(mlxx->w_height / 2) , mlxx->C_color, mlxx);
	draw_line(i,(mlxx->w_height / 2), mlxx->w_height , mlxx->F_color, mlxx);
	if (mlxx->color_select == 1)
		draw_line_x(i, (mlxx->w_height / 2) + (wall_h / 2), (mlxx->w_height / 2) - (wall_h / 2), mlxx->color1, mlxx, tmp_wall_h);
	if (mlxx->color_select == 2)
		draw_line_x(i, (mlxx->w_height / 2) + (wall_h / 2), (mlxx->w_height / 2) - (wall_h / 2), mlxx->color2, mlxx, tmp_wall_h);
	if (mlxx->color_select == 3)
		draw_line_x(i, (mlxx->w_height / 2) + (wall_h / 2), (mlxx->w_height / 2) - (wall_h / 2), mlxx->color3, mlxx, tmp_wall_h);
	if (mlxx->color_select == 4)
		draw_line_x(i, (mlxx->w_height / 2) + (wall_h / 2), (mlxx->w_height / 2) - (wall_h / 2), mlxx->color4, mlxx, tmp_wall_h);
}

void	drow_player(t_mlx mlxx)
{
	double	angle;
	double	inc;
	double	send_angle;
	int		i;

	angle = mlxx.angle - (M_PI / 6);
	inc = (M_PI / 3) / mlxx.w_weight;
	send_angle = angle;
	i = 0;
	mlxx.color_select = 1;
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

int	drow(void *param)
{
	t_mlx	*mlxx;

	mlxx = (t_mlx *)param;
	drow_player (*mlxx);
	drow_mini_map(mlxx);
	mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
	return (0);
}
