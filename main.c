/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:50:45 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/03 13:31:51 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac < 2)
		write(2, "Error\n", 6);
	if (is_it_ber(av[1]) == 0)
	{
		write(1, "this is not ber\n", 16);
		exit(1);
	}	
	game.nmap = av[1];
	read_map(av[1], &game);
	shaw_all(&game);
}

void	stroki(t_game *game, char *pl, char *side)
{
	{
		mlx_clear_window(game->fmlx, game->win);
		move(game, pl, side);
		put_imgs(game->map, game);
	}
}
