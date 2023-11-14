/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:18:09 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/14 19:25:36 by haguezou         ###   ########.fr       */
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

long create_hexa(char *RGB)
{
    int rgb_color[3];
    char *r_;
    char *g_;
    char *b_;
    char **rgb;

    ft_bzero(rgb_color, sizeof(rgb_color));
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
    rgb_color[0] = cube_atoi(r_);
    rgb_color[1] = cube_atoi(g_);
    rgb_color[2] = cube_atoi(b_);
    free_double(rgb);

    if (rgb_color[0] == -1 || rgb_color[1] == -1 || rgb_color[2] == -1)
    {
        printf("ERROR \nRGB not right!");
        free(r_);
        free(g_);
        free(b_);
        exit(0);
    }
    free(r_);
    free(g_);
    free(b_);
    return (((rgb_color[0] & 0xff) << 16) + ((rgb_color[1] & 0xff) << 8) + (rgb_color[2] & 0xff));
}

char **pure_map(char **map)
{
    int i;
    int j;
    int k;
    char **pure_map;
    char *line_1;

    i = 0;
    j = 0;
    k = 0;
    while(map[i])
    {
        line_1 = ft_strtrim(map[i], " ");
        if(ft_strncmp("1", line_1, 1) == 0 || ft_strncmp("0", line_1, 1) == 0)
        {
            j++; // count the number of lines in the map (without the params)
        }
        free(line_1);
        i++;
    }
    
    pure_map = malloc(sizeof(char *) * (j + 1));
    i = 0;
    j = 0;

    
    while(map[i])
    {
            line_1 = ft_strtrim(map[i], " ");
        if(j > 0)
        {
            // line_2 = ft_strtrim(map[i], " ")
            if(ft_strncmp("\n", line_1, 1) == 0 || ft_strchr("012NEWS", line_1[0]) == 0)
            {
                printf("Error\nMap is not valid !\n");
                free(line_1);
                return NULL;
            }
        }
        if(ft_strncmp("1", line_1, 1) == 0 || ft_strncmp("0", line_1, 1) == 0)
        {
            pure_map[j] = ft_strdup(map[i]);
            j++;
        }
        i++;
        free(line_1);
    }
    pure_map[j] = NULL;
    return pure_map;
}
