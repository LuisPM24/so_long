/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:17:47 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/10 17:15:26 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_rows(char *map_arg)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(map_arg, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**get_map(char *map_arg)
{
	char	*line;
	char	**map;
	int		fd;
	int		count;

	count = 0;
	map = malloc(sizeof(char *) * (count_rows(map_arg) + 1));
	if (!map)
		return (NULL);
	fd = open(map_arg, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[count] = line;
		count++;
		line = get_next_line(fd);
	}
	map[count] = NULL;
	close(fd);
	return (map);
}

void	print_map(char **map)
{
	int		count;

	count = 0;
	while (map[count])
	{
		ft_printf("%s", map[count]);
		count++;
	}
}
