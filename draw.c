/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:56:31 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/15 16:15:36 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void drow_rays(t_mlx *mlxx, double angle, int color)
{
    int x = mlxx->player_x / 4;
    int y = mlxx->player_y / 4;
    int z = 1;
    int xx, yy;

    while (z < 50)
    {
        xx = x - (z * cos(angle));
        yy = y - (z * sin(angle));
        
        // Check for collision with obstacles in your environment
        if (mlxx->map[(int)(yy / 10)][(int)(xx / 10)] == '1') {
            break; // Exit the loop when hitting an obstacle
        }

        my_mlx_pixel_put(&mlxx->img, xx, yy, color);
        z++;
    }
}

void	drow_square(int startx ,int starty, int size, t_data img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	startx = startx * size;
	starty = starty * size;
	while (j < size)
	{
		while (i < size)
		{
			my_mlx_pixel_put(&img,startx + i, starty + j, color);
			i++;
		}
		i = 0;
		j++;
	}
	
}

float distance(int x1, int y1, int x2, int y2)
{
    float x;
    float y;
    float z;
    
    x = x2 - x1;
    y = y2 - y1;
    z = sqrt((x * x) + (y * y));
    return (z);
}

void scan(t_mlx *mlxx, double angle, int color, int i)
{
    t_point h_point = horizontal_ray(mlxx, angle);
    t_point v_point = vertical_ray(mlxx, angle);
    t_point point;
   	double new_dest;

    if (distance(mlxx->player_x, mlxx->player_y, h_point.x, h_point.y) <=
         distance(mlxx->player_x, mlxx->player_y, v_point.x, v_point.y))
    {
        point.x = h_point.x;
        point.y = h_point.y;
    }
    else
    {
        point.x = v_point.x;
        point.y = v_point.y;
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
    draw_line(i, (mlxx->height / 2) + (wall_h / 2), i, (mlxx->height / 2) - (wall_h / 2), mlxx->img, color);

	
}

void	drow_player(t_mlx mlxx, int color)
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
		scan(&mlxx, send_angle, color, i);
		angle += inc;
		send_angle = angle;
		i++;
	}
	// printf("index = %d\n", index);


} 
int    drow(void *param)
{
    int	i;
    int	j;
	t_mlx *mlxx;

	mlxx = (t_mlx *)param;
    i = 0;
    j = 0;
	drow_player (*mlxx, 0xe06666);
	while (mlxx->map[i])
	{
		while (mlxx->map[i][j])
		{
			if (mlxx->map[i][j] == '1')
			{
				drow_square (j,i,10 ,mlxx->img, 0xffffff);
			}
				
			j++;
		}
		j = 0;
		i++;
	}	
	// drow_grid(mlxx);
	my_mlx_pixel_put(&mlxx->img, mlxx->player_x / 4, mlxx->player_y / 4, 0x00ff00);
	drow_rays(mlxx, mlxx->angle, 0x00ff00);
		
	mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
	return 0;
}
