/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:59:19 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/11 18:19:39 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_valid(t_list1 *to_check, t_list2 *game, int line, int chara)
{	
	if (game -> map[line + 1])
	{
		if (ft_strlen(game -> map[line]) != ft_strlen(game -> map[line + 1]))
			return (to_check -> equality = 1, 1);
	}
	if (line == 0 || chara == 0 || chara == game -> len - 1 || line == game -> dolen - 1)
	{
		if (game -> map[line][chara] != '1')
			return (to_check -> walls = 1, 1);
	}
	if (game -> map[line][chara] == 'P')
		to_check -> p_check++;
	else if (game -> map[line][chara] == 'C')
		game -> cls_check++;
	else if (game -> map[line][chara] == 'E')
		to_check-> e_check++;
	else if (game -> map[line][chara] != '0' && game -> map[line][chara] != '1' && game -> map[line][chara] != 'P' && game -> map[line][chara] != 'E' && game -> map[line][chara] != 'C')
		return (to_check -> imposter = 1, 1);
	if (line == game -> dolen - 1 && chara == game -> len - 1 && (to_check -> p_check != 1
			|| game -> cls_check == 0 || to_check -> e_check != 1))
		return (1);
	return (0);
}

int	ft_check(t_list1 *to_check,t_list2 *game)
{
	int	i;
	int	line;
	
	game -> cls_check = 0;
	to_check -> p_check = 0;
	to_check -> e_check = 0;
	line = 0;
	game -> dolen = ft_dostrlen(game -> map);
	game -> len = ft_strlen(game -> map[line]);
	if (ft_strlen(game -> map[line]) != ft_dostrlen(game -> map))
	{
		while (game -> map[line])
		{
			i = 0;
			while (game ->map[line][i])
			{
				if (ft_valid(to_check, game, line, i) == 1)
					return (1);
				i++;
			}
			line++;
		}
	}
	return (0);
}