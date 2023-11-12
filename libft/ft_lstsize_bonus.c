/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:13:17 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/26 19:49:20 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	if (!lst)
	{
		return (0);
	}
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
