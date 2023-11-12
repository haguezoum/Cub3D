/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:04:52 by haguezou          #+#    #+#             */
/*   Updated: 2022/10/26 17:39:53 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
