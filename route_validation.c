/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:46:59 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/12 11:21:59 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int row, int column)
{
	if (row < 0 || column < 0 || !map[row] || !map[row][column])
		return ;
	if (map[row][column] == '1' || map[row][column] == 'F')
		return ;
	map[row][column] = 'F';
	flood_fill(map, row + 1, column);
	flood_fill(map, row - 1, column);
	flood_fill(map, row, column + 1);
	flood_fill(map, row, column - 1);
}

static char	**flood_fill_map(char **map)
{
	int		count;
	char	**map_copy;

	count = 0;
	while (map[count])
		count++;
	map_copy = malloc(sizeof(char *) * (count + 1));
	if (!map_copy)
		return (NULL);
	count = 0;
	while (map[count])
	{
		map_copy[count] = ft_strdup(map[count]);
		count++;
	}
	map_copy[count] = NULL;
	return (map_copy);
}

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
	return (NULL);
}

static int	verify_route(char **map)
{
	int		row;
	int		column;
	int		*player_pos;
	char	**map_cpy;

	row = 0;
	map_cpy = flood_fill_map(map);
	player_pos = get_player_position(map_cpy);
	flood_fill(map_cpy, player_pos[0], player_pos[1]);
	while (map_cpy[row])
	{
		column = 0;
		while (map_cpy[row][column])
		{
			if (map_cpy[row][column] == 'C' || map_cpy[row][column] == 'E')
				return (0);
			column++;
		}
		row++;
	}
	print_map(map_cpy);
	return (1);
}

void	route_validation(char **map)
{
	if (!verify_route(map))
	{
		write(2, "Error\nThere is not a valid route.", 33);
		exit (1);
	}
}
