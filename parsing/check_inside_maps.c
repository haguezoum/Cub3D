/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:26:17 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/14 14:46:22 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_inside_err(char **map, char sus)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == sus)
			{
				if (map[i][j + 1] == 10 || map[i][j - 1] == 10 
					|| map[i + 1][j] == 10 || map[i - 1][j] == 10)
				{
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	open_zero(char **map)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	size = table_counter(map);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0') 
			{
				if (!is_valid_char_inzero(map, i, j, size))
					return (-1);
			}
		}
	}
	return (0);
}

int	main_units(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i]) 
	{
		j = 0;
		while (ft_isspace(map[i][j]))
		{
			j++;
		}
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j])) 
				return (-1);
			j++;
		}
		while (j > 0 && ft_isspace(map[i][j - 1])) 
		{
			j--;
		}
		i++;
	}
	return (0);
}

int	space_sus(char **map)
{
	int	y;

	if (check_inside_err(map, 'N') == -1 || check_inside_err(map, 'S') == -1 
		|| check_inside_err(map, 'E') == -1 || check_inside_err(map, 'W') == -1)
	{
		return (-1);
	}
	y = open_zero(map);
	if (y != 0)
	{
		return (-1);
	}
	return (0);
}

int	inside_map(char **map)
{
	char	*err_msg1;
	char	*err_msg2;

	err_msg1 = "Error in map\nMap accept only 1,0,(N | S | E | W) !\n";
	err_msg2 = "Error in map\nSpace (between || around) 0 or (N | S | E | W) !\n";
	if (main_units(map) == -1)
	{
		write(2, err_msg1, ft_strlen(err_msg1));
		free_double(map);
		return (-1);
	}
	if (space_sus(map) == -1)
	{
		write(2, err_msg2, ft_strlen(err_msg2));
		free_double(map);
		return (-1);
	}
	if (player_position_count(map) == -1)
	{
		write(2, "Error\nMap accept only 1 player pos no more no less !\n", 53);
		free_double(map);
		return (-1);
	}
	return (0);
}
