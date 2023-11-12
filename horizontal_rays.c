/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:56:36 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/12 12:24:20 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <string.h>

#include <string.h>

int check_if_wall(char **map, int y, int x)
{
    int i = 0;
    
    // First, find the number of rows in the map
    while (map[i])
    {
        i++;
    }
    
    // Check if the coordinates are out of bounds
    if (y < 0 || y >= i || x < 0 || x >= (int)ft_strlen(map[y]))
    {
        return 1;
    }
    
    // Check if the cell at (y, x) is a wall ('1')
    if (map[y][x] == '1')
    {
        return 1;
    }
    
    return 0;
}


t_point	horizontal_ray(t_mlx *mlxx, double angle)
{
	double	y_intercept;
	double	x_intercept;
	double	x_step;
	t_point	h_point;

	x_step = 40 / tan(M_PI - angle);
	if (angle >= 0 && angle < M_PI)
	{
		y_intercept = (int)(mlxx->player_y / 40) * 40;
		x_intercept = mlxx->player_x
			+ (y_intercept - mlxx->player_y) / tan(angle);
	}
	else
	{
		y_intercept = (int)((mlxx->player_y / 40) + 1) * 40;
		x_intercept = mlxx->player_x
			+ (y_intercept - mlxx->player_y) / tan(angle);
	}
	while (check_if_wall(mlxx->map, (int)((y_intercept) / 40), (int)((x_intercept) / 40)) == 0)
	{
	
		
		if (mlxx->map[(int)(y_intercept / 40)][(int)((x_intercept) / 40)] == '1')
		{
			break;
		}
		if (check_if_wall(mlxx->map, (int)((y_intercept) / 40) - 1, (int)((x_intercept) / 40)) == 1)
		{
			break;
		}
		
		
		if (angle >= 0 && angle < M_PI)
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
	// if (x_intercept <= 0 || x_intercept >= mlxx->w_weight || y_intercept <= 0
	// 	|| y_intercept >= mlxx->w_height)
	// {
	// 	h_point.x = 1000000;
	// 	h_point.y = 1000000;
	// 	return (h_point);
	// }
	h_point.x = x_intercept;
	h_point.y = y_intercept;
	return (h_point);
}
