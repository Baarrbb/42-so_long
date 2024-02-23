/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:07:47 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/headers/libft.h"
# include "../libft/headers/ft_printf.h"
# include "../libft/headers/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>

# define BOLD "\x1b[1m"
# define RED "\x1b[31m"
# define RESET "\x1b[0m"
# define IMG_SIZE 32

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		collect;
	int		player_x;
	int		player_y;
	int		acces_exit;
}	t_map;

typedef struct s_game
{
	t_map	*map;

	int		wwidth;
	int		wheight;
	void	*mlx;
	void	*win;

	void	*floor;
	void	*wall;
	void	*coll;
	void	*close;
	void	*ex;
	void	*play;
	void	*play_l;
	void	*play_r;
	void	*play_b;
	void	*zomb[8];

	int		collect;
	int		x;
	int		y;
	int		dir;
	int		count;
	int		timer;
}	t_game;

int		win_exit(t_game *game);

/*                FILE_MANAGE_BONUS.C                   */
int		check_file(char *file);

/*                INIT_MAP_BONUS.C                     */
t_map	*init_map(int fd);

/*                MAP_CHECK_BONUS.C                    */
void	check_map(t_map *map);

/*                PATH_BONUS.C                        */
void	check_path(t_map *map);

/*                INIT_GAME.C                         */
t_game	game_init(t_map *map);

/*                RENDER_IMG.C                        */
void	put_img_zomb(t_game *game, int w, int h);
void	put_img_player(t_game *game, int w, int h);
void	put_img_exit(t_game *game, int w, int h);
void	update_score(t_game *game);
void	put_img_inanim(t_game *game, int w, int h);

/*                PUT_IMG.C                           */
void	put_ptr_win(t_game *game, void *img_ptr, int w, int h);
int		put_img_win(t_game *game);

/*                MOVE.C                              */
int		move_left(t_game *game);
int		move_right(t_game *game);
int		move_down(t_game *game);
int		move_up(t_game *game);

/*                KEY_EVENT.C                         */
int		check_move(t_game *game, int x, int y);
int		get_key_event(int keycode, t_game *game);

/*                CLEAN_EXIT.C                        */
void	free_map(t_map *map);
void	handle_error(const char *s, t_map *map, int ex);
void	destroy_zomb(t_game *game);
void	destroy_img(t_game *game);
void	free_empty_line(int fd, char *line, char *map_line, t_map *map);

#endif
