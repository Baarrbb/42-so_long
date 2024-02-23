/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:53:35 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		free_ptr(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		handle_error("Malloc problem ptr img", game->map, 1);
	}
	return (ptr);
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
	game.floor = img_init_ptr(&game, "textures/floor.xpm");
	game.wall = img_init_ptr(&game, "textures/wall.xpm");
	game.coll = img_init_ptr(&game, "textures/key.xpm");
	game.ex = img_init_ptr(&game, "textures/door.xpm");
	game.close = img_init_ptr(&game, "textures/close.xpm");
	game.play = img_init_ptr(&game, "textures/perso.xpm");
	return (game);
}
