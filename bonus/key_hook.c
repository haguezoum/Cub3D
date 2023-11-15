/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:20:54 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/15 12:39:31 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	moves(float *tmp_x, float *tmp_y, double *tmp_angle, int *key)
{
	if (*key == 124)
		(*tmp_angle) += 0.12;
	if (*key == 123)
		(*tmp_angle) -= 0.12;
	if (*key == 13)
	{
		(*tmp_x) -= 10 * cos((*tmp_angle));
		(*tmp_y) -= 10 * sin((*tmp_angle));
	}
	if (*key == 1)
	{
		(*tmp_x) += 10 * cos((*tmp_angle));
		(*tmp_y) += 10 * sin((*tmp_angle));
	}
	if (*key == 0)
	{
		(*tmp_x) -= 10 * cos((*tmp_angle) - M_PI_2);
		(*tmp_y) -= 10 * sin((*tmp_angle) - M_PI_2);
	}
	if (*key == 2)
	{
		(*tmp_x) -= 10 * cos((*tmp_angle) + M_PI_2);
		(*tmp_y) -= 10 * sin((*tmp_angle) + M_PI_2);
	}
}

int	vurtual_move(int key, t_mlx *mlxx)
{
	float	tmp_x;
	float	tmp_y;
	double	tmp_angle;

	tmp_x = mlxx->player_x;
	tmp_y = mlxx->player_y;
	tmp_angle = mlxx->angle;
	moves(&tmp_x, &tmp_y, &tmp_angle, &key);
	if (mlxx->map[(int)tmp_y / 40][(int)tmp_x / 40] == '1')
		return (0);
	if (mlxx->map[(int)mlxx->player_y / 40][(int)tmp_x / 40] == '1'
		|| mlxx->map[(int)tmp_y / 40][(int)mlxx->player_x / 40] == '1')
		return (0);
	if (check_if_wall(mlxx->map, (tmp_y - 1) / 40, (tmp_x - 1) / 40) == 1
		|| check_if_wall(mlxx->map, (tmp_y + 1) / 40, (tmp_x + 1) / 40) == 1)
		return (0);
	if (check_if_wall(mlxx->map, (tmp_y - 1) / 40, (tmp_x) / 40) == 1
		|| check_if_wall(mlxx->map, (tmp_y + 1) / 40, (tmp_x) / 40) == 1)
		return (0);
	if (check_if_wall(mlxx->map, (tmp_y) / 40, (tmp_x - 1) / 40) == 1
		|| check_if_wall(mlxx->map, (tmp_y) / 40, (tmp_x + 1) / 40) == 1)
		return (0);
	return (1);
}

int	exit_key(t_mlx *mlxx)
{
	mlx_destroy_image(mlxx->mlx, mlxx->img.img);
	mlx_destroy_window(mlxx->mlx, mlxx->mlx_win);
	free_double(mlxx->map);
	exit(0);
	return (0);
}

int	click_key(int key, t_mlx *mlxx)
{
	if (key == 53)
	{
		mlx_destroy_image(mlxx->mlx, mlxx->img.img);
		mlx_destroy_window(mlxx->mlx, mlxx->mlx_win);
		free_double(mlxx->map);
		exit(0);
	}
	if (vurtual_move(key, mlxx) == 1)
	{
		moves(&mlxx->player_x, &mlxx->player_y, &mlxx->angle, &key);
		if (mlxx->angle <= 0)
			mlxx->angle += 2 * M_PI;
		if (mlxx->angle > 2 * M_PI)
			mlxx->angle -= 2 * M_PI;
		mlx_destroy_image(mlxx->mlx, mlxx->img.img);
		mlxx->img.img 
			= mlx_new_image(mlxx->mlx, mlxx-> w_weight, mlxx->w_height);
		mlxx->img.addr 
			= mlx_get_data_addr(mlxx->img.img, &mlxx->img.bits_per_pixel,
				&mlxx->img.line_length, &mlxx->img.endian);
		drow(mlxx);
		mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
	}
	return (0);
}
