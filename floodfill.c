/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:51:34 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/06 12:33:23 by hobenaba         ###   ########.fr       */
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

int	floodfill_map_changer(char **flmap, int j, int i)
{
	//printf("%c\n", flmap[j][i]);
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
	return (0);
}

int	floodfill(t_LIST *game)
{
	char	**p;
	int		j;
	int		i;
	int		rq;
	int		rq2;

	p = floodfill_map(game);
	ft_find_player(game);
	j = game -> p_line;
	i = game -> p_chara;
	rq = 0;
	rq2 = 0;
	floodfill_map_changer(p, j, i);
	printf("the first line : %s\n", p[0]);
	printf("the second line : %s\n", p[1]);
	printf("the third line : %s\n", p[2]);
	printf("the fourth line : %s\n", p[3]);
	printf("the fifth line : %s\n", p[4]);
	printf("the sixth line : %s\n", p[5]);
	j = 0;
	while (p[j])
	{
		i = 0;
		while (p[j][i])
		{
			if (p[j][i] == 'C')
				rq = 5;
			else if (p[j][i] == 'E')
			{
				if (p[j][i + 1] != 'H' && p[j][i - 1] != 'H'
					&& p[j + 1][i] != 'H' && p[j - 1][i] != 'H')
					rq2 = 6;
			}
			i++;
		}
		j++;
	}
	if (rq == 5 && rq2 == 6)
		return (7);
	else if (rq == 0)
		return (rq2);
	return (rq);
}
