/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:59:34 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) != map->width)
			handle_error("The map isn't rectangular", map, 1);
		i++;
	}
}

static void	check_surround_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] == '1' && map->map[map->height - 1][i] == '1')
		i++;
	if (i != map->width)
		handle_error("Map not surrounded by walls", map, 1);
	if (map->map[1])
	{
		i = 1;
		while (map->map[i][0] == '1' && map->map[i][map->width - 1] == '1'
			&& i < map->height - 1)
			i++;
		if (i != map->height - 1)
			handle_error("Map not surrounded by walls", map, 1);
	}
}

static void	check_nb_char(int exit_nb, int start_nb, int collect_nb, t_map *map)
{
	if (exit_nb > 1 || exit_nb == 0)
		handle_error("Too much or missing an exit on the map", map, 1);
	if (start_nb > 1 || start_nb == 0)
		handle_error("Too much or missing a start on the map", map, 1);
	if (collect_nb == 0)
		handle_error("Missing collectible on the map", map, 1);
	map->collect = collect_nb;
}

static void	count_char(t_map *map)
{
	int	exit_nb;
	int	collect_nb;
	int	start_nb;
	int	i;
	int	j;

	exit_nb = 0;
	collect_nb = 0;
	start_nb = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
				collect_nb++;
			if (map->map[i][j] == 'E')
				exit_nb++;
			if (map->map[i][j] == 'P')
				start_nb++;
		}
	}
	check_nb_char(exit_nb, start_nb, collect_nb, map);
}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	check_rectangular(map);
	check_surround_map(map);
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (!ft_strchr("01CEP", map->map[i][j]))
				handle_error("Wrong charactere in the map", map, 1);
		}
	}
	count_char(map);
	check_path(map);
}
