/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:12:26 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/13 22:31:45 by haguezou         ###   ########.fr       */
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
