/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:13:59 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/11 18:49:21 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_move(int key, int *a, int *b)
{
	*a = 0;
	*b = 0;
	if (key == 13 || key == 126)
		*a = -1;
	else if (key == 0 || key == 123)
		*b = -1;
	else if (key == 1 || key == 125)
		*a = 1;
	else if (key == 2 || key == 124)
		*b = 1;
}

int	ft_check_which_key(t_list2 *game, int *line, int *chara)
{
	if (game -> map[*line + game -> mbls][*chara + game -> mbcs] == '0'
		|| game -> map[*line + game -> mbls][*chara + game -> mbcs] == 'C')
	{
		if (game -> map[*line + game -> mbls][*chara + game -> mbcs] == 'C')
			game -> cls_check--;
		game -> map[*line + game -> mbls][*chara + game -> mbcs]
			= game -> map[*line][*chara];
		game -> map[*line][*chara] = '0';
		*line = *line + game -> mbls;
		*chara = *chara + game -> mbcs;
		return (1);
	}
	else if (game -> map[*line + game -> mbls][*chara + game -> mbcs] == '1')
		return (0);
	else if (game -> map[*line + game -> mbls][*chara + game -> mbcs] == 'E')
	{
		if (game -> cls_check == 0)
		{
			mlx_destroy_window(game -> mlx_ptr, game -> win_ptr);
			exit(0);
		}
	}
	return (0);
}

int	ft_which_key(int key, t_list2 *game)
{
	if (key == 53)
	{
		mlx_destroy_window(game -> mlx_ptr, game -> win_ptr);
		exit(0);
	}
	ft_find_player(game);
	ft_move(key, &(game -> mbls), &(game -> mbcs));
	if (game -> mbls == 0 && game -> mbcs == 0)
		return (0);
	game -> check = ft_check_which_key
		(game, &(game -> p_line), &(game -> p_chara));
	if (game -> check == 1)
	{
		mlx_clear_window(game -> mlx_ptr, game -> win_ptr);
		ft_put_img(game);
	}
	game -> move++;
	ft_printf("step : %d\n", game -> move);
	return (0);
}
