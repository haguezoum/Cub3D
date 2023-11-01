/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:52:19 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/11/01 16:16:54 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	*load_color(t_mlx *mlx, char *path)
{
	int				weight;
	int				height;
	int				size_line;
	int				endian;
	void			*new;
	unsigned int	*img_data;

	new = mlx_xpm_file_to_image(mlx->mlx, path, &height, &weight);
	img_data = (unsigned int *)mlx_get_data_addr(new,
			&weight, &size_line, &endian);
	return (img_data);
}
