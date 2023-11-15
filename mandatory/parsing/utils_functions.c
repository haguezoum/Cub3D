/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:37:20 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/15 16:45:56 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	cube_atoi(char *str)
{
	long	res;
	size_t	i;

	res = 0;
	i = 0;
	if (ft_strlen(str) == 0)
		return (-1);
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		if (res > 255 || res < 0)
			return (-1);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (res);
}

int	check_map_name(char *map_name)
{
	int		i;
	int		j;
	char	*map;
	char	*s;

	i = 0;
	j = 0;
	map = ft_strdup(map_name);
	while (map[i] != '.' && map[i] != '\0')
	{
		i++;
	}
	s = ft_strdup(&map[i]);
	free(map);
	if (ft_strncmp(s, ".cub", 5) == 0)
	{
		free(s);
		return (1);
	}
	free(s);
	return (0);
}

int	check_path(t_mlx *mlxx)
{
	if (!mlxx->ea_path || !mlxx->so_path || !mlxx->we_path || !mlxx->no_path)
	{
		return (-1);
	}
	if (extention(mlxx->ea_path) == -1 || extention(mlxx->so_path) == -1 
		|| extention(mlxx->we_path) == -1 || extention(mlxx->no_path) == -1)
	{
		return (-1);
	}
	if (open(mlxx->ea_path, O_RDONLY) == -1 
		|| open(mlxx->so_path, O_RDONLY) == -1
		|| open(mlxx->we_path, O_RDONLY) == -1 
		|| open(mlxx->no_path, O_RDONLY) == -1)
	{
		return (-1);
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' 
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	extention(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (line[i - 1] == 'm' && line[i - 2] == 'p' && line[i - 3] == 'x'
		&& line[i - 4] == '.')
		return (0);
	return (-1);
}
