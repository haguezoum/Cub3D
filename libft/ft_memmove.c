/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 02:02:54 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/07 13:35:36 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	int	i;

	i = n - 1;
	if (dest > src)
	{
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
		return (dest);
	}
	else
	{
		return (ft_memcpy(dest, src, n));
	}
}
