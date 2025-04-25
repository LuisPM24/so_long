/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:53:24 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/25 18:45:17 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_player_position(char **map)
{
	int	*player_pos;
	int	row;
	int	column;

	player_pos = malloc(2 * sizeof(int));
	if (!player_pos)
		return (NULL);
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == 'P')
			{
				player_pos[0] = row;
				player_pos[1] = column;
				return (player_pos);
			}
			column++;
		}
		row++;
	}
	free(player_pos);
	return (NULL);
}

void	free_map(char **map)
{
	int	count;

	count = 0;
	if (map)
	{
		while (map[count])
		{
			free(map[count]);
			count++;
		}
		free(map);
	}
}

static int	is_rectangular(char **map)
{
	int	width;
	int	len;
	int	count;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	if (width > 0 && map[0][width - 1] == '\n')
		width--;
	count = 1;
	while (map[count])
	{
		len = ft_strlen(map[count]);
		if (len > 0 && map[count][len - 1] == '\n')
			len--;
		if (len != width)
			return (0);
		count++;
	}
	return (1);
}

static int	is_closed(char **map)
{
	int	row;
	int	column;
	int	width;

	row = 0;
	width = ft_strlen(map[0]);
	while (map[row])
	{
		column = 0;
		while (map[row][column] && map[row][column] != '\n')
		{
			if ((row == 0 || column == 0 || map[row][column + 1] == '\n'
				|| column == width - 1 || map[row + 1] == NULL))
			{
				if (map[row][column] != '1')
					return (0);
			}
			column++;
		}
		row++;
	}
	return (1);
}

void	map_validations(char **map)
{
	if (!is_rectangular(map))
	{
		write(2, "Error\nThe map is not rectangular.\n", 34);
		free_map(map);
		exit (EXIT_FAILURE);
	}
	else if (!is_closed(map))
	{
		write(2, "Error\nThe map borders are not closed.\n", 38);
		free_map(map);
		exit (EXIT_FAILURE);
	}
}
