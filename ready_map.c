/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:44:19 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/03 13:23:01 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_mshape(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[++i])
	{
		if (len != ft_strlen(map[i]))
		{
			write(2, "map not in the good shape\n", 26);
			exit(1);
		}
	}
}

void	check_wall(char *wall)
{
	int	i;

	i = 0;
	while (wall[i] && wall[i] == '1')
		i++;
	if (wall[i])
	{
		write(2, "where is a wall?\n", 17);
		exit(1);
	}
}

void	check_walls(char **map)
{
	int	i;

	i = 0;
	check_wall(map[0]);
	if (map[i])
	{
		i = 0;
		while (map[i] && map[i + 1])
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			{
				write(2, "U miss wall somwhere\n", 21);
				exit(1);
			}
			i++;
		}
		check_wall(map[i]);
	}
}

void	check_chars(char map, t_game *game)
{
	if (map != '0' && map != '1' && map != 'E'
		&& map != 'C' && map != 'P')
	{
		write(2, "does not exist\n", 15);
		exit (1);
	}
	if (map == 'P' && !game->player)
	{
		write(2, "wrong number of Players\n", 24);
		exit(1);
	}
	if (map == 'P' && game->player)
		game->player = 0;
	if (map == 'E' && game->exid)
		game->exid = 0;
	if (map == 'C' && game->cnt)
		game->cnt = 0;
}

void	check_char(char **map)
{
	t_game	game;
	int		i;
	int		j;

	i = -1;
	game.player = 1;
	game.exid = 1;
	game.cnt = 1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			check_chars(map[i][j], &game);
	}
	if (game.player || game.exid || game.cnt)
	{
		write (2, "U miss very important thing: exit/player/cnt\n", 45);
		exit(1);
	}
}
