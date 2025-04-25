/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_validations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:04:21 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/25 18:35:33 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_amount_objects(char **map, char object_char, int amount)
{
	int	count1;
	int	count2;
	int	rep;

	count1 = 0;
	rep = 0;
	while (map[count1])
	{
		count2 = 0;
		while (map[count1][count2] && map[count1][count2] != '\n')
		{
			if (map[count1][count2] == object_char)
				rep += 1;
			count2++;
		}
		count1++;
	}
	if (rep == amount)
		return (1);
	else
		return (0);
}

static int	search_other_objects(char **map)
{
	int	count1;
	int	count2;

	count1 = 0;
	while (map[count1])
	{
		count2 = 0;
		while (map[count1][count2] && map[count1][count2] != '\n')
		{
			if (map[count1][count2] != '0' &&
				map[count1][count2] != '1' &&
				map[count1][count2] != 'C' &&
				map[count1][count2] != 'E' &&
				map[count1][count2] != 'P')
			{
				return (0);
			}
			count2++;
		}
		count1++;
	}
	return (1);
}

void	object_validations(char **map)
{
	if (validate_amount_objects(map, 'C', 0))
	{
		write(2, "Error\nThere are no collectables in the map.\n", 44);
		free_map(map);
		exit (EXIT_FAILURE);
	}
	else if (!validate_amount_objects(map, 'E', 1))
	{
		write(2, "Error\nOnly 1 exit allowed in the map.\n", 38);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	else if (!validate_amount_objects(map, 'P', 1))
	{
		write(2, "Error\nOnly 1 player allowed in the map.\n", 40);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	else if (!search_other_objects(map))
	{
		write(2, "Error\nInvalid objects in the map.\n", 35);
		free_map(map);
		exit(EXIT_FAILURE);
	}
}
