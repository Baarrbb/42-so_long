/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:07:10 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_ptr(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->coll)
		mlx_destroy_image(game->mlx, game->coll);
	if (game->ex)
		mlx_destroy_image(game->mlx, game->ex);
	if (game->close)
		mlx_destroy_image(game->mlx, game->close);
	if (game->play)
		mlx_destroy_image(game->mlx, game->play);
}

int	win_exit(t_game *game)
{
	free_ptr(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(EXIT_SUCCESS);
	return (0);
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
