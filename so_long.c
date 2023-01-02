/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:20:53 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/02 16:29:38 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
void ft_which_error(t_LIST *game)
{
    if (game -> true == 1)
        ft_printf("Error\nThe Lines of the Map are not the exactly the same");
    else if (game -> true == 2)
        ft_printf("Error\nYour Map it's not surrounded by Walls");
    else if (game -> true == 3)
        ft_printf("Error\nOne of The Characters is not one of its Compositions");
    else if (game -> true == 4)
        ft_printf("Error\nThe Map is not Rectangular, do I have to be specific wit this also");
}
int main(int ac, char **av)
{
    t_LIST game;
    if (ac == 2)
    {
        game.MAP = themap(av[1]);
        // if (game.MAP == NULL)
        //      return(ft_printf("Error\nYour Map it's not surrounded by Walls"), 0);
        game.true = ft_check(&game);
        //printf("%d", game.true);
        if (game.true != 0)
            ft_which_error(&game);
        else if (game.true == 0)    
            ft_mywindow(&game); 
    }
    return (0);
}