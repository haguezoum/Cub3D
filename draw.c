/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:56:31 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/06 12:57:50 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drow_square(int startx ,int starty, int size, t_data img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	startx = startx * size;
	starty = starty * size;
	while (j < size)
	{
		while (i < size)
		{
			my_mlx_pixel_put(&img,startx + i, starty + j, color);
			i++;
		}
		i = 0;
		j++;
	}
	
}

void	drow_player(t_mlx mlxx, int color)
{
	int	i = 0;
	int j = 0;
	int x = mlxx.player_x - 5;
	int y = mlxx.player_y - 5;
		while (j < 10)
		{
			while (i < 10)
			{
				my_mlx_pixel_put(&mlxx.img,x + i , y + j, color);
				i++;
			}
			i = 0;
			j++;
		}
} 
void    drow(t_mlx *mlxx)
{
    int i;
    int j;


    i = 0;
    j = 0;
	while (mlxx->map[i + 1])
	{
		while (mlxx->map[i][j])
		{
			if (mlxx->map[i][j] == '1')
				drow_square (j,i,40 ,mlxx->img, 0xffffff);
			if (mlxx->map[i][j] == 'p')
				drow_player (*mlxx, 0xff0000);
			j++;
		}
		j = 0;
		i++;
	}
	// singl_play(mlxx->player_x ,mlxx->player_y, 40, mlxx->img, 0xff0000);
	
	mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
}
