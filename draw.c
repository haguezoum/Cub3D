/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:56:31 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/05 14:32:37 by abdel-ou         ###   ########.fr       */
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
void	drow_player(int startx ,int starty, int size, t_data img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	startx = startx * size + (size - 4)/2;
	starty = starty * size + (size - 4)/2;
	while (j < 4)
	{
		while (i < 4)
		{
			my_mlx_pixel_put(&img,startx + i, starty + j, color);
			i++;
		}
		i = 0;
		j++;
	}
} 
void    drow(t_mlx *mlxx, char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
      while (map[i + 1])
	{
		while (map[i][j])
		{

			if (map[i][j] == '1')
				drow_square (j,i,40 ,mlxx->img, 0xffffff);
			if (map[i][j] == 'p')
				drow_player (j,i,40 ,mlxx->img, 0xFF0000);
			j++;
		}
		j = 0;
		i++;
	}
}

