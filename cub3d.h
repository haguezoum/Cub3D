/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:25:36 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/05 22:13:38 by abdel-ou         ###   ########.fr       */
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
	int		player_x;
	int		player_y;
}t_mlx;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**memory_allocete(char *file_name);
void	draw_line(t_point p1, t_point p2, t_data img, int color);
char	*get_next_line(int fd, int buffers);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		check_new_line(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *s, int start, size_t len);
char	**load_map(char *file_name);
void	drow_square(int startx ,int starty, int size, t_data img, int color);
void	drow_player(int startx ,int starty, int size, t_data img, int color);
void    drow(t_mlx *mlxx);
void	init_param(t_mlx *mlxx,  char *file_name);

#endif
