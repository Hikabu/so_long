/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:32:38 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/03 13:12:57 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	give_value_struct(t_game *game, char **map)
{
	game->x = ft_strlen(map[0]);
	game->shag = 0;
	game->collect = 0;
	game->vsego = count_coll(game);
	game->y = count_y(map);
	game->fmlx = mlx_init();
	game->img_w = 64;
	game->img_h = 64;
	game->wall = pxpm(WALL, game);
	game->pol = pxpm(BRICK, game);
	game->sobirat = pxpm(COLLECT, game);
	game->igrok = pxpm(PLAYER, game);
	game->exit = pxpm(EXIT, game);
}

int	is_it_ber(char *av)
{
	char	*ber;
	char	*ret;

	ber = 0;
	ber = &av[0];
	ret = ft_strchr(ber, '.');
	if (ret == 0)
		return (0);
	if ((ft_strncmp(".ber", ret, 5)) == 0)
		return (1);
	return (0);
}

void	is_valid(char **map)
{
	check_mshape(map);
	check_walls(map);
	check_char(map);
}

void	read_map(char *map, t_game *game)
{
	int		fd;
	char	*line;
	char	*join;
	char	**split;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		write(2, "file doesn't exist\n", 19);
	line = get_next_line(fd);
	if (line == NULL || line[0] == '\n')
	{
		write(2, "empty file\n", 11);
		exit(1);
	}
	join = NULL;
	while (line)
	{		
		join = new_strjoin(join, line);
		line = get_next_line(fd);
	}
	split = ft_split(join, '\n');
	free(join);
	is_valid(split);
	game->map = split;
	close(fd);
}
