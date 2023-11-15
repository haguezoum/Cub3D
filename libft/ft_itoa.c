/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:51:44 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/15 15:00:29 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_num(long long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while (num)
	{
		count ++;
		num = num / 10;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int			count;
	char		*ptr;
	long long	n;

	n = nbr;
	count = count_num(n);
	ptr = (char *)ft_calloc(count + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	if (n < 0)
		n *= -1;
	while (count)
	{
		ptr[count - 1] = (n % 10) + '0';
		n = n / 10;
		count--;
	}
	if (nbr < 0)
		ptr[0] = '-';
	return (ptr);
}
