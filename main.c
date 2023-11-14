/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:12:00 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/14 18:19:21 by haguezou         ###   ########.fr       */
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

void	init_param(t_mlx *mlxx, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	mlxx->w_weight = 1280;
	mlxx->w_height = 720;
	player_int(mlxx);
	mlxx->mlx = mlx_init();
	mlxx->mlx_win = mlx_new_window(mlxx->mlx, mlxx->w_weight,
			mlxx->w_height, "cub");
	mlxx->img.img = mlx_new_image(mlxx->mlx, mlxx->w_weight, mlxx->w_height);
	mlxx->img.addr = mlx_get_data_addr(mlxx->img.img, &mlxx->img.bits_per_pixel,
			&mlxx->img.line_length, &mlxx->img.endian);
	mlxx->color1 = load_color(mlxx, mlxx->NO_path);
	mlxx->color2 = load_color(mlxx, mlxx->EA_path);
	mlxx->color3 = load_color(mlxx, mlxx->WE_path);
	mlxx->color4 = load_color(mlxx, mlxx->SO_path);
	free(mlxx->NO_path);
	free(mlxx->EA_path);
	free(mlxx->WE_path);
	free(mlxx->SO_path);
}
void main_helper(t_mlx *mlxx, char *map_name)
{
	mlxx.map = cube3d_full_map(argv[1], &mlxx);
	if (mlxx.map == NULL )
		exit(1);
	init_param(&mlxx, argv[1]);
	if(!mlxx.color1 || !mlxx.color2 || !mlxx.color3 || !mlxx.color4)
	{
		printf("Error\ncheck images again !\n");
		free_double(mlxx.map);
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
			printf("Error\nfile extention must be .cub !\n");
			exit(0);
		}
		main_helper(&mlxx, argv[1]);
		mlx_loop_hook(mlxx.mlx, &drow, &mlxx);
		mlx_hook(mlxx.mlx_win, 2, 0, click_key, &mlxx);
		mlx_hook(mlxx.mlx_win, 17, 0, exit_key, &mlxx);
		mlx_loop(mlxx.mlx);
		return (0);
	}
	else
	{
		printf("Error\ncheck arguments again !\n");
		exit(0);
	}
	return (0);
}
