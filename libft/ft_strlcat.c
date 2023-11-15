/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:54:50 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/15 14:59:25 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	dlen;

	i = 0;
	j = 0;
	if (!dest && n == 0)
		return (ft_strlen(src));
	dlen = ft_strlen(dest);
	if (ft_strlen(dest) >= n)
		return (ft_strlen(src) + n);
	i = ft_strlen(dest);
	while (src[j] && i < n - 1)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dlen + ft_strlen((char *)src));
}
