/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:56:36 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/12 15:45:27 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_if_wall(char **map, int y, int x)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (y < 0 || y >= i || x < 0 || x >= (int)ft_strlen(map[y]))
		return (1);
	if (map[y][x] == '1')
		return (1);
	return (0);
}

void	h_norm_help_1(t_mlx *mlxx, double *x_intercept,
	double *y_intercept, double angle)
{
	if (angle >= 0 && angle < M_PI)
	{
		(*y_intercept) = (int)(mlxx->player_y / 40) * 40;
		(*x_intercept) = mlxx->player_x
			+ ((*y_intercept) - mlxx->player_y) / tan(angle);
	}
	else
	{
		(*y_intercept) = (int)((mlxx->player_y / 40) + 1) *40;
		(*x_intercept) = mlxx->player_x
			+ ((*y_intercept) - mlxx->player_y) / tan(angle);
	}
}

void	h_norm_help_2(double *x_step, double *x_intercept,
	double *y_intercept, double angle)
{
	if (angle >= 0 && angle < M_PI)
	{
		(*x_intercept) += (*x_step);
		(*y_intercept) -= 40;
	}
	else
	{
		(*x_intercept) -= (*x_step);
		(*y_intercept) += 40;
	}
}

t_point	horizontal_ray(t_mlx *mlxx, double angle)
{
	double	y_intercept;
	double	x_intercept;
	double	x_step;
	t_point	h_point;

	x_step = 40 / tan(M_PI - angle);
	h_norm_help_1(mlxx, &x_intercept, &y_intercept, angle);
	while (check_if_wall(mlxx->map, (int)((y_intercept) / 40),
		(int)((x_intercept) / 40)) == 0)
	{
		if (mlxx->map[(int)(y_intercept / 40)]
			[(int)((x_intercept) / 40)] == '1')
			break ;
		if (check_if_wall(mlxx->map, (int)((y_intercept) / 40) - 1,
			(int)((x_intercept) / 40)) == 1)
			break ;
		h_norm_help_2(&x_step, &x_intercept, &y_intercept, angle);
	}
	h_point.x = x_intercept;
	h_point.y = y_intercept;
	return (h_point);
}
