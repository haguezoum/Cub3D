/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:18:09 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/15 00:20:10 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_height(int fd)
{
	int		height;
	char	*line;

	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			break ;
		}
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

long	create_hexa(char *RGB)
{
	char		*r_;
	char		*g_;
	char		*b_;
	char		**rgb;
	t_rgb_color	color;

	rgb = ft_split(RGB, ',');
	if (check_rgb_count(rgb) == -1 || check_comma(RGB) == -1) 
	{
		printf("ERROR\nRGB error");
		free_double(rgb);
		return (-1);
	}
	r_ = ft_strtrim(rgb[0], "\n");
	g_ = ft_strtrim(rgb[1], "\n");
	b_ = ft_strtrim(rgb[2], "\n");
	color.r = cube_atoi(r_);
	color.g = cube_atoi(g_);
	color.b = cube_atoi(b_);
	free_double(rgb);
	handle_rgb_error(color, r_, g_, b_);
	return (free(r_), free(g_), free(b_), ((color.r & 0xff) << 16)
		+ ((color.g & 0xff) << 8) + (color.b & 0xff));
}

char	**pure_map_helper(int j, char **map, char **pure_map)
{
	int		i;
	char	*line_1;

	i = -1;
	j = 0;
	while (map[++i])
	{
		line_1 = ft_strtrim(map[i], " ");
		if (j > 0)
		{
			if (ft_strncmp("\n", line_1, 1) == 0
				|| ft_strchr("012NEWS", line_1[0]) == 0)
			{
				printf("Error\nMap is not valid !\n");
				return (free(line_1), NULL);
			}
		}
		if (ft_strncmp("1", line_1, 1) == 0 || ft_strncmp("0", line_1, 1) == 0)
		{
			pure_map[j] = ft_strdup(map[i]);
			j++;
		}
		free(line_1);
	}
	return (pure_map[j] = NULL, pure_map);
}

char	**pure_map(char **map)
{
	int		i;
	int		j;
	int		k;
	char	**pure_map;
	char	*line_1;

	i = -1;
	j = 0;
	k = 0;
	while (map[++i])
	{
		line_1 = ft_strtrim(map[i], " ");
		if (ft_strncmp("1", line_1, 1) == 0 || ft_strncmp("0", line_1, 1) == 0)
		{
			j++;
		}
		free(line_1);
	}
	pure_map = malloc(sizeof(char *) * (j + 1));
	pure_map = pure_map_helper(j, map, pure_map);
	return (pure_map);
}
