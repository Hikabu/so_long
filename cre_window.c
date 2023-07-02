/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cre_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:13:49 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/01 03:36:10 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*pxpm(char *path, t_game *game)
{
	void	*ptr;
	
	ptr = mlx_xpm_file_to_image(game->fmlx, path,
			&game->img_w, &game->img_h);
	return (ptr);
}

void	put_tile(t_game *game, char **map, int i, int o)
{
	void	*wall;
	void	*pol;
	void	*collect;
	void	*player;
	void	*exit;
	
	wall = pxpm(WALL, game);
	pol = pxpm(BRICK, game);
	collect = pxpm(COLLECT, game);
	player = pxpm(PLAYER, game);
	exit = pxpm(EXIT, game);
	if (map[i][o] == '1')
		mlx_put_image_to_window(game->fmlx, game->win, wall, o * SIZE, i * SIZE);
	else if (map[i][o] == 'E')
		mlx_put_image_to_window(game->fmlx, game->win, exit, o * SIZE, i * SIZE);
	else if (map[i][o] == 'P')
	{
		mlx_put_image_to_window(game->fmlx, game->win, pol, o * SIZE, i * SIZE);
		mlx_put_image_to_window(game->fmlx, game->win, player, o * SIZE, i * SIZE);
	}
	else if (map[i][o] == 'C')
	{
		mlx_put_image_to_window(game->fmlx, game->win, pol, o * SIZE, i * SIZE);
		mlx_put_image_to_window(game->fmlx, game->win, collect, 
			o * SIZE, i * SIZE);
	}
	else
		mlx_put_image_to_window(game->fmlx, game->win, pol, o * SIZE, i * SIZE);
}

void    put_imgs(char **map, t_game *game)
{
	int i;
	int o;

	i = -1;
	while (map[++i])
	{
		o = -1;
		while (map[i][++o])
			put_tile(game, map, i, o);
	}
}