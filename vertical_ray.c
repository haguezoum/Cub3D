/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:28:34 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/12 12:47:04 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void vertical_ray(t_mlx *mlxx)
{
    int	x_intercept;
    int	y_intercept;
    int	y_step; 

    y_step = tan(mlxx->angle) * 40;
	if (mlxx->angle >= M_PI_2 && mlxx->angle < 3 * M_PI_2)
	{
		x_intercept = (int)((mlxx->player_x / 40) + 1) * 40;
		y_intercept = mlxx->player_y + (x_intercept - mlxx->player_x) * tan(mlxx->angle);
	}
	else
	{
		x_intercept = (int)((mlxx->player_x / 40)) * 40;
		y_intercept = mlxx->player_y + (x_intercept - mlxx->player_x) * tan(mlxx->angle);
	}
  
    if (mlxx->angle >= M_PI_2 && mlxx->angle < 3 * M_PI_2)
    {
        x_intercept += 40;
        y_intercept += y_step;
    }else
    {
       x_intercept -= 40;
        y_intercept -= y_step; 
    }
    
    if (x_intercept < 0 || x_intercept > mlxx->weight || y_intercept < 0 || y_intercept > mlxx->height)
        return ;
    
    draw_line(mlxx->player_x, mlxx->player_y, x_intercept, y_intercept, mlxx->img, 0x00ff00);
     printf("x_intercept = %d || y_intercept = %d || angle = %f \n", x_intercept, y_intercept, mlxx->angle * (180 / M_PI));
}   