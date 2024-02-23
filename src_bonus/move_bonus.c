/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 00:42:21 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_left(t_game *game)
{
	if (!check_move(game, game->x - 1, game->y))
		return (0);
	if (game->map->map[game->y][game->x - 1] == 'C')
	{
		game->collect++;
		game->map->map[game->y][game->x] = '0';
		game->map->map[game->y][game->x - 1] = 'P';
	}
	if (game->map->map[game->y][game->x - 1] == '0')
	{
		game->map->map[game->y][game->x] = '0';
		game->map->map[game->y][game->x - 1] = 'P';
	}
	game->x = game->x - 1;
	game->y = game->y;
	return (3);
}

int	move_right(t_game *game)
{
	if (!check_move(game, game->x + 1, game->y))
		return (0);
	if (game->map->map[game->y][game->x + 1] == 'C')
	{
		game->collect++;
		game->map->map[game->y][game->x] = '0';
		game->map->map[game->y][game->x + 1] = 'P';
	}
	if (game->map->map[game->y][game->x + 1] == '0')
	{
		game->map->map[game->y][game->x] = '0';
		game->map->map[game->y][game->x + 1] = 'P';
	}
	game->x = game->x + 1;
	game->y = game->y;
	return (4);
}

int	move_down(t_game *game)
{
	if (!check_move(game, game->x, game->y + 1))
		return (0);
	if (game->map->map[game->y + 1][game->x] == 'C')
	{
		game->collect++;
		game->map->map[game->y][game->x] = '0';
		game->map->map[game->y + 1][game->x] = 'P';
	}
	if (game->map->map[game->y + 1][game->x] == '0')
	{
		game->map->map[game->y][game->x] = '0';
		game->map->map[game->y + 1][game->x] = 'P';
	}
	game->x = game->x;
	game->y = game->y + 1;
	return (1);
}

int	move_up(t_game *game)
{
	if (!check_move(game, game->x, game->y - 1))
		return (0);
	if (game->map->map[game->y - 1][game->x] == 'C')
	{
		game->collect++;
		game->map->map[game->y][game->x] = '0';
		game->map->map[game->y - 1][game->x] = 'P';
	}
	if (game->map->map[game->y - 1][game->x] == '0')
	{
		game->map->map[game->y][game->x] = '0';
		game->map->map[game->y - 1][game->x] = 'P';
	}
	game->x = game->x;
	game->y = game->y - 1;
	return (2);
}
