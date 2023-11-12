/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:22:13 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/12 18:01:38 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void free_double(char **double_char_pointer)
{
    int i;

    i = 0;
    while(double_char_pointer[i])
    {
        free(double_char_pointer[i]);
        i++;
    }
    free(double_char_pointer);
}
