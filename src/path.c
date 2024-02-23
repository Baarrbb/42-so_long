/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:35:17 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_temp(t_map *tmp)
{
	int	i;

	i = 0;
	while (tmp->map[i])
	{
		free(tmp->map[i]);
		i++;
	}
	free(tmp->map);
}

static int	dfs(t_map *temp, int y, int x)
{
	if (temp->map[y][x] == '1')
		return (0);
	if (temp->map[y][x] == 'C')
		temp->collect--;
	if (temp->map[y][x] == 'E')
	{
		temp->acces_exit = 1;
		return (0);
	}
	temp->map[y][x] = '1';
	if (dfs(temp, y - 1, x))
		return (1);
	if (dfs(temp, y + 1, x))
		return (1);
	if (dfs(temp, y, x + 1))
		return (1);
	if (dfs(temp, y, x - 1))
		return (1);
	return (0);
}

static void	exit_problem(char *str, t_map tmp, t_map *map)
{
	free_temp(&tmp);
	handle_error(str, map, 1);
}

void	check_path(t_map *map)
{
	t_map	temp;
	int		i;

	temp.height = map->height;
	temp.width = map->width;
	temp.collect = map->collect;
	temp.player_x = map->player_x;
	temp.player_y = map->player_y;
	temp.acces_exit = 0;
	temp.map = (char **)ft_calloc((temp.height + 1), sizeof(char *));
	if (!temp.map)
		handle_error("Malloc problem during check path", map, 1);
	temp.map[temp.height] = NULL;
	i = -1;
	while (++i < temp.height)
	{
		temp.map[i] = ft_strdup(map->map[i]);
		if (!temp.map[i])
			exit_problem("Malloc error", temp, map);
	}
	dfs(&temp, temp.player_y, temp.player_x);
	if (!(temp.acces_exit == 1 && temp.collect == 0))
		exit_problem("No valid path", temp, map);
	free_temp(&temp);
}
