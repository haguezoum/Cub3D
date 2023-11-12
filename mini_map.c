/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:22:45 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/12 13:22:47 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drow_rays(t_mlx *mlxx, double angle, int color)
{
  int x = mlxx->player_x / 4;
    int y = mlxx->player_y / 4;

    
    int length = 4;

    double z = 0;
    while (z < 2 * M_PI) {
        int xx = x + (length * cos(angle + z));
        int yy = y + (length * sin(angle + z));
		
        my_mlx_pixel_put(&mlxx->img, xx, yy, color);	
        z += 0.1;
    }
}


void	drow_square(int startx, int starty, t_data img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	startx = startx * 10 ;
	starty = starty * 10;
	while (j < 10)
	{
		while (i < 10)
		{
			my_mlx_pixel_put(&img, startx + i, starty + j, color);
			i++;
		}
		i = 0;
		j++;
	}
}

void	drow_mini_map(t_mlx	*mlxx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlxx->map[i])
	{
		while (mlxx->map[i][j])
		{
			if (mlxx->map[i][j] == '1')
				drow_square(j, i, mlxx->img, 0xffffff);
			j++;
		}
		j = 0;
		i++;
	}
	// my_mlx_pixel_put(&mlxx->img, mlxx->player_x / 4,
	// 	mlxx->player_y / 4, 0x00ff00);
	my_mlx_pixel_put(&mlxx->img, 100,100, 0x00ff00);	
	drow_rays(mlxx, mlxx->angle, 0x00ff00);
}




