/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:41:21 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/16 17:20:54 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*mystr;
	size_t	strlen;

	mystr = (char *)str;
	strlen = ft_strlen(mystr) + 1;
	while (strlen--)
	{
		if (mystr[strlen] == (unsigned char)c)
			return (&mystr[strlen]);
	}
	return (NULL);
}
