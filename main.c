/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:12:00 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/24 15:42:58 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_int(t_mlx *mlxx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
		while (i < 9)
	{
		while (j < 18)
		{
			if (mlxx->map[i][j] && mlxx->map[i][j] == 'p')
			{
				mlxx->player_y = i * 40 + 20;
				mlxx->player_x = j * 40 + 20;
			}	
			j++;
		}
		j = 0;
		i++;
	}
}

void init_param(t_mlx *mlxx,  char *file_name)
{
	int fd = open(file_name, O_RDONLY, 0);
	mlxx->height = 1;
	mlxx->weight = 0;
	mlxx->angle = 90 * (M_PI / 180);

	mlxx->weight = ft_strlen(get_next_line(fd, 1)) - 1;
	while (get_next_line(fd, 1))
		mlxx->height++;
	mlxx->weight = mlxx->weight * 40;
	mlxx->height = mlxx->height * 40;
	mlxx->map = load_map(file_name);
	player_int(mlxx);

	mlxx->mlx = mlx_init();
	mlxx->mlx_win = mlx_new_window(mlxx->mlx, mlxx->weight, mlxx->height, "cube3d");
	mlxx->img.img = mlx_new_image(mlxx->mlx,mlxx-> weight, mlxx->height);
	mlxx->img.addr = mlx_get_data_addr(mlxx->img.img, &mlxx->img.bits_per_pixel, &mlxx->img.line_length,
			&mlxx->img.endian);
	mlxx->color1 = load_color(mlxx, "./texture/wall_40_1.xpm");
}


int	main(int argc, char **argv)
{
	t_mlx	mlxx;

	if (argc > 1)
		init_param(&mlxx, argv[1]);
	mlx_loop_hook(mlxx.mlx, &drow, &mlxx);
	mlx_hook(mlxx.mlx_win,2,0, click_key, &mlxx);
	mlx_loop(mlxx.mlx);
	return (0);
}
