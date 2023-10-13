/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:07:06 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/13 16:39:27 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void scan(t_mlx *mlxx, double angle, int color)
{
    t_point h_point = horizontal_ray(mlxx, angle);
    t_point v_point = vertical_ray(mlxx, angle);
    t_point point;
    

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
    draw_line(mlxx->player_x, mlxx->player_y, point.x, point.y, mlxx->img, color);
}

