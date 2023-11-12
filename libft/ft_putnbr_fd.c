/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:21:48 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/23 19:17:23 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	print_each_number(unsigned int num, int fd)
{
	char	c;

	if (num <= 0)
		return ;
	print_each_number(num / 10, fd);
	c = num % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr == 0)
		write(fd, "0", 1);
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	print_each_number(nbr, fd);
}
