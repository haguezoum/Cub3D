/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:34:57 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/09 17:04:59 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s || *s == (char) c)
	{
		if (*s == (char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
