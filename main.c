/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:50:45 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/18 19:43:17 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game *game;
	t_window *window;
	t_wall *wall;
	
	game = malloc(sizeof(t_game));
	window = malloc(sizeof(t_window));
	wall = malloc(sizeof(t_wall));

	game->window = *window;
	game->wall = *wall;
	
	char *relative_path = "./sprites/brick.xpm";
	(void)av;
	(void)ac;
	int w = 100;
	int h = 100;
	game->fmlx = mlx_init();
	game->window = new_window(game->fmlx, 1000, 900, "HI!");
	game->wall.brick = mlx_xpm_file_to_image(game->fmlx, relative_path, &w, &h);
	// printf("%p\n", game->wall->brick);
	opspr(game);
	mlx_loop(game->fmlx);
}