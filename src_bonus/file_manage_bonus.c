/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:59:26 by marvin            #+#    #+#             */
/*   Updated: 2024/02/23 17:50:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		handle_error(strerror(errno), 0, 1);
	return (fd);
}

int	check_file(char *file)
{
	char	*ext;
	size_t	len;

	ext = ft_strrchr(file, '.');
	len = ft_strlen(ext);
	if (len < 4)
		len = 4;
	if (!ext || ft_strncmp(ext, ".ber", len) != 0)
		handle_error("Map has to end with \".ber\" extension", 0, 1);
	return (open_file(file));
}
