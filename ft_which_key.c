/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:13:59 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/02 12:16:57 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void ft_move(int key, int *a, int *b)
{
    if (key == 13 || key == 126)
    {
        *a = -1;
        *b = 0;
    }
    else if (key == 0 || key == 123)
    {
        *a = 0;
        *b = -1;
    }
    else if (key == 1 || key  == 125)
    {
        *a = 1;
        *b = 0;
    }
    else if (key == 2 || key == 124)
    {
        *a = 0;
        *b = 1;
    }
}
int ft_check_which_key(int key, t_LIST *game, int *line, int *chara)
{
    int a;
    int b;

    a = 0;
    b = 0;
    ft_move(key, &a, &b);
    if(a == 0 && b == 0)
        return (0);
    if (game -> MAP[*line + a][*chara + b] == '0' || game -> MAP[*line + a][*chara + b] == 'C')
    {
        if (game -> MAP[*line + a][*chara + b] == 'C')
            game -> check1--;
        game -> MAP[*line + a][*chara + b] = game -> MAP[*line][*chara];
        game -> MAP[*line][*chara] = '0';
        *line = *line + a;
        *chara = *chara + b;
        return (1);
    }
    else if (game -> MAP[*line + a][*chara + b] == '1')
        return (0); 
    else if (game -> MAP[*line + a][*chara + b] == 'E')
    {
        if (game -> check1 == 0)
        {
            mlx_destroy_window(game -> mlx_ptr, game -> win_ptr);
            exit(0);
        }
    }
    return (0);
   
}
int ft_which_key(int key, t_LIST *game)
{
    static int i;
    static int j;
    
    if (key == 53)   
        mlx_destroy_window(game -> mlx_ptr, game -> win_ptr);
    while (game -> MAP[j])
    {
        while (game -> MAP[j][i] != '\0' && game -> MAP[j][i] != 'P')
            i++;
        if (game -> MAP[j][i] == 'P')
            break;
        i = 0;
        j++; 
    }
    game -> check = ft_check_which_key(key, game, &j, &i);
    if (game -> check == 1)
    {
        mlx_clear_window(game -> mlx_ptr, game -> win_ptr);
        ft_put_img(game);
    }
    return (0);
}