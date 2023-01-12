/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mywindow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:24:59 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/12 12:01:46 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_which_event(t_list2 *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game -> map);
	exit(0);
}

int	ft_mywindow(t_list2 *game)
{
	game->move = 0;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window
		(game->mlx_ptr, 60 * game->len, 60 * game->dolen, "My Game");
	ft_which_pointer(game);
	ft_put_img(game);
	mlx_hook(game->win_ptr, 2, 0, ft_which_key, game);
	mlx_hook(game->win_ptr, 17, 0, ft_which_event, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
