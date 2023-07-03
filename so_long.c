/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:49:43 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/03 13:26:56 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*where_pl(char **map)
{
	char	*str;
	int		i;

	i = 0;
	while (map[i])
	{
		str = map[i];
		while (*str)
		{
			if (*str == 'P')
				return (str);
			str++;
		}
		i++;
	}
	return (0);
}

void	move(t_game *game, char *pl, char *storon)
{
	if (*storon != '1')
	{
		if (*storon == 'E')
		{
			if (game->collect != game->vsego)
				return ;
			else
				exit (0);
		}
		if (*storon == 'C')
			game->collect++;
		*pl = '0';
		*storon = 'P';
		game->shag++;
		game->cnt_step = ft_itoa(game->shag);
		ft_putstr(game->cnt_step);
		ft_putstr("\n");
		if (*game->cnt_step != '0')
			free(game->cnt_step);
	}
}

char	*only_up(t_game *game)
{
	char	*up;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (game->map[y][x] != 'P')
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != 'P')
		{
			x++;
			if (game->map[y][x] == 'P')
				break ;
		}
		if (game->map[y][x] == 'P')
			break ;
		y++;
	}
	up = &game->map[y - 1][x];
	return (up);
}

char	*only_down(t_game *game)
{
	char	*down;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (game->map[y][x] != 'P')
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != 'P')
		{
			x++;
			if (game->map[y][x] == 'P')
				break ;
		}
		if (game->map[y][x] == 'P')
			break ;
		y++;
	}
	down = &game->map[y + 1][x];
	return (down);
}

int	for_key(int keycode, t_game *game)
{
	char	*pl;
	char	*r;
	char	*l;
	char	*up;
	char	*down;

	up = only_up(game);
	down = only_down(game);
	pl = where_pl(game->map);
	r = pl + 1;
	l = pl - 1;
	if (keycode == 53)
	{
		mlx_destroy_image(game->fmlx, game->win);
		exit(0);
	}
	else if (keycode == 2)
		stroki(game, pl, r);
	else if (keycode == 0)
		stroki(game, pl, l);
	else if (keycode == 13)
		stroki(game, pl, up);
	else if (keycode == 1)
		stroki(game, pl, down);
	return (0);
}
