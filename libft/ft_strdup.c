/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:05:01 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/15 15:12:04 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	stlen;
	size_t	size;
	char	*ptr;
	size_t	i;

	stlen = ft_strlen((char *)str) + 1;
	size = sizeof (*((char *) str));
	i = 0;
	ptr = (char *) ft_calloc(stlen, size);
	if (ptr == NULL)
		return (NULL);
	while (stlen > i)
	{
		ptr[i] = (char)str[i];
		i++;
	}
	return (ptr);
}
