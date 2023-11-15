/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:22:41 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/15 10:32:37 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_all(int i, t_mlx *mlxx, int tmp_wall_h)
{
	draw_line(i, 0, mlxx->c_color, mlxx);
	draw_line(i, 1, mlxx->f_color, mlxx);
	if (mlxx->color_select == 1)
		draw_line_x(i, mlxx->color1, mlxx, tmp_wall_h);
	if (mlxx->color_select == 2)
		draw_line_x(i, mlxx->color2, mlxx, tmp_wall_h);
	if (mlxx->color_select == 3)
		draw_line_x(i, mlxx->color3, mlxx, tmp_wall_h);
	if (mlxx->color_select == 4)
		draw_line_x(i, mlxx->color4, mlxx, tmp_wall_h);
}

int	find_wall_h(t_mlx *mlxx, double angle, t_point point)
{
	int		tmp_wall_h;
	int		distaproj;
	double	dist;

	distaproj = (mlxx->w_weight / 2) / tan(M_PI / 6);
	dist = distance(mlxx->player_x, mlxx->player_y, point.x, point.y);
	if (mlxx->angle > angle)
		dist = dist * cos(mlxx->angle - angle);
	else
		dist = dist * cos(angle - mlxx->angle);
	mlxx->wall_h = (40 / dist) * distaproj;
	tmp_wall_h = mlxx->wall_h;
	if (mlxx->wall_h > mlxx->w_height)
		mlxx->wall_h = mlxx->w_height;
	return (tmp_wall_h);
}
