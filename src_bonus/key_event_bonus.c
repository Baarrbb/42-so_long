/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:12:59 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_move(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == '1')
		return (0);
	if (game->map->map[y][x] == 'M')
		win_exit(game);
	if (game->map->map[y][x] == 'E')
	{
		if (game->collect != game->map->collect)
			return (0);
		win_exit(game);
	}
	return (1);
}

int	get_key_event(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		win_exit(game);
	else if (keycode == XK_Down || keycode == XK_s)
		game->dir = move_down(game);
	else if (keycode == XK_Up || keycode == XK_w)
		game->dir = move_up(game);
	else if (keycode == XK_Left || keycode == XK_a)
		game->dir = move_left(game);
	else if (keycode == XK_Right || keycode == XK_d)
		game->dir = move_right(game);
	else
		return (0);
	if (game->dir)
		game->count++;
	return (0);
}
