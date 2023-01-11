/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:20:53 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/11 17:16:36 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	ft_error_printer(t_list1 *to_check, t_list2 *game)
{
	
	if (to_check -> equality == 1)
		return (ft_printf("Error\nThe Lines of the Map are not the exactly the same"), 1);
	else if (to_check -> walls == 1)
		return (ft_printf("Error\nYour Map it's not surrounded by Walls"), 1);
	else if (to_check -> imposter == 1)
		return (ft_printf("Error\nOne of The Characters is not one of its Compositions"), 1);
	if (to_check -> p_check != 1)
		return (ft_printf("Error\nThere is a Problem with Your player"), 1);
	else if (game -> cls_check == 0)
		return (ft_printf("Error\nThere is no collectibles to work with"), 1);
	else if(to_check -> e_check != 1)		
		return (ft_printf("Error\nThere is a Problem with your Exit"), 1);
	return (0);
}
int check_the_right_file(char *str)
{
	int j;
	j = ft_strlen(str) - 1;
	if (str[j] != 'r' && str[j - 1] != 'e' && str[j - 2] != 'r')
		return (1);
	return (0);
}
int	main(int ac, char **av)
{
	t_list1 to_check;
	t_list2 game; 
	if (ac == 2)
	{
		if (check_the_right_file (av[1]) == 1)
			return (ft_printf("Error\nThis is not the right file"), 0);
		game.p_line = 0;
		game.p_chara = 0;
	    if (themap(av[1], &game) == 0)
	 	{
			if (ft_check(&to_check, &game) == 1)
				return (ft_error_printer(&to_check,&game), 0);
			if (ft_check(&to_check, &game) == 0)
		  	{	
		 		if (floodfill(&game) == 1)
					return (0);
				else if (floodfill(&game) == 0)
					ft_mywindow(&game);
		 	}
		}
	}
	return (0);
}
