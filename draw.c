/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:56:31 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/09 08:50:53 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void drow_rays(t_mlx *mlxx, double angle, int color)
{
	int x;
	int y;
	int z;
	int xx;
	int yy;


	x = mlxx->player_x;
	y = mlxx->player_y;
	z = 1;
	xx = x - (z * cos(angle));
	yy = y - (z * sin(angle));
	while (mlxx->map[yy / 40][(int)xx / 40] != '1')
	{
		xx = x - (z * cos(angle));
		yy = y - (z * sin(angle));
		my_mlx_pixel_put(&mlxx->img,xx  , yy, color);
		z++;
	}
}
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
	double angle = mlxx.angle;
	
		my_mlx_pixel_put(&mlxx.img ,mlxx.player_x ,mlxx.player_y ,color);

			drow_rays(&mlxx, angle - 0.4, 0x00ff00);
			drow_rays(&mlxx, angle - 0.35, 0x00ff00);
			drow_rays(&mlxx, angle - 0.3, 0x00ff00);
			drow_rays(&mlxx, angle - 0.25, 0x00ff00);
			drow_rays(&mlxx, angle - 0.2, 0x00ff00);
			drow_rays(&mlxx, angle - 0.15, 0x00ff00);
			drow_rays(&mlxx, angle - 0.1, 0x00ff00);
			drow_rays(&mlxx, angle, 0x00ff00);
			drow_rays(&mlxx, angle + 0.4, 0x00ff00);
			drow_rays(&mlxx, angle + 0.35, 0x00ff00);
			drow_rays(&mlxx, angle + 0.3, 0x00ff00);
			drow_rays(&mlxx, angle + 0.25, 0x00ff00);
			drow_rays(&mlxx, angle + 0.2, 0x00ff00);
			drow_rays(&mlxx, angle + 0.15, 0x00ff00);
			drow_rays(&mlxx, angle + 0.1, 0x00ff00);
			
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
