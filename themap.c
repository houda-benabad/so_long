/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   themap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:35:33 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/11 18:27:38 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
int check_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			return (1);
		i++;
	}
	return (0);
}
int	themap(char *map, t_list2 *game)
{
	int		fd;
	char	*line;
	char	*str;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nThat is not the right file"), 1);
	str = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf("Error\nThere is no Map to work with"), 1);
	while (line != NULL)
	{
		str = ft_join(str, line);
		line = get_next_line(fd);
	}
	if (check_str(str) == 1)
		return (ft_printf("Error\nThere is an empty line on The Map"), 1);
	game -> map = ft_split(str, '\n');
	return (0);
}
