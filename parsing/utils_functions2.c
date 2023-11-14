/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:22:13 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/13 22:36:01 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_double(char **double_char_pointer)
{
	int	i;

	i = 0;
	while (double_char_pointer[i])
	{
		free(double_char_pointer[i]);
		i++;
	}
	free(double_char_pointer);
}

int	table_counter(char **tab)
{
	int	count;

	count = 0;
	if (!tab)
		return (0);
	while (tab[count])
		count++;
	return (count);
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'S' || c == 'N'
		|| c == 'W' || c == 'E' || c == '\n' || c == ' ');
}

int	player_position_count(char **map)
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
			if (map[i][j] == 'N' || map[i][j] == 'S' 
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	if (count > 1 || count == 0)
		return (-1);
	return (0);
}
