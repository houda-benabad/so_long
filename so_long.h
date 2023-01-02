/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:50:41 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/02 11:01:32 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct game
{
    char **MAP;
    int len;
    int dolen;
    int true;
    int check;
    int check1;
    int x;
    int y;
    void *wall;
    void *floor;
    void *rabbit;
    void *carrot;
    void *exit;
    void *mlx_ptr;
    void *win_ptr;
}   t_LIST;
char **themap(char *map); 
int ft_check(t_LIST *game);
int ft_mywindow(t_LIST *game);
size_t ft_dostrlen(char **MAP);
size_t	ft_strlen(const char *s);
void *ft_which_image(char c, t_LIST *game);
void ft_which_pointer(t_LIST *game);
int ft_put_img(t_LIST *game);
int ft_which_key(int key, t_LIST *game);

#endif