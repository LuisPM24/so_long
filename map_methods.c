/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:17:47 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/23 19:28:32 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_amount_tile(t_game *game, char tile)
{
	int		row;
	int		column;
	int		amount;
	char	**map;

	map = game->map;
	row = 0;
	amount = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == tile)
				amount++;
			column++;
		}
		row++;
	}
	return (amount);
}

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

static void	line_read(int fd, char *line, char **map)
{
	int		count;

	count = 0;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[count] = line;
		count++;
		line = get_next_line(fd);
	}
	map[count] = NULL;
}

char	**get_map(char *map_arg)
{
	char	**map;
	char	*line;
	int		fd;

	map = malloc(sizeof(char *) * (count_rows(map_arg) + 1));
	if (!map)
		return (NULL);
	fd = open(map_arg, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	line = get_next_line(fd);
	if (!line)
	{
		free(map);
		close(fd);
		return (NULL);
	}
	line_read(fd, line, map);
	close(fd);
	return (map);
}

void	print_map(char **map)
{
	int		count;

	count = 0;
	while (map[count])
	{
		ft_printf("%s\n", map[count]);
		count++;
	}
}
