/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:04:52 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/15 14:59:25 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		t = *lst;
		while (t->next)
		{
			t = t->next;
		}
		t->next = new;
	}
}
