/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cre_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:13:49 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/03 13:28:49 by vfedorov         ###   ########.fr       */
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
	if (map[i][o] == '1')
		mlx_put_image_to_window(game->fmlx, game->win,
			game->wall, o * SIZE, i * SIZE);
	else if (map[i][o] == 'E')
		mlx_put_image_to_window(game->fmlx, game->win, game->exit,
			o * SIZE, i * SIZE);
	else if (map[i][o] == 'P')
	{
		mlx_put_image_to_window(game->fmlx, game->win, game->pol,
			o * SIZE, i * SIZE);
		mlx_put_image_to_window(game->fmlx, game->win, game->igrok,
			o * SIZE, i * SIZE);
	}
	else if (map[i][o] == 'C')
	{
		mlx_put_image_to_window(game->fmlx, game->win, game->pol,
			o * SIZE, i * SIZE);
		mlx_put_image_to_window(game->fmlx, game->win, game->sobirat,
			o * SIZE, i * SIZE);
	}
	else
		mlx_put_image_to_window(game->fmlx, game->win, game->pol,
			o * SIZE, i * SIZE);
}

void	put_imgs(char **map, t_game *game)
{
	int	i;
	int	o;

	i = -1;
	while (map[++i])
	{
		o = -1;
		while (map[i][++o])
			put_tile(game, map, i, o);
	}
}
