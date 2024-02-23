/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:59:40 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**get_map(int fd, t_map *s_map)
{
	char	*map_line;
	char	*line;
	char	**map;

	map_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "\n", ft_strlen(line)))
			free_empty_line(fd, line, map_line, s_map);
		map_line = ft_strjoin(map_line, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(map_line, '\n');
	free(map_line);
	if (!map)
		handle_error("Problem collect the map", s_map, 1);
	return (map);
}

static int	count_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	count_column(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

static void	player_pos(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				return ;
			}
		}
	}
}

t_map	*init_map(int fd)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		handle_error("Malloc error on the map", 0, 1);
	map->map = get_map(fd, map);
	map->height = count_line(map->map);
	map->width = count_column(map->map);
	if (map->height == map->width)
		handle_error("The map isn't rectangular", map, 1);
	map->collect = 0;
	player_pos(map);
	map->acces_exit = 0;
	return (map);
}
