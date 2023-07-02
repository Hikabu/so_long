/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:49:43 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/02 00:13:07 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char	*where_pl(char **map)
{
	char	*str;
	int		i;
	
	i = 0;
	while(map[i])
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

void	check(t_game *game, char *pl, char *kuda)
{
	if (*kuda != '1')
	{
		if (*kuda == 'C')
			game->cnt++;
		*pl = '0';
		*kuda = 'P';
	}
}
void	kmove(int kcode, t_game *game)
{
	char	*pl;
	char	*r;
	char	*l;
	// char	*up;
	// char	*down;

	pl = where_pl(game->map);
	r = pl + 1;
	l = pl - 1;
	// up = fi_up(game, );
	// down = fi_down(game, );
	if (kcode == 2)
		check(game, pl, r);
	if (kcode == 0)
		check(game, pl, l);
	// if (kcode == 13)
	// 	check(game, pl, up);
	// if (kcode == 1)
	// 	check(game, pl, down);
}


int	for_key(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_image(game->fmlx, game->win);
		exit(0);
	}
	// else if (keycode == 0)
	// 	move_left(game);
	// else if (keycode == 2)
	// 	move_right(game);
	// else if(keycode == 13)
	// 	move_up(game);
	// else if (keycode == 1)
	// 	move_down(game);
	// return (0);
		
	// if (kcode == 13 || kcode == 0 || kcode == 1 || kcode == 2)
	// {
	// 	kmove(kcode, game);
	// 	mlx_clear_window(game->fmlx, game->win);
	// }
	return (0);
}
