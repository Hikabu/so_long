/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:51:40 by vfedorov          #+#    #+#             */
/*   Updated: 2023/07/03 13:26:39 by vfedorov         ###   ########.fr       */
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
# define KEY_RELEASE 3
# define KEY_RELEASE_MASK 1L<<1 




typedef struct s_game
{
	char			**map;
	void			*refwin;
	int				mag;
	void			*fmlx;
	void			*win;
	int				collect;
	int				shag;
	int				cnt;
	char			*cnt_step;
	int				vsego;
	int				x;
	int				y;
	char			*nmap;
	int				player;
	int				exid;
	int				img_h;
	int				img_w;
	char			*my_fil;
	char			*brick;
	void			*wall;
	void			*pol;
	void			*sobirat;
	void			*igrok;
	void			*exit;
}		t_game;

void		read_map(char *map, t_game *game);
void		give_value_struct(t_game *game, char **map);
void		check_mshape(char **map);

int			count_y(char **map);
int			count_coll(t_game *game);
void		check_walls(char **map);
void		check_char(char **map);
int			is_it_ber(char *av);

char		*new_strjoin(char *s1, char *s2);
void		free_split(char **s);
void		ft_putstr(char *s);
void		stroki(t_game *game, char *pl, char *side);

void		put_imgs(char **map, t_game *game);
void		shaw_all(t_game *game);
int			for_key(int kcode, t_game *game);
void		init_mlx(t_game *game, char *path);
void		*pxpm(char *path, t_game *game);


#endif
