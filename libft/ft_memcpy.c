/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:35:57 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/07 13:02:15 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = n;
	if (!dest && !src)
	{
		return (0);
	}
	while (n != 0)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		n--;
	}
	return (dest - i);
}
