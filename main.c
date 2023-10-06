/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:12:00 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/06 13:51:21 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clear_pixel(int x, int y, t_data img)
{
    int color = 0x0ff000;  // Background color (black in this example)
    int pixel_offset = (x * (img.bits_per_pixel / 8)) + (y * img.line_length);
    *(unsigned int *)(img.addr + pixel_offset) = color;
}

int	click_key(int key, t_mlx *mlxx)
{
	if (key == 53)
	{
        mlx_destroy_image(mlxx->mlx, mlxx->img.img);
        mlx_destroy_window(mlxx->mlx, mlxx->mlx_win);
		exit(0);
	}
	if (key == 125)
		mlxx->player_y++;
	if (key == 126)
		mlxx->player_y--;
	if (key == 124)
		mlxx->player_x++;
	if (key == 123)
		mlxx->player_x--;	
	printf("%d \n",key);
			mlxx->img.img = mlx_new_image(mlxx->mlx, mlxx-> weight, mlxx->height);
			mlxx->img.addr = mlx_get_data_addr(mlxx->img.img, &mlxx->img.bits_per_pixel, &mlxx->img.line_length,
				&mlxx->img.endian);
			drow(mlxx);
		mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
	return (0);
}
void player_int(t_mlx *mlxx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
		while (mlxx->map[i + 1])
	{
		while (mlxx->map[i][j])
		{
			if (mlxx->map[i][j] == 'p')
			{
				mlxx->player_y = i * 40 + 18;
				mlxx->player_x = j * 40 + 18;
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

	mlxx->weight = ft_strlen(get_next_line(fd, 1)) - 1;
	while (get_next_line(fd, 1))
		mlxx->height++;
	mlxx->weight = mlxx->weight * 40;
	mlxx->height = mlxx->height * 40;
	mlxx->map = load_map(file_name);
	player_int(mlxx);

	mlxx->mlx = mlx_init();
	mlxx->mlx_win = mlx_new_window(mlxx->mlx, mlxx->weight, mlxx->height, "abdel-ou");
	mlxx->img.img = mlx_new_image(mlxx->mlx,mlxx-> weight, mlxx->height);
	mlxx->img.addr = mlx_get_data_addr(mlxx->img.img, &mlxx->img.bits_per_pixel, &mlxx->img.line_length,
			&mlxx->img.endian);
}


int	main(int argc, char **argv)
{
	t_mlx	mlxx;

	if (argc > 1)
		init_param(&mlxx, argv[1]);

	drow(&mlxx);
	mlx_put_image_to_window(mlxx.mlx, mlxx.mlx_win, mlxx.img.img, 0, 0);
	mlx_hook(mlxx.mlx_win,2,0, click_key, &mlxx);
	mlx_loop(mlxx.mlx);
	return (0);
}
