/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:18:09 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/11 16:07:35 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int get_map_height(int fd)
{
    int height;

    height = 0;

    while(get_next_line(fd))
    {
        height++;
    }
    close(fd);
    return height;
}

long create_hexa(char *RGB)
{  
   int r;
   int g;
   int b;
   char **rgb;

   r = 0;
   g = 0;
   b = 0;

   rgb = ft_split(RGB, ',');
	if(check_rgb_count(rgb) == -1 || check_comma(RGB) == -1)
	{
		printf("ERROR\nRGB error");
		// return (-1);
		exit(0);
	}
   r = cube_atoi(ft_strtrim(rgb[0], "\n"));
   g = cube_atoi(ft_strtrim(rgb[1], "\n"));
   b = cube_atoi(ft_strtrim(rgb[2], "\n"));
//    free(rgb);
   if(r == -1 || g == -1 || b == -1)
   {
	   printf("ERROR \nRGB not right!");
	   exit(0);
   }
   return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

char **pure_map(char **map)
{
    int i;
    int j;
    int k;
    char **pure_map;

    i = 0;
    j = 0;
    k = 0;
    while(map[i])
    {
        if(ft_strncmp("1", ft_strtrim(map[i], " "), 1) == 0 || ft_strncmp("0", ft_strtrim(map[i], " "), 1) == 0)
        {
            j++; // count the number of lines in the map (without the params)
        }
        i++;
    }
    
    pure_map = malloc(sizeof(char *) * (j + 1));
    i = 0;
    j = 0;
    
    while(map[i])
    {
        if(j > 0)
        {
            // check \n inside map, if yes return error and enythig else than 01NNSWE
            if(ft_strncmp("\n", ft_strtrim(map[i], " "), 1) == 0 || ft_strchr("012NEWS", ft_strtrim(map[i], " ")[0]) == 0)
            {
                printf("Error\nMap is not valid !\n");
                exit(0);
            }
        }
        if(ft_strncmp("1", ft_strtrim(map[i], " "), 1) == 0 || ft_strncmp("0", ft_strtrim(map[i], " "), 1) == 0)
        {
            pure_map[j] = ft_strdup(map[i]);
            j++;
        }
        i++;
    }
    pure_map[j] = NULL;
    return pure_map;
}