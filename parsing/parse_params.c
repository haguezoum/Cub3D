/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:38:30 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/12 17:12:29 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *param(char *path, int *count)
{
    int i = 0;
    while(path[i] != ' ' && path[i] != '\0')
    {
        i++;
    }
    return ((*count)++, ft_substr(path, i + 1, ft_strlen(path) - i));
}

int check_rgb_count(char **rgb)
{
    int i;
    
    i  = 0;
    while (rgb[i])
    {
        i++;
    }
    if(i != 3)
        return (-1);
    return (0);
}

int check_comma(char *str)
{
		int count;
		int i;

		i = 0;
		count = 0;

		while(str[i])
		{
			if(str[i] == ',')
				count++;
			i++;
		}
	if(count != 2)
		return -1;
	return 0;
}

void process_texture_line(char *line, t_mlx *mlxx, int *count)
{
    if (ft_strncmp("NO ", line, 3) == 0)
        mlxx->NO_path = ft_strtrim(param(line, count), " \n");
    else if (ft_strncmp("SO ", line, 3) == 0)
        mlxx->SO_path = ft_strtrim(param(line, count), " \n");
    else if (ft_strncmp("WE ", line, 3) == 0)
        mlxx->WE_path = ft_strtrim(param(line, count), " \n");
    else if (ft_strncmp("EA ", line, 3) == 0)
        mlxx->EA_path = ft_strtrim(param(line, count), " \n");
    else if (ft_strncmp("C ", line, 2) == 0)
    {
        mlxx->C_color = create_hexa(param(line, count));
    }
    else if (ft_strncmp("F ", line, 2) == 0)
    {
        mlxx->F_color = create_hexa(param(line, count));
    }
    else if (ft_isalpha(line[0]))
    {
        printf("Error\n");
        exit(0);
    }

}

int store_params(char **map, t_mlx *mlxx)
{
    int i = 0;
    int count = 0;
    int c_count = 0;
    int f_count = 0;
    char *line;

    while (map[i] && count < 7)
    {
        line = ft_strtrim(map[i], " ");
        process_texture_line(line, mlxx, &count);
        free(line);
        i++;
    }

    if (mlxx->C_color != -1)
        c_count++;
    if (mlxx->F_color != -1)
        f_count++;

    if (c_count != 1 || f_count != 1)
    {
        return (-1);
    }

    return count;
}
