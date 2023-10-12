/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:25:36 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/11 17:37:40 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;	
	int		endian;
}t_data;

typedef struct s_point
{
	float	x;
	float	y;
}t_point;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	**map;
	float	player_x;
	float	player_y;
	double	angle;
	int		height;
	int		weight;
}t_mlx;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**memory_allocete(char *file_name);
void	draw_line(int p1_x, int p1_y, int p2_x, int p2_y, t_data img, int color);
char	*get_next_line(int fd, int buffers);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		check_new_line(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *s, int start, size_t len);
char	**load_map(char *file_name);
void	drow_square(int startx ,int starty, int size, t_data img, int color);
void	drow_player(t_mlx mlxx, int color);
int    drow(void *param);

void	init_param(t_mlx *mlxx,  char *file_name);
int	click_key(int key, t_mlx *mlxx);

void horizontal_ray(t_mlx *mlxx);
void vertical_ray(t_mlx *mlxx);
void drow_rays(t_mlx *mlxx, double angle, int color);

// just for test or visualisation the grid
void drow_grid(t_mlx *mlxx);

#endif
