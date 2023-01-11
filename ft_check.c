/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:59:19 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/11 15:49:38 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_valid(t_list2 *game, char c, int chara, int line)
{	
	game -> len = ft_strlen(game -> map[line]);
	game -> dolen = ft_dostrlen(game -> map);
	if (game -> map[line + 1])
	{
		if (ft_strlen(game -> map[line]) != ft_strlen(game -> map[line + 1]))
			return (1);
	}
	else if (line == 0 || chara == 0 || chara == game -> len - 1
		|| line == game -> dolen - 1)
	{	
		if (c != '1')
			return (2);
	}
	if (c == 'P')
		game -> p_check++;
	else if (c == 'C')
		game -> cls_check++;
	else if (c == 'E')
		game-> e_check++;
	else if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		return (3);
	else if (line == game -> dolen - 1 && (game -> p_check != 1
			|| game -> cls_check == 0 || game -> e_check != 1))
		return (4);
	return (0);
}

int	ft_check(t_list2 *game)
{
	int	i;
	int	line;

	line = 0;
	game -> cls_check = 0;
	game -> p_check = 0;
	game -> e_check = 0;
	game -> dolen = ft_dostrlen(game -> map);
	if (ft_strlen(game -> map[line]) != ft_dostrlen(game -> map))
	{
		game -> len = ft_strlen(game -> map[line]);
		while (game -> map[line])
		{
			i = 0;
			while (game ->map[line][i])
			{
				if (ft_valid(game, game -> map[line][i], i, line) != 0)
					return (ft_valid(game, game -> map[line][i], i, line));
				i++;
			}
			line++;
		}
	}
	return (0);
}