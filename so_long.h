/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:50:41 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/11 12:18:07 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "./libft/ft_printf/ft_printf.h"

typedef struct to_check
{
	int imposter;
	int equality;
	int walls;
}	t_list1;

typedef struct game
{
	char **map;
	int len;
	int dolen;
	int move;
	int x;
	int y;
	int cls_check;
	int p_check;
	int e_check;
	int check;
	int true3;
	int p_line;
	int p_chara;
	int mbls;
	int mbcs;
	void *wall;
	void *floor;
	void *rabbit;
	void *carrot;
	void *exit;
	void *mlx_ptr;
	void *win_ptr;
}   t_list2;

int themap(char *map, t_list2 *game); 
int	ft_check(t_list2 *game);
int ft_mywindow(t_list2 *game);
size_t ft_dostrlen(char **MAP);
size_t	ft_strlen(const char *s);
void *ft_which_image(char c, t_list2 *game);
void ft_which_pointer(t_list2 *game);
int ft_put_img(t_list2 *game);
int ft_which_key(int key, t_list2 *game);
int floodfill(t_list2 *game);
void ft_find_player(t_list2 *game);
#endif