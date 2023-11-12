/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:13:59 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/05 21:41:06 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	if(!string)
		return (0);
	while (*string)
	{
		i++;
		string++;
	}
	return (i);
}
