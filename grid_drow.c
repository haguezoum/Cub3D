/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_drow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:48:19 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/01 16:49:05 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void her(t_mlx *mlxx)
{
    int i = 0;
    int j = 0;
    while (i < mlxx->height)
    {
        while (j < mlxx->weight)
        {
            my_mlx_pixel_put(&mlxx->img, j, i, 0xff12cc);
            j++;
        }
        j = 0;
        i+= 40;
    }
}
void ver(t_mlx *mlxx)
{
 int i = 0;
 int j = 0;
 
 while (i < mlxx->weight)
 {
    while (j < mlxx->height)
    {
        my_mlx_pixel_put(&mlxx->img, i, j, 0xff12cc);
        j++;
    }
    j = 0;
    i+= 40;
 }
}
void drow_grid(t_mlx *mlxx)
{
    her(mlxx);
    ver(mlxx);
}