/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:51:39 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_ptr_win(t_game *game, void *img_ptr, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, w, h);
}

int	put_img_win(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->map->height)
	{
		w = -1;
		while (++w < game->map->width)
		{
			if (ft_strchr("01C.", game->map->map[h][w]))
				put_img_inanim(game, w, h);
			if (h == game->y && w == game->x)
				put_img_player(game, w, h);
			if (game->map->map[h][w] == 'E')
				put_img_exit(game, w, h);
			if (game->map->map[h][w] == 'M')
				put_img_zomb(game, w, h);
		}
	}
	usleep(50000);
	game->timer++;
	if (game->timer == 16)
		game->timer = 0;
	return (0);
}
