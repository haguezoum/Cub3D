/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:28:34 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/15 11:55:58 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point vertical_ray(t_mlx *mlxx, double angle)
{
    double	x_intercept;
    double	y_intercept;
    double	y_step;
    t_point v_point;

    y_step = tan(angle) * 40;
	if (angle >= M_PI_2 && angle < 3 * M_PI_2)
	{
		x_intercept = (int)((mlxx->player_x / 40) + 1) * 40;
		y_intercept = mlxx->player_y + (x_intercept - mlxx->player_x) * tan(angle);
	}
	else
	{
		x_intercept = (int)((mlxx->player_x / 40)) * 40;
		y_intercept = mlxx->player_y + (x_intercept - mlxx->player_x) * tan(angle);
	}
    
    
  
   while (x_intercept >= 0 && x_intercept < mlxx->weight &&
           y_intercept >= 0 && y_intercept < mlxx->height)
  {
     if (mlxx->map[(int)(y_intercept / 40)][(int)(x_intercept / 40)] == '1' || mlxx->map[(int)(y_intercept / 40) ][(int)(x_intercept / 40) - 1] == '1')
        {
            break;
        }
   if (angle >= M_PI_2 && angle < 3 * M_PI_2)
    {
        x_intercept += 40;
        y_intercept += y_step;
    }else
    {
        x_intercept -= 40;
        y_intercept -= y_step; 
    }
    
  }
  if (x_intercept <= 0 || x_intercept >= mlxx->weight || y_intercept <= 0 || y_intercept >= mlxx->height)
  {
      v_point.x = 10000;
      v_point.y = 10000;

      return (v_point);
}
    v_point.x = x_intercept;
    v_point.y = y_intercept;
    // draw_line(mlxx->player_x, mlxx->player_y, v_point.x, v_point.y, mlxx->img, 0xff0000);
    return (v_point);
    //  printf("x_intercept = %d || y_intercept = %d || angle = %f \n", x_intercept, y_intercept, mlxx->angle * (180 / M_PI));
}   