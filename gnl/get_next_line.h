/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:02:50 by haguezou          #+#    #+#             */
/*   Updated: 2023/10/17 16:47:20 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_substr(char *s, unsigned int start, size_t len);
int		gnl_strchr(const char *s, char c);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *s);
char	*gnl_calloc(int count, int size);
#endif
