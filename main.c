/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:50:45 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/02 18:41:08 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game game;
	
	if (ac < 2)
		write(2, "Error\n", 6);
	if (is_it_ber(av[1]) == 0)
	{
		write(1, "this is not ber\n", 16);
		exit(1);
	}	
	game.nmap = av[1];
	read_map(av[1], &game);
	mlx_hook(game.win, 2, 1L<<0, for_key, &game);
	shaw_all(av[1], &game);
}
