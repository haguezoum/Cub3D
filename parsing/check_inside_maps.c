/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside_maps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:26:17 by haguezou          #+#    #+#             */
/*   Updated: 2023/11/12 18:31:42 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_inside_err(char **map, char sus)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;

    while(map[i])
    {
        j  = 0;
        while(map[i][j])
        {
            if(map[i][j] == sus)
            {
                printf("%d\n", map[i][j]);
                printf("%d\n", map[i][j + 1]);
                printf("%d\n", map[i][j - 1]);
                printf("%d\n", map[i + 1][j]);
                printf("%d\n", map[i - 1][j]);
                
                if(map[i][j + 1] == 10 || map[i][j - 1] == 10 || map[i + 1][j] == 10 || map[i - 1][j] == 10)
                {
                    return (-1);
                }
            }
            j++;
        }
        i++;
    }
    return (0);
}

int table_counter(char **tab)
{
    int count;

    count = 0;
    if (!tab)
        return (0);
    while(tab[count])
        count++;
    return(count);
}

int open_zero(char **map) {
    int i = 0;
    int j = 0;

    while (map[i]) 
    {
        j = 0;
        while (map[i][j]) 
        { 
            if (map[i][j] == '0')
            {
                if (i == 0 || i == table_counter(map) - 1 || j == 0 || j == (int)ft_strlen(map[i]) - 2)
                    return (-1);
                if (j >= (int)ft_strlen(map[i + 1])  || j >= (int)ft_strlen(map[i - 1]) )
                {
                    printf("i => %d | j=> %d\n", i, j);
                    return (-1);
                }
                if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == 10 || map[i][j - 1] == 10)
                {
                    return (-1);
                }
                if ((map[i + 1][j] && (map[i + 1][j] == ' ' || map[i + 1][j] == 10))  || (map[i - 1][j] == ' ' && (map[i - 1][j] || map[i - 1][j] == 10)))
                {
                    return (-1);
                }
            }
            j++;
        }
        i++;
    }

    return 0;
}

int player_position_count(char **map)
{
    int i;
    int j;
    int count;
    i = 0;
    j = 0;
    count = 0;
    
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
            {
                count++;
            }
            j++;
        }
        i++;
    }
    if(count > 1 || count == 0)
    {
        return (-1);
    }
    return (0);
}

int is_valid_char(char c) 
{
    return (c == '0' || c == '1' || c == 'S' || c == 'N' || c == 'W' || c == 'E' || c == '\n' || c == ' ');
}

int main_units(char **map) 
{
    int i = 0;

    while (map[i]) 
    {
        int j = 0;
        while(ft_isspace(map[i][j]))
        {
            j++;
        }
        while (map[i][j]) 
        {
            if (!is_valid_char(map[i][j])) 
            {
                printf("Invalid character at map[%d][%d]:%c => %d\n", i, j, map[i][j], map[i][j]);
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

int space_sus(char **map)
{   
    if(check_inside_err(map, 'N') == -1 || check_inside_err(map, 'S') == -1 ||
        check_inside_err(map, 'E') == -1 || check_inside_err(map, 'W') == -1)
    {
        return (-1);
    }
   
    // int x = check_inside_err(map, '0');
    int y = open_zero(map);
    if(y != 0)
    {
        return (-1);
    }
    return (0);
}

int inside_map(char **map)
{
    char *err_msg1;
    char *err_msg2;
    
    err_msg1 = "Error in map\nMap accept only 1,0,(N | S | E | W) !\n";
    err_msg2 = "Error in map\nSpace (between || around) 0 or (N | S | E | W) !\n";
   
    if(main_units(map) == -1)
    {
        write(2, err_msg1, ft_strlen(err_msg1));
        return (-1);
    }
    if (space_sus(map) == -1)
    {
        write(2, err_msg2 , ft_strlen(err_msg2));
        return (-1);
    }
    if(player_position_count(map) == -1)
    {
        write(2, "Error\nMap accept only 1 player position no more no less !\n", 59);
        return (-1);   
    }

    return (0);
}
