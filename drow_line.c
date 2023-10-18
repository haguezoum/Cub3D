/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:15:13 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/18 12:19:33 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_line(int x0, int y0, int x1, int y1, t_data img, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int steps;

    if (dx > dy)
        steps = dx;
    else
        steps = dy;

    double x_increment = (x1 - x0) / (double)steps;
    double y_increment = (y1 - y0) / (double)steps;
    double x = x0;
    double y = y0;

    int i = 0;
    while (i <= steps)
    {
        my_mlx_pixel_put(&img, round(x), round(y), color);
        x += x_increment;
        y += y_increment;
        i++;
    }
}

void draw_line_x(int x0, int y0, int x1, int y1, t_data img, unsigned int *color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int steps;
    int i = 0;

    if (dx > dy)
        steps = dx;
    else
        steps = dy;

    double x_increment = (x1 - x0) / (double)steps;
    double y_increment = (y1 - y0) / (double)steps;
    double x = x0;
    double y = y0;

  
    int ii  = 200;
    while (i <= steps)
    {
        my_mlx_pixel_put(&img, round(x), round(y), color[x1 + ii * 200 ]);
        x += x_increment;
        y += y_increment;
        i++;
        ii--;
        if (ii == 0)
            ii = 200;
        
        
    }
}


