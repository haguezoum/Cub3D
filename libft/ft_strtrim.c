/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:15:43 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/26 17:39:20 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	f_index;
	int	l_index;
	int	len;

	i = 0;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[i]))
	{
		i++;
	}
	f_index = i;
	i = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[i]))
	{
		i--;
	}
	l_index = i;
	len = (l_index - f_index) + 1;
	return (ft_substr((char *)s1, f_index, len));
}
