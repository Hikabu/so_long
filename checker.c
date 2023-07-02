/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:32:38 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/02 00:17:36 by valeriafedo      ###   ########.fr       */
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
	// sprite_struct(game);
	game->y = count_y(map);
	dprintf(2, "Height: %d\n", game->x);
	game->fmlx = mlx_init();
	game->img_w = 64;
	game->img_h = 64;
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
	// int i = 0;
	// while (map[i])
	// {
	// 	dprintf(1, "%s\n", map[i]);
	// 	i++;
	// }
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
	// int i = 0;
	// while (game->map[i])
	// {
	// 	dprintf(1, "%s\n", game->map[i]);
	// 	i++;
	// }
	free_split(split);
	close(fd);
}
