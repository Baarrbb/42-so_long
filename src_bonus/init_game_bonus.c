/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:53:35 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*img_init_ptr(t_game *game, char *path)
{
	void	*ptr;
	int		i;
	int		j;

	i = IMG_SIZE;
	j = IMG_SIZE;
	ptr = mlx_xpm_file_to_image(game->mlx, path, &i, &j);
	if (!ptr)
	{
		destroy_img(game);
		destroy_zomb(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		handle_error("Malloc problem ptr img", game->map, 1);
	}
	return (ptr);
}

static void	init_zomb(t_game *game)
{
	game->zomb[0] = img_init_ptr(game, "sprites_bonus/a_l/a1.xpm");
	game->zomb[1] = img_init_ptr(game, "sprites_bonus/a_l/a2.xpm");
	game->zomb[2] = img_init_ptr(game, "sprites_bonus/a_l/a3.xpm");
	game->zomb[3] = img_init_ptr(game, "sprites_bonus/a_l/a4.xpm");
	game->zomb[4] = img_init_ptr(game, "sprites_bonus/a_l/a5.xpm");
	game->zomb[5] = img_init_ptr(game, "sprites_bonus/a_l/a6.xpm");
	game->zomb[6] = img_init_ptr(game, "sprites_bonus/a_l/a7.xpm");
	game->zomb[7] = img_init_ptr(game, "sprites_bonus/a_l/a8.xpm");
}

static void	init_img_game(t_game *game)
{
	game->floor = img_init_ptr(game, "sprites_bonus/floor.xpm");
	game->wall = img_init_ptr(game, "sprites_bonus/wall.xpm");
	game->coll = img_init_ptr(game, "sprites_bonus/key.xpm");
	game->ex = img_init_ptr(game, "sprites_bonus/door.xpm");
	game->close = img_init_ptr(game, "sprites_bonus/close.xpm");
	game->play = img_init_ptr(game, "sprites_bonus/perso.xpm");
	game->play_l = img_init_ptr(game, "sprites_bonus/left.xpm");
	game->play_r = img_init_ptr(game, "sprites_bonus/right.xpm");
	game->play_b = img_init_ptr(game, "sprites_bonus/dos.xpm");
}

static void	player_pos(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->map->height)
	{
		w = -1;
		while (++w < game->map->width)
		{
			if (game->map->map[h][w] == 'P')
			{
				game->x = w;
				game->y = h;
				break ;
			}
		}
	}
}

t_game	game_init(t_map *map)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.map = map;
	game.wwidth = map->width * IMG_SIZE;
	game.wheight = map->height * IMG_SIZE;
	game.mlx = mlx_init();
	if (!game.mlx)
		handle_error("MLX INIT ERROR", map, 1);
	game.win = mlx_new_window(game.mlx, game.wwidth, game.wheight, "Game");
	if (!game.win)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		handle_error("Mlx new window error", map, 1);
	}
	game.dir = 1;
	player_pos(&game);
	init_img_game(&game);
	init_zomb(&game);
	return (game);
}
