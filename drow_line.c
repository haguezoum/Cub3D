/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:15:13 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/11 11:19:14 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
#include <math.h>


void draw_line(int x0, int y0,int x1, int y1, t_data img, int color)
{
    double dx = x1 - x0;
    double dy = y1 - y0;
    double steps;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    double x_increment = dx / steps;
    double y_increment = dy / steps;
    double x = x0;
    double y = y0;

    int i = 0;
    while (i <= steps )
    {
         my_mlx_pixel_put(&img, round(x),round(y), color);
        x += x_increment;
        y += y_increment;
        i++;
    }
}