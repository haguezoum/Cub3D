/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:15:49 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/22 22:45:24 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
