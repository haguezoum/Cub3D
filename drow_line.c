/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:15:13 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/12 18:48:04 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_line(int x0, int y0, int y1, int color, t_mlx *mlxx)
{
    int steps = abs(y1 - y0);
    double y_increment = (y1 - y0) / (double)steps;
    int i = 0;
    while (i <= steps)
    {
         if (x0 >= 0 && x0 < mlxx->w_weight && y0 >= 0 && y0 < mlxx->w_height)
            my_mlx_pixel_put(&mlxx->img, round(x0), round(y0), color);
        y0 += y_increment;
        i++;
    }
}

void draw_line_x(int x0, int y0, int y1, unsigned int *color,t_mlx *mlxx, int tmp_wall_h)
{

    int i = 0;
    int steps = abs(y1 - y0);
    double y_increment = (y1 - y0) / (double)steps;
    double conter = mlxx->w_height / 2;
    float coff = 40.0 / (tmp_wall_h);
    float ii = coff * (tmp_wall_h / 2);
    while (i <= (steps / 2))
    {
        int colors = (int)ii * 40 + mlxx->x_offset;
        
        
        if (x0 >= 0 && x0 < mlxx->w_weight && conter >= 0 && conter < mlxx->w_height && colors < 1600)
            my_mlx_pixel_put(&mlxx->img, round(x0), round(conter), color[colors]); 
        conter += y_increment;
        ii -= coff;
        i++;
    }
        i = 0;
         conter = mlxx->w_height / 2;
        ii = coff * (tmp_wall_h / 2);
    
      while (i <= (steps / 2))
    {
        int colors = (int)ii * 40 + mlxx->x_offset;
        
        
        if (x0 >= 0 && x0 < mlxx->w_weight && conter >= 0 && conter < mlxx->w_height && colors < 1600)
            my_mlx_pixel_put(&mlxx->img, round(x0), round(conter), color[colors]);
        conter -= y_increment;
        ii += coff;
        i++;
    }
}