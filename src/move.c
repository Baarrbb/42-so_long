/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:42:21 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_y(t_game *game, int x, int y, int move)
{
	if (game->map->map[move][x] == '1')
		return (0);
	if (game->map->map[move][x] == 'E')
	{
		if (game->collect != game->map->collect)
			return (0);
		win_exit(game);
	}
	if (game->map->map[move][x] == 'C')
	{
		game->collect++;
		game->map->map[y][x] = '0';
		game->map->map[move][x] = 'P';
		return (1);
	}
	if (game->map->map[move][x] == '0')
	{
		game->map->map[y][x] = '0';
		game->map->map[move][x] = 'P';
		return (1);
	}
	return (0);
}

static int	move_x(t_game *game, int x, int y, int move)
{
	if (game->map->map[y][move] == '1')
		return (0);
	if (game->map->map[y][move] == 'E')
	{
		if (game->collect != game->map->collect)
			return (0);
		win_exit(game);
	}
	if (game->map->map[y][move] == 'C')
	{
		game->collect++;
		game->map->map[y][x] = '0';
		game->map->map[y][move] = 'P';
		return (1);
	}
	if (game->map->map[y][move] == '0')
	{
		game->map->map[y][x] = '0';
		game->map->map[y][move] = 'P';
		return (1);
	}
	return (0);
}

int	get_key_event(int keycode, t_game *game)
{
	int	ok;

	ok = 0;
	if (keycode == XK_Escape)
		win_exit(game);
	else if (keycode == XK_Down || keycode == XK_s)
		ok = move_y(game, game->x, game->y, game->y + 1);
	else if (keycode == XK_Up || keycode == XK_w)
		ok = move_y(game, game->x, game->y, game->y - 1);
	else if (keycode == XK_Left || keycode == XK_a)
		ok = move_x(game, game->x, game->y, game->x - 1);
	else if (keycode == XK_Right || keycode == XK_d)
		ok = move_x(game, game->x, game->y, game->x + 1);
	else
		return (0);
	if (ok)
	{
		put_img_win(game);
		game->count++;
		ft_printf("Move : %d\n", game->count);
	}
	return (0);
}
