/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cre_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:13:49 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/18 16:22:16 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_close()
{
    exit(0);
}

t_window	new_window(void *mlx, int w, int h, char *name)
{
    t_window    window;

    window.reference = mlx_new_window(mlx, w, h, name);
    window.size.x = w;
    window.size.y = h;
    
    //mlx_hook(window.reference, 17, 0, ft_close, 0);
    return (window);
}