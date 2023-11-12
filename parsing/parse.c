/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:23:24 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/12 16:27:03 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int map_validity(char **map)
{
    int i;
    int j;
     
    i = 1;
        
    while(map[i])
    {
        j = 0;

        while(ft_isspace(map[i][j]))
        {
            j++;
        }
        while(map[i][j] != '\0')
        {
            
            if(!ft_strchr("01NSEW", map[i][j]))
            {
                printf ("map validity error\n");
                return -1;
            }
            j++;
        }
        while(j > 0 && ft_isspace(map[i][j - 1])) 
        {
            j--; //j -- because we want to check the last char of the line
        }    
        i++;
    }
    return 0;
}

char ** read_map(int height, int fd)
{
    char **map;
    char *line;
    int i;

    i = 0;
    map = malloc(sizeof(char *) * (height + 1));
    i = 0;
    while(i < height)
    {
        line = get_next_line(fd);
        map[i] = ft_strdup(line);
        free(line);
        i++;
    }
    map[i] = NULL;
    return (map);
}

char **read_and_store_map(char *arg, t_mlx *mlxx)
{
    int fd;
    char **whole_map;
    int height;

    fd = open(arg, O_RDONLY);
    height = get_map_height(fd);
    ft_bzero(mlxx, sizeof(t_mlx));
    close(fd);

    fd = open(arg, O_RDONLY);
    whole_map = read_map(height, fd);
    close(fd);

    return whole_map;
}

char **validate_and_return_map(char **whole_map, t_mlx *mlxx)
{
    char **mapy;
    int store_param_;
    int check_path_;

    store_param_ =  store_params(whole_map, mlxx);
    check_path_ = check_path(mlxx);
    if (store_param_ == 6 && check_path_ == 0)
    {
        mapy = pure_map(whole_map);
        if(!mapy)
        {
            free_double(whole_map); 
            return NULL;
        }
        if (inside_map(mapy) == -1)
        {   
            free_double(mapy);
            return NULL;
        }
        else
        {
            return mapy;
        }
    }
    else
    {
        printf("Bad Map params not completed\n");
        return NULL;
    }
}

char **cube3d_full_map(char *arg, t_mlx *mlxx)
{
    char **whole_map = read_and_store_map(arg, mlxx);
    char **validate_and_return_map_;
    
    if (whole_map == NULL)
    {
        return NULL;
    }
    validate_and_return_map_ = validate_and_return_map(whole_map, mlxx);
    if(validate_and_return_map_ == NULL)
    {
        return NULL;
    }
    return (validate_and_return_map_);
}