/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:59:19 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/12 12:46:12 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_valid(t_list1 *to_check, t_list2 *game, int j, int i)
{	
	char	c;

	c = game -> map[j][i];
	if (game -> map[j + 1])
	{
		if (ft_strlen(game -> map[j]) != ft_strlen(game -> map[j + 1]))
			return (to_check -> equality = 1, 1);
	}
	if (j == 0 || i == 0 || i == game -> len - 1 || j == game -> dolen - 1)
	{
		if (c != '1')
			return (to_check -> walls = 1, 1);
	}
	if (game -> map[j][i] == 'P')
		to_check -> p_check++;
	else if (game -> map[j][i] == 'C')
		game -> cls_check++;
	else if (game -> map[j][i] == 'E')
		to_check-> e_check++;
	else if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		return (to_check -> imposter = 1, 1);
	if (j == game->dolen - 1 && i == game->len - 1 && (to_check->p_check != 1
			|| game->cls_check == 0 || to_check->e_check != 1))
		return (1);
	return (0);
}

int	ft_check(t_list1 *to_check, t_list2 *game)
{
	int	i;
	int	j;

	game -> cls_check = 0;
	to_check -> p_check = 0;
	to_check -> e_check = 0;
	j = 0;
	game -> dolen = ft_dostrlen(game -> map);
	game -> len = ft_strlen(game -> map[j]);
	while (game -> map[j])
	{
		i = 0;
		while (game ->map[j][i])
		{
			if (ft_valid(to_check, game, j, i) == 1)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
