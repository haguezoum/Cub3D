/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:25:36 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/14 13:23:38 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
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
	float			x;
	float			y;
	float			x_offset;
	float			y_offset;
	char			type;
	int				color;
	unsigned int	*color_array;
}t_point;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	char			**map;
	float			player_x;
	float			player_y;
	float			wall_x;
	float			wall_y;
	int				wall_h;
	double			angle;
	float			x_offset;
	int				w_height;
	int				w_weight;
	int				color_select;
	unsigned int	*color1;
	unsigned int	*color2;
	unsigned int	*color3;
	unsigned int	*color4;
	char			*WE_path;
	char			*EA_path;
	char			*NO_path;
	char			*SO_path;
	long			F_color;
	long			C_color;
}t_mlx;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**memory_allocete(char *file_name);
void	draw_line(int p1_x, int x, int color, t_mlx *mlxx);
// char	*get_next_line(int fd, int buffers);
// int		ft_strlen(char *str);
// char	*ft_strdup(char *str);
int		check_new_line(char *str);
char	**load_map(char *file_name);
void	drow_square(t_mlx *mlxx, int startx, int starty, t_data img, int color);
void	drow_player(t_mlx mlxx);
int		drow(void *param);

void	init_param(t_mlx *mlxx, char *file_name);
int		click_key(int key, t_mlx *mlxx);

t_point	horizontal_ray(t_mlx *mlxx, double angle);
t_point	vertical_ray(t_mlx *mlxx, double angle);
void	drow_rays(t_mlx *mlxx, double angle, int color);
void	scan(t_mlx *mlxx, double angle, int i);

unsigned int *load_color(t_mlx *mlx, char *path);
void draw_line_x(int x0,unsigned int *color, t_mlx *mlxx, int tmp_wall_h);
void	drow_mini_map(t_mlx	*mlxx);
int check_if_wall(char **map, int x, int y);
void	draw_all(int i, t_mlx *mlxx, int tmp_wall_h);
int	find_wall_h(t_mlx *mlxx, double angle, t_point point);
double	distance(int x1, int y1, int x2, int y2);
int exit_key(t_mlx *mlxx);
// just for test or visualisation the grid
// void	drow_grid(t_mlx *mlxx);

//Parsing functions

char **cube3d_full_map(char* arg, t_mlx *mlxx);
int inside_map(char **map);
int check_map_name(char *map_name);

// check inside maps file 
int ft_isspace(char c);
char *param(char *path, int *count);
int check_rgb_count(char **rgb);
int check_comma(char *str);
int store_params(char **map, t_mlx *mlxx);

// new parse params file
int get_map_height(int fd);
long create_hexa(char *RGB);
char **pure_map(char **map);

//  utils functions 
int	cube_atoi(char *str);
int check_map_name(char *map_name);
int check_path(t_mlx *mlxx);
int extention(char *line);

//  utils functions 2
void free_double(char **double_char_pointer);
int table_counter(char **tab);
int is_valid_char(char c);
int player_position_count(char **map);

//  utils functions 3

void norm_dir_path(char *line, int *count, char **direction);
void norm_color(char *line, int *count, long *color);



#endif