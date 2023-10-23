/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:15:13 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/23 21:44:51 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_line(int x0, int y0, int x1, int y1, t_data img, int color, t_mlx *mlxx)
{
     if (y0 > 360)
        y0 = 360;
    if (y1 < 0)
        y1 = 0;
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
         if (x >= 0 && x < mlxx->weight && y >= 0 && y < mlxx->height)
            my_mlx_pixel_put(&img, round(x), round(y), color);
        x += x_increment;
        y += y_increment;
        i++;
    }
}

void draw_line_x(int x0, int y0, int x1, int y1, t_data img, unsigned int *color, int x_offset, t_mlx *mlxx)
{
    
    if (y0 > mlxx->height)
    {
        
        y0 = mlxx->height;
    }
        
    if (y1 < 0)
    {
       
        y1 = 0;
    }
    int tmp_y0 = y0;
     int tmp_y1 = y1;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int steps;
    int i = 0;
    float ii = 0;

    if (dx > dy)
        steps = dx;
    else
        steps = dy;

    double x_increment = (x1 - x0) / (double)steps;
    double y_increment = (y1 - y0) / (double)steps;
    double x = x0;
    double y = y0;
   
    float coff = 40.0 / (tmp_y0 - tmp_y1); // Calculate coff using absolute difference in y

    while (i <= steps)
    {
        int colors = (int)ii * 40 + x_offset;
        
        if (x >= 0 && x < mlxx->weight && y >= 0 && y < mlxx->height && colors < 1600)
            my_mlx_pixel_put(&img, round(x), round(y), color[colors]); // Use i to index the color array
        x += x_increment;
        y += y_increment;
        ii += coff;
        i++;
    }
}



