/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:56:31 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/09 11:56:45 by abdel-ou         ###   ########.fr       */
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
		my_mlx_pixel_put(&mlxx.img ,mlxx.player_x ,mlxx.player_y ,color);
			// drow_rays(&mlxx, angle, 0x00ff00);
			horizontal_ray(&mlxx);

			
} 
int    drow(void *param)
{
    int	i;
    int	j;
	t_mlx *mlxx;

	mlxx = (t_mlx *)param;
    i = 0;
    j = 0;
	while (mlxx->map[i])
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
	drow_grid(mlxx);
	mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
	return 0;
}
