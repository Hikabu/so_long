/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:49:43 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/18 19:45:35 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void opspr(t_game *game)
{
// 	char *relative_path = "./sprites/brick.xpm";
	mlx_put_image_to_window(game->fmlx, game->window.reference, game->wall.brick, 0, 0);
	
}
//printf("%p\n", game.wall.brick);