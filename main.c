/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:12:00 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/05 22:44:49 by abdel-ou         ###   ########.fr       */
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
        mlx_destroy_window(mlxx->mlx, mlxx->mlx_win);
        mlx_destroy_image(mlxx->mlx, mlxx->img.img);
		exit(0);
	}
	   if (key == 126)
    {
        // Draw the red square on the existing image
		drow_player(15, 7, 40, mlxx->img, 0x000000);
		// drow(&mlxx);
		clear_pixel(mlxx->player_y, mlxx->player_x, mlxx->img);
       mlxx->player_x--;
	   mlxx->player_y--;
        mlx_put_image_to_window(mlxx->mlx, mlxx->mlx_win, mlxx->img.img, 0, 0);
    }
	
	return (0);
}
void init_param(t_mlx *mlxx,  char *file_name)
{
	int fd = open(file_name, O_RDONLY, 0);
	int height = 1;
	int	weight = 0;

	weight = ft_strlen(get_next_line(fd, 1)) - 1;
	while (get_next_line(fd, 1))
		height++;
	weight = weight * 40;
	height = height * 40;
	
	mlxx->map = load_map(file_name);
	mlxx->mlx = mlx_init();
	mlxx->mlx_win = mlx_new_window(mlxx->mlx, weight, height, "abdel-ou");
	mlxx->img.img = mlx_new_image(mlxx->mlx, weight, weight);
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
