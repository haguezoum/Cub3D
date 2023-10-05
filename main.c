/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:12:00 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/05 14:51:28 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	click_key(int key, t_mlx *mlxx)
{
	if (key == 53)
	{
        mlx_destroy_window(mlxx->mlx, mlxx->mlx_win);
        mlx_destroy_image(mlxx->mlx, mlxx->img.img);
		exit(0);
	}
	if (key == 126)
	{
		/* code */
	}
	
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlxx;
	char **map;
	(void)argc;

	map = load_map(argv[1]);
	mlxx.mlx = mlx_init();
	mlxx.mlx_win = mlx_new_window(mlxx.mlx, 760, 400, "abdel-ou");
	mlxx.img.img = mlx_new_image(mlxx.mlx, 1280, 720);
	mlxx.img.addr = mlx_get_data_addr(mlxx.img.img, &mlxx.img.bits_per_pixel, &mlxx.img.line_length,
			&mlxx.img.endian);

	 drow(&mlxx, map);
	mlx_put_image_to_window(mlxx.mlx, mlxx.mlx_win, mlxx.img.img, 0, 0);
	mlx_key_hook(mlxx.mlx_win, click_key, &mlxx);
	mlx_loop(mlxx.mlx);
	return (0);
}
