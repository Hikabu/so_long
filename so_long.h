/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/01 16:53:21 by valeriafedo      ###   ########.fr       */
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
# include"./libft/libft.h"
# include"./mlx/mlx.h"
# include"get_next_line.h" 

# define WALL "./sprites/topcentr.xpm"
# define BRICK "./sprites/brick.xpm"
# define SIZE 64
# define PLAYER "./sprites/death.xpm"
# define COLLECT "./sprites/collect.xpm"
# define EXIT "./sprites/exit.xpm"




typedef struct s_game
{
	char			**map;
	void			*refwin;
	int				mag;
	void			*fmlx;
	void			*win;
	int				x;
	int				y;
	char			*nmap;
	int				player;
	int				cnt;
	int				exid;
	int				img_h;
	int				img_w;
	char			*my_fil;
	char			*brick;
}		t_game;

//t_window	new_window(void *mlx, int w, int h, char *name);
void		read_map(char *map, t_game *game);
void		opspr(t_game *game, char *pic, int x, int y);
t_game		new_window(void *mlx, int w, int h, char *name);
void		show_map(t_game *game, int x, int y);
void		draw_window(t_game *game);
void		give_value_struct(t_game *game, char **map);
void		check_mshape(char **map);

int			count_y(char **map);
// int			check_simb(**map);
void		check_walls(char **map);
void		check_char(char **map);
void		shaaw_all(char **av);
int			is_it_ber(char *av);

char		*new_strjoin(char *s1, char *s2);
void		free_split(char **s);

void		put_imgs(char **map, t_game *game);
void		shaw_all(char *map, t_game *game);
// void		sprite_struct(t_game *game);
int			for_key(int kcode, t_game *game);


#endif
