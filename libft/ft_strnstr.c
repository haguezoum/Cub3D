/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:33:47 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/13 19:00:58 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnstr(const char *bigStr, const char *smlStr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (bigStr == NULL && len == 0)
		return (NULL);
	if (smlStr[0] == '\0')
		return ((char *)bigStr);
	while (bigStr[i])
	{
		while ((smlStr[j] == bigStr[i + j]) && len > i + j)
		{
			if (smlStr[j + 1] == '\0')
				return ((char *)bigStr + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
