/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:38:32 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/15 15:13:44 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*ptr;
	unsigned int		i;

	i = start;
	if (!s)
		return (0);
	if (ft_strlen((char *)s) < len)
		len = ft_strlen((char *)s) - i;
	if (i >= ft_strlen((char *)s))
		return (ft_strdup(""));
	ptr = (char *)ft_calloc(len + 1, sizeof(*s));
	if (!ptr)
	{
		return (0);
	}
	if (ptr != NULL)
	{
		return ((char *)ft_memmove(ptr, (char *)s + i, len));
	}
	return (NULL);
}
