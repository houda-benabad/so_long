/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:20:53 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/02 11:32:05 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int main(int ac, char **av)
{
    t_LIST game;
    if (ac == 2)
    {
        game.MAP = themap(av[1]);
    //     printf("%s", game.MAP[0]);
        if (game.MAP == NULL)
            return (write (1, "error\n", 6), 0);
        game.true = ft_check(&game);
        if (game.true != 1)
        {
            //printf("im hier");
            ft_mywindow(&game);
        }
    }
    return (0);
}