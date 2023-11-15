/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:57:58 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/15 15:10:41 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	w_count(const char *s, char c)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	j = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				words += 1;
			i++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	v;
	char	**ptr;

	i = 0;
	j = 0;
	v = 0;
	if (!s)
		return (0);
	ptr = ft_calloc(w_count(s, c) + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s[i] && (int)j < w_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		v = i;
		while (s[i] != c && s[i])
			i++;
		ptr[j] = ft_substr(s, v, i - v);
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}
