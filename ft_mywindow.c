/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   : hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:50:43  hobenaba          #+#    #+#             */
/*   Updated: 2022/12/29 17:52:04  hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int ft_mywindow(t_LIST *game)
{
    game -> mlx_ptr = mlx_init();
    game -> win_ptr = mlx_new_window(game -> mlx_ptr, 60 * game -> len, 60 * game -> dolen, "My Game");
    ft_which_pointer(game);
    ft_put_img(game);
    mlx_key_hook(game -> win_ptr, ft_which_key, game);
    mlx_loop(game -> mlx_ptr);
    //printf("in ft_mywindow :\n%d", game -> check1);
    return (0);
}