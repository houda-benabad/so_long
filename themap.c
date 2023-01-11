/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   themap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:35:33 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/11 11:30:33 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	themap(char *map, t_list2 *game)
{
	int		fd;
	char	*line;
	char	*str;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (1);
	str = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf("Error\nThere is no Map to work with"), 1);
	while (line != NULL)
	{
		str = ft_join(str, line);
		line = get_next_line(fd);
	}
	if (str[ft_strlen(str) - 1] == '\n' && (str[ft_strlen(str)] == '\0'
			|| str[ft_strlen(str)] == '\n'))
		return (ft_printf("Error\nThis is Not a Valid Map"), 1);
	game -> map = ft_split(str, '\n');
	return (0);
}
