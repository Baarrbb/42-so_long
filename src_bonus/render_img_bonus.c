/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:18:15 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img_zomb(t_game *game, int w, int h)
{
	if (game->timer >= 0 && game->timer < 2)
		put_ptr_win(game, game->zomb[0], w * IMG_SIZE, h * IMG_SIZE);
	if (game->timer >= 2 && game->timer < 4)
		put_ptr_win(game, game->zomb[1], w * IMG_SIZE, h * IMG_SIZE);
	if (game->timer >= 4 && game->timer < 6)
		put_ptr_win(game, game->zomb[2], w * IMG_SIZE, h * IMG_SIZE);
	if (game->timer >= 6 && game->timer < 8)
		put_ptr_win(game, game->zomb[3], w * IMG_SIZE, h * IMG_SIZE);
	if (game->timer >= 8 && game->timer < 10)
		put_ptr_win(game, game->zomb[4], w * IMG_SIZE, h * IMG_SIZE);
	if (game->timer >= 10 && game->timer < 12)
		put_ptr_win(game, game->zomb[5], w * IMG_SIZE, h * IMG_SIZE);
	if (game->timer >= 12 && game->timer < 14)
		put_ptr_win(game, game->zomb[6], w * IMG_SIZE, h * IMG_SIZE);
	if (game->timer >= 14 && game->timer < 16)
		put_ptr_win(game, game->zomb[7], w * IMG_SIZE, h * IMG_SIZE);
}

void	put_img_player(t_game *game, int w, int h)
{
	if (game->dir == 1)
		put_ptr_win(game, game->play, w * IMG_SIZE, h * IMG_SIZE);
	else if (game->dir == 2)
		put_ptr_win(game, game->play_b, w * IMG_SIZE, h * IMG_SIZE);
	else if (game->dir == 3)
		put_ptr_win(game, game->play_l, w * IMG_SIZE, h * IMG_SIZE);
	else if (game->dir == 4)
		put_ptr_win(game, game->play_r, w * IMG_SIZE, h * IMG_SIZE);
	else
		put_ptr_win(game, game->play, w * IMG_SIZE, h * IMG_SIZE);
}

void	put_img_exit(t_game *game, int w, int h)
{
	if (game->collect != game->map->collect)
		put_ptr_win(game, game->close, w * IMG_SIZE, h * IMG_SIZE);
	if (game->collect == game->map->collect)
		put_ptr_win(game, game->ex, w * IMG_SIZE, h * IMG_SIZE);
}

void	update_score(t_game *game)
{
	char	*mv;
	int		w;

	w = game->wheight;
	mlx_string_put(game->mlx, game->win, 42, w - 12, 0xffff99, "Move :");
	mv = ft_itoa(game->count);
	mlx_string_put(game->mlx, game->win, 93, w - 12, 0xffff99, mv);
	free(mv);
}

void	put_img_inanim(t_game *game, int w, int h)
{
	if (game->map->map[h][w] == '1')
		put_ptr_win(game, game->wall, w * IMG_SIZE, h * IMG_SIZE);
	if (game->map->map[h][w] == '0')
		put_ptr_win(game, game->floor, w * IMG_SIZE, h * IMG_SIZE);
	if (game->map->map[h][w] == 'C')
		put_ptr_win(game, game->coll, w * IMG_SIZE, h * IMG_SIZE);
	else
		update_score(game);
}
