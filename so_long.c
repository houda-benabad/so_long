/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hobenaba <hobenaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:20:53 by hobenaba          #+#    #+#             */
/*   Updated: 2023/01/11 15:48:15 by hobenaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	ft_error_printer(t_list2 *game)
{
	// if (to_check -> equality == 1)
	// 	ft_printf("Error\nThe Lines of the Map are not the exactly the same");
	// else if (to_check -> walls == 1)
	// 	ft_printf("Error\nYour Map it's not surrounded by Walls");
	// else if (to_check -> imposter == 1)
	// 	ft_printf("Error\nOne of The Characters is not one of its Compositions");
	if (game -> p_check != 1)
		ft_printf("Error\nThere is a Problem with Your player");
	else if (game -> cls_check == 0)
		ft_printf("Error\nThere is no collectibles to work with");
	else if(game -> e_check != 1)		
		ft_printf("Error\nThere is a Problem with your Exit");
}

int	main(int ac, char **av)
{
	t_list2 game; 
	if (ac == 2)
	{
		game.p_line = 0;
		game.p_chara = 0;
	    if (themap(av[1], &game) == 0)
	 	{
			if (ft_check(&game) == 1)
				return (ft_error_printer(&game), 0);
			if (ft_check(&game) == 0)
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
