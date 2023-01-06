/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:51:34 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/06 17:00:41 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	**floodfill_map(t_LIST *game)
{
	char	**p;
	int		j;

	p = malloc ((game -> dolen - 1) * sizeof (char *));
	if (!p)
		return (NULL);
	j = 0;
	while (j < game -> dolen)
	{
		p[j] = ft_strdup(game -> MAP[j]);
		j++;
	}
	p[j] = 0;
	return (p);
}

void	floodfill_map_changer(char **flmap, int j, int i)
{
	if (flmap[j][i + 1] != '1' && flmap[j][i + 1] != 'E'
		&& flmap[j][i + 1] != 'H')
	{
		flmap[j][i + 1] = 'H';
		floodfill_map_changer(flmap, j, i + 1);
	}
	if (flmap[j][i - 1] != '1' && flmap[j][i - 1] != 'E'
		&& flmap[j][i - 1] != 'H')
	{
		flmap[j][i - 1] = 'H';
		floodfill_map_changer(flmap, j, i - 1);
	}
	if (flmap[j + 1][i] != '1' && flmap[j + 1][i] != 'E'
		&& flmap[j + 1][i] != 'H')
	{
		flmap[j + 1][i] = 'H';
		floodfill_map_changer(flmap, j + 1, i);
	}
	if (flmap[j - 1][i] != '1' && flmap[j - 1][i] != 'E'
		&& flmap[j - 1][i] != 'H')
	{
		flmap[j - 1][i] = 'H';
		floodfill_map_changer(flmap, j - 1, i);
	}
}

int	ft_check_themap(char **p, int line, int chara)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (p[line][chara] == 'C')
		a = 5;
	else if (p[line][chara] == 'E')
	{
		if (p[line][chara + 1] != 'H' && p[line][chara - 1] != 'H'
			&& p[line + 1][chara] != 'H' && p[line - 1][chara] != 'H')
		b = 6;
	}
	else if (a == 6 && b == 5)
		return (7);
	else if (a != 0)
		return (b);
	return (a);
}

int	floodfill(t_LIST *game)
{
	char	**p;
	int		j;
	int		i;

	j = 0;
	i = 0;
	p = floodfill_map (game);
	ft_find_player(game);
	//floodfill_map_changer(p, game -> p_line, game -> p_chara);
	printf("the first line : %s\n", p[0]);
	printf("the second line : %s\n", p[1]);
	printf("the third line : %s\n", p[2]);
	printf("the fourth line : %s\n", p[3]);
	printf("the fifth line : %s\n", p[4]);
	printf("the sixth line : %s\n", p[5]);
	while (p[j])
	{
		i = 0;
		while (p[j][i])
		{
			if (p[j][i] == 'C' || p[j][i] == 'E')
			{
				if (ft_check_themap(p, j, i) != 0)
					return (ft_check_themap(p, j, i));
			}
			i++;
		}
		j++;
	}
	return (0);
}
