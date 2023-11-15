/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:12:00 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/15 10:52:00 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_int(t_mlx *mlxx)
{
	int	i;
	int	j;

	i = -1;
	while (mlxx->map[++i])
	{
		j = -1;
		while (mlxx->map[i][++j])
		{
			if (mlxx->map[i][j] == 'N' || mlxx->map[i][j] == 'S' ||
				mlxx->map[i][j] == 'E' || mlxx->map[i][j] == 'W')
			{
				mlxx->player_y = i * 40 + 20;
				mlxx->player_x = j * 40 + 20;
			}
			if (mlxx->map[i][j] == 'N')
				mlxx->angle = 90 * (M_PI / 180);
			if (mlxx->map[i][j] == 'S')
				mlxx->angle = 270 * (M_PI / 180);
			if (mlxx->map[i][j] == 'E')
				mlxx->angle = 0 * (M_PI / 180);
			if (mlxx->map[i][j] == 'W')
				mlxx->angle = 180 * (M_PI / 180);
		}
	}
}

void	init_param(t_mlx *mlxx)
{
	mlxx->w_weight = 1280;
	mlxx->w_height = 720;
	player_int(mlxx);
	mlxx->mlx = mlx_init();
	mlxx->mlx_win = mlx_new_window(mlxx->mlx, mlxx->w_weight,
			mlxx->w_height, "cub");
	mlxx->img.img = mlx_new_image(mlxx->mlx, mlxx->w_weight, mlxx->w_height);
	mlxx->img.addr = mlx_get_data_addr(mlxx->img.img, &mlxx->img.bits_per_pixel,
			&mlxx->img.line_length, &mlxx->img.endian);
	mlxx->color1 = load_color(mlxx, mlxx->no_path);
	mlxx->color2 = load_color(mlxx, mlxx->ea_path);
	mlxx->color3 = load_color(mlxx, mlxx->we_path);
	mlxx->color4 = load_color(mlxx, mlxx->so_path);
	free(mlxx->no_path);
	free(mlxx->ea_path);
	free(mlxx->we_path);
	free(mlxx->so_path);
}

void main_helper(t_mlx *mlxx, char *map_name)
{
	mlxx->map = cube3d_full_map(map_name, mlxx);
	if (mlxx->map == NULL )
		exit(1);
	init_param (mlxx);
	if (!mlxx->color1 || !mlxx->color2 || !mlxx->color3 || !mlxx->color4)
	{
		printf("Error mlx imag\n");
		free_double(mlxx->map);
		exit(1);
	}
}
int	main(int argc, char **argv)
{
	t_mlx	mlxx;

	if (argc == 2)
	{
		if(check_map_name(argv[1]) == 0)
		{
			printf("Error\n map name !\n");
			exit(1);
		}
		main_helper(&mlxx, argv[1]);
		// mlxx.map = cube3d_full_map(argv[1], &mlxx);
		// // -----------------------
		// if (mlxx.map == NULL )
		// 	exit(1);
		// init_param (&mlxx);
		// if (!mlxx.color1 || !mlxx.color2 || !mlxx.color3 || !mlxx.color4)
		// {
		// 	printf("Error mlx imag\n");
		// 	free_double(mlxx.map);
		// 	exit(1);
		// }
	// -----------------------
		system("leaks cub3d");
		mlx_loop_hook(mlxx.mlx, &drow, &mlxx);
		mlx_hook(mlxx.mlx_win, 2, 0, click_key, &mlxx);
		mlx_hook(mlxx.mlx_win, 17, 0, exit_key, &mlxx);
		mlx_loop(mlxx.mlx);
	}
	else
	{
		printf("Error\n tow arguments !\n");
		exit(1);
	}
	
	return (0);
}
