/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:51:39 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_ptr_win(t_game *game, void *img_ptr, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, w, h);
}

static void	put_img_win_bis(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->map->height)
	{
		w = -1;
		while (++w < game->map->width)
		{
			if (game->map->map[h][w] == '1')
				put_ptr_win(game, game->wall, w * IMG_SIZE, h * IMG_SIZE);
			if (game->map->map[h][w] == '0')
				put_ptr_win(game, game->floor, w * IMG_SIZE, h * IMG_SIZE);
			if (game->map->map[h][w] == 'C')
				put_ptr_win(game, game->coll, w * IMG_SIZE, h * IMG_SIZE);
		}
	}
}

void	put_img_win(t_game *game)
{
	int	h;
	int	w;

	put_img_win_bis(game);
	h = -1;
	while (++h < game->map->height)
	{
		w = -1;
		while (++w < game->map->width)
		{
			if (game->map->map[h][w] == 'E'
				&& game->collect != game->map->collect)
				put_ptr_win(game, game->close, w * IMG_SIZE, h * IMG_SIZE);
			if (game->map->map[h][w] == 'E'
				&& game->collect == game->map->collect)
				put_ptr_win(game, game->ex, w * IMG_SIZE, h * IMG_SIZE);
			if (game->map->map[h][w] == 'P')
			{
				put_ptr_win(game, game->play, w * IMG_SIZE, h * IMG_SIZE);
				game->x = w;
				game->y = h;
			}
		}
	}
}
