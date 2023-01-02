/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:59:19 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/02 11:29:13 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int ft_valid(t_LIST *game, char c, char chara, int line)
{   
    game -> len = ft_strlen(game -> MAP[line]);
    game -> dolen = ft_dostrlen(game -> MAP);
    if (game -> MAP[line + 1])
    {
        if (ft_strlen(game -> MAP[line]) != ft_strlen(game -> MAP[line + 1]))
            return (1);
    }
    if (line == 0 || chara == 0 || chara == game -> len - 1|| line == game -> dolen - 1)
    {   
        if (c != '1')
            return (1);
    }
    else if (c == 'P' || c == 'E')
        game -> check++;
    else if (c == 'C')
        game -> check1++;
    else if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
        return (1);
    //printf("%d", game -> check1);
    if (line == game -> dolen && (game -> check != 2 || game -> check1 == 0))
        return (1);
    return (0);
}
int ft_check(t_LIST *game)
{
    int i;
    int j;

    j = 0;
    game -> check = 0;
    game -> check1 = 0;
    game -> dolen = ft_dostrlen(game -> MAP);
    if (ft_strlen(game -> MAP[j]) != ft_dostrlen(game -> MAP))
    {
        game -> len = ft_strlen(game -> MAP[j]);
        while (game -> MAP[j])
        {
            i = 0;
            while (game ->MAP[j][i])
            {
                if (ft_valid(game, game -> MAP[j][i], i, j) == 1)
                    return (1);
                i++;
            }   
            j++;
        }
    }
    return (0);
}