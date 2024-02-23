/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:59:16 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	args_manag(char	*prog)
{
	ft_printf(RED);
	ft_printf(BOLD);
	ft_printf("[USAGE]\n");
	ft_printf(RESET);
	ft_printf("%s <maps.ber>\n", prog);
	handle_error(strerror(EINVAL), 0, 1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	t_game	game;

	if (argc != 2)
		args_manag(argv[0]);
	fd = check_file(argv[1]);
	map = init_map(fd);
	check_map(map);
	game = game_init(map);
	put_img_win(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, get_key_event, &game);
	mlx_hook(game.win, DestroyNotify, 0, win_exit, &game);
	mlx_loop(game.mlx);
	free_map(map);
	return (0);
}
