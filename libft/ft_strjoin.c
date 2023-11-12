/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:01:06 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/17 17:11:30 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	ptr = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!ptr)
		return (0);
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
