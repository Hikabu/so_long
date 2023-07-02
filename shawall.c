/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shawall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 02:54:06 by valeriafedo       #+#    #+#             */
/*   Updated: 2023/06/29 22:11:24 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_me_map(char **map, char *my_file, t_game *game)
{
	give_value_struct(game, map);	
	game->my_fil = my_file;
	dprintf(2, "Screen Dimensions: %d %d\n", game->x * 64, game->y * 64);
	game->win = mlx_new_window
			(game->fmlx, game->x * 64, game->y * 64, "So Long");
	put_imgs(map, game);
	mlx_loop(game->fmlx);
	
}


void	shaw_all(char *map, t_game *game)
{
	int		fd;
	char	*line;
	char	*join;
	char	**split;

	join = NULL;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		join = new_strjoin(join, line);
		line =get_next_line(fd);
	}
	split = ft_split(join, '\n');
	free(join);
	show_me_map(split, map, game);
	free_split(split);
	close(fd);
}
