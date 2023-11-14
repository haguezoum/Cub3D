/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:12:26 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/14 14:36:19 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	norm_dir_path(char *line, int *count, char **direction)
{
	char	*param_res;

	param_res = param(line, count);
	*direction = ft_strtrim(param_res, " \n");
	free(param_res);
}

void	norm_color(char *line, int *count, long *color)
{
	char	*param_res;

	param_res = param(line, count);
	*color = create_hexa(param_res);
	free(param_res);
}

int	is_valid_char_inzero(char **map, int i, int j, int size)
{
	if (i == 0 || i == size - 1 || j == 0 || j >= (int)ft_strlen(map[i]) - 1)
		return (0);
	if (j >= (int)ft_strlen(map[i + 1]) || j >= (int)ft_strlen(map[i - 1]))
		return (0);
	if (map[i][j + 1] == ' ' || map[i][j - 1] == ' '
		|| map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
		return (0);
	if (map[i + 1][j] == 10 || map[i - 1][j] == 10)
		return (0);
	return (1);
}
