/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:22:45 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/17 15:25:23 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drow_rays(t_mlx *mlxx, double angle, int color)
{
	int	x;
	int	y;
	int	z ;
	int	xx;
	int	yy;

	z = 1;
	x = mlxx->player_x / 4;
	y = mlxx->player_y / 4;
	while (z < 50)
	{
		xx = x - (z * cos(angle));
		yy = y - (z * sin(angle));
		if (mlxx->map[(int)(yy / 10)][(int)(xx / 10)] == '1')
		{
			break ;
		}
		my_mlx_pixel_put(&mlxx->img, xx, yy, color);
		z++;
	}
}

void	drow_square(int startx, int starty, t_data img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	startx = startx * 10;
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
	my_mlx_pixel_put(&mlxx->img, mlxx->player_x / 4,
		mlxx->player_y / 4, 0x00ff00);
	drow_rays(mlxx, mlxx->angle, 0x00ff00);
	// for git color from the image
	// int weight = 100;
	// int height = 100;
	// int bits_per_pixel;
	// int size_line;
	// int endian;
	// void *new = mlx_xpm_file_to_image(mlxx->mlx, "/Users/abdel-ou/Desktop/wall_40.xpm", &weight, &height);
	// unsigned int *img_data = (unsigned int *)mlx_get_data_addr(new,&bits_per_pixel, &size_line, &endian);
	//     int x, y;
    // for (y = 0; y <= 40; y++) {
    //     for (x = 0; x < 40; x++) {
    //         unsigned int color = img_data[y * 40 + x]; // Get the pixel color
    //         my_mlx_pixel_put(&mlxx->img, x + 100, y + 100, color); // And put it to the window
    //     }
    // }
}
