/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:14:16 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/10/05 11:07:34 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*copy;

	copy = malloc(sizeof(char ) * (ft_strlen(str) + 1));
	if (!copy)
		return (NULL);
	copy[0] = 0;
	return (copy);
}

int	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	while (str1[i] != '\0')
	{
		newstr[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		newstr[i] = str2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_substr(char *s, int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*b;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (slen < len)
		len = slen;
	i = 0;
	if (!s)
		return (0);
	b = malloc(sizeof(char) * (len + 1));
	if (b == 0)
		return (0);
	while (i < len && start < ft_strlen(s))
	{
		b[i] = s[start];
		i++;
		start++;
	}
	b[i] = '\0';
	return (b);
}
