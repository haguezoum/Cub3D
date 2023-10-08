/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:20:54 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/08 17:30:04 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int vurtual_move(int key, t_mlx *mlxx)
{
	float tmp_x;
	float tmp_y;
	double tmp_angle;

	tmp_x = mlxx->player_x;
	tmp_y = mlxx->player_y;
	tmp_angle = mlxx->angle;
	if (key == 124)
		tmp_angle += 0.4;
	if (key == 123)
		tmp_angle -= 0.4;
	if (key == 13)
	{
		tmp_x -= 7 * cos(tmp_angle);
		tmp_y -= 7 * sin(tmp_angle);
	}
	if (key == 1)
	{
		tmp_x +=7 * cos(tmp_angle);
		tmp_y +=7 * sin(tmp_angle);
	}
		if (key == 0)
	{
		tmp_x -= 7 * cos(tmp_angle -  1.5708);
		tmp_y -= 7 * sin(tmp_angle - 1.5708);
	}
		if (key == 2)
	{
		tmp_x -= 7 * cos(tmp_angle +  1.5708);
		tmp_y -= 7 * sin(tmp_angle + 1.5708);
	}
	if (mlxx->map[(int)tmp_y / 40][(int)tmp_x / 40] == '1')
		return (0);
	if (mlxx->map[(int)mlxx->player_y / 40][(int)tmp_x / 40] == '1' || mlxx->map[(int)mlxx->player_y / 40][(int)mlxx->player_x / 40] == '1')
		return (0);
	return (1);
}


int	click_key(int key, t_mlx *mlxx)
{
	// float tmp_x = mlxx->player_x;
	// float tmp_y = mlxx->player_y;
	if (key == 53)
	{
        mlx_destroy_image(mlxx->mlx, mlxx->img.img);
        mlx_destroy_window(mlxx->mlx, mlxx->mlx_win);
		exit(0);
	}
	if (vurtual_move(key, mlxx) == 1)
	{
		if (key == 124)
		mlxx->angle += 0.4;
	if (key == 123)
		mlxx->angle -= 0.4;
	if (key == 13)
	{
		mlxx->player_x -= 7 * cos(mlxx->angle);
		mlxx->player_y -= 7 * sin(mlxx->angle);
	}
	if (key == 0)
	{
		mlxx->player_x -= 7 * cos(mlxx->angle -  1.5708);
		mlxx->player_y -= 7 * sin(mlxx->angle - 1.5708);
	}
		if (key == 2)
	{
		mlxx->player_x -= 7 * cos(mlxx->angle +  1.5708);
		mlxx->player_y -= 7 * sin(mlxx->angle + 1.5708);
	}
	if (key == 1)
	{
		mlxx->player_x += 7 * cos(mlxx->angle );
		mlxx->player_y += 7 * sin(mlxx->angle);
	}
	mlx_destroy_image(mlxx->mlx, mlxx->img.img);	
	printf("%d \n",key);
			mlxx->img.img = mlx_new_image(mlxx->mlx, mlxx-> weight, mlxx->height);
			mlxx->img.addr = mlx_get_data_addr(mlxx->img.img, &mlxx->img.bits_per_pixel, &mlxx->img.line_length,
				&mlxx->img.endian);
			drow(mlxx);
		mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
	}
	
	
	return (0);
}
