/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:53:24 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/10 17:53:33 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(char **map)
{
	int	width;
	int	len;
	int	count;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	if (map[0][width - 1] == '\n')
		width--;
	count = 1;
	while (map[count])
	{
		len = ft_strlen(map[count]);
		if (map[count][len - 1] == '\n')
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
		write(2, "Error\nThe map is not rectangular.", 33);
		exit (1);
	}
	else if (!is_closed(map))
	{
		write(2, "Error\nThe map borders are not closed.", 37);
		exit (1);
	}
}
