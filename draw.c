/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:56:31 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/13 10:23:14 by abdel-ou         ###   ########.fr       */
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

t_point	closest_p(t_point h_point, t_point v_point, t_mlx *mlxx, double angle)
{
	t_point	point;

	if (distance(mlxx->player_x, mlxx->player_y, h_point.x, h_point.y)
		< distance(mlxx->player_x, mlxx->player_y, v_point.x, v_point.y))
	{
		point.x = h_point.x;
		point.y = h_point.y;
		mlxx->x_offset = (int)h_point.x % 40 ;
		if (angle > 0 && angle < M_PI)
			mlxx->color_select = 1;
		else
			mlxx->color_select = 2;
	}
	if (distance(mlxx->player_x, mlxx->player_y, h_point.x, h_point.y)
		> distance(mlxx->player_x, mlxx->player_y, v_point.x, v_point.y))
	{
		point.x = v_point.x;
		point.y = v_point.y;
		mlxx->x_offset = (int)v_point.y % 40;
		if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
			mlxx->color_select = 3;
		else
			mlxx->color_select = 4;
	}
	return (point);
}

void	scan(t_mlx *mlxx, double angle, int i)
{
	t_point	h_point;
	t_point	v_point;
	t_point	point;
	int		tmp_wall_h;

	h_point = horizontal_ray(mlxx, angle);
	v_point = vertical_ray(mlxx, angle);
	point = closest_p(h_point, v_point, mlxx, angle);
	tmp_wall_h = find_wall_h(mlxx, angle, point);
	draw_all(i, mlxx, tmp_wall_h);
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
