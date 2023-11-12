/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:56:11 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/07 12:47:12 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)ptr)[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
