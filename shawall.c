/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shawall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:44:07 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/03 13:23:57 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	for_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->win, event, mask, f, game);
}

void	init_mlx(t_game *game, char *path)
{
	(void)path;
	for_hook(game, KEY_RELEASE, KEY_RELEASE_MASK, for_key);
}

void	show_me_map(char **map, char *my_file, t_game *game)
{
	give_value_struct(game, map);
	game->my_fil = my_file;
	dprintf(2, "Screen Dimensions: %d %d\n", game->x * 64, game->y * 64);
	game->win = mlx_new_window
		(game->fmlx, game->x * 64, game->y * 64, "So Long");
	put_imgs(map, game);
	init_mlx(game, *map);
	mlx_loop(game->fmlx);
}

void	shaw_all(t_game *game)
{
	int		fd;
	char	*line;
	char	*join;
	char	**split;

	join = NULL;
	fd = open(game->nmap, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		join = new_strjoin(join, line);
		line = get_next_line(fd);
	}
	split = ft_split(join, '\n');
	free(join);
	show_me_map(split, game->nmap, game);
	free_split(split);
	close(fd);
}
