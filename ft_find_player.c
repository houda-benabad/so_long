/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:59:36 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/10 13:48:34 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_list2 *game)
{
	while (game -> map[game -> p_line])
	{
		while (game -> map[game -> p_line][game -> p_chara] != '\0'
			&& game -> map[game -> p_line][game -> p_chara] != 'P')
			game -> p_chara++;
		if (game -> map[game -> p_line][game -> p_chara] == 'P')
			break ;
		game -> p_chara = 0;
		game -> p_line++;
	}
}
