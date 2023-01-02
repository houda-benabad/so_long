/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   themap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:35:33 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/02 10:03:27 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char **themap(char *map)
{
    int fd;
    char *line;
    char *LINE;
    t_LIST game;
    
    fd = open(map, O_RDONLY);
    if (fd == -1)
        return (NULL);
    LINE = NULL;
    line = get_next_line(fd);
    while (line != NULL)
    {
        LINE = ft_join(LINE, line);
        line = get_next_line(fd);
    }
    if (LINE[ft_strlen(LINE) - 1] == '\n' && LINE[ft_strlen(LINE)] == '\0')
        return (NULL);
    game.MAP = ft_split(LINE, '\n');
    return (game.MAP);
}

