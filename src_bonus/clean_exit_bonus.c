/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:10 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map)
		{
			while (map->map[i])
			{
				free(map->map[i]);
				i++;
			}
			free(map->map);
		}
		free(map);
	}
}

void	handle_error(const char *s, t_map *map, int ex)
{
	ft_printf(RED);
	ft_printf(BOLD);
	ft_printf("[Error]\n");
	ft_printf(RESET);
	if (s)
		ft_printf("%s\n", s);
	if (map)
		free_map(map);
	if (ex)
		exit(EXIT_FAILURE);
}

void	destroy_zomb(t_game *game)
{
	if (game->zomb[0])
		mlx_destroy_image(game->mlx, game->zomb[0]);
	if (game->zomb[1])
		mlx_destroy_image(game->mlx, game->zomb[1]);
	if (game->zomb[2])
		mlx_destroy_image(game->mlx, game->zomb[2]);
	if (game->zomb[3])
		mlx_destroy_image(game->mlx, game->zomb[3]);
	if (game->zomb[4])
		mlx_destroy_image(game->mlx, game->zomb[4]);
	if (game->zomb[5])
		mlx_destroy_image(game->mlx, game->zomb[5]);
	if (game->zomb[6])
		mlx_destroy_image(game->mlx, game->zomb[6]);
	if (game->zomb[7])
		mlx_destroy_image(game->mlx, game->zomb[7]);
}

void	destroy_img(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->coll)
		mlx_destroy_image(game->mlx, game->coll);
	if (game->close)
		mlx_destroy_image(game->mlx, game->close);
	if (game->ex)
		mlx_destroy_image(game->mlx, game->ex);
	if (game->play)
		mlx_destroy_image(game->mlx, game->play);
	if (game->play_l)
		mlx_destroy_image(game->mlx, game->play_l);
	if (game->play_r)
		mlx_destroy_image(game->mlx, game->play_r);
	if (game->play_b)
		mlx_destroy_image(game->mlx, game->play_b);
}

void	free_empty_line(int fd, char *line, char *map_line, t_map *map)
{
	if (line)
		free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	if (map_line)
		free(map_line);
	handle_error("Empty line on the map", map, 1);
}
