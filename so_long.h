/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/06/18 19:32:08 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<stdio.h>
# include<stddef.h>
# include<limits.h>
# include<stdlib.h>
# include<fcntl.h>
# include<sys/wait.h>
# include<libft.h>
# include<mlx.h>


typedef	struct s_wall
{
	void	*brick;
}		t_wall;

typedef	struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_window
{
	void	*reference;
	t_vector	size;
}	t_window;

typedef struct s_game
{
	void			*fmlx;

	void			*win;
	t_window		window;
	t_vector		pos;
	t_wall			wall;
}		t_game;

t_window	new_window(void *mlx, int w, int h, char *name);
char		**chek(int ac, char **av, t_game game);
void		opspr(t_game *game);

#endif
