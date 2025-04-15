/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:08:18 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/15 15:35:26 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, char **map)
{
	int	rows;
	int	columns;

	rows = 0;
	columns = ft_strlen(map[0]);
	while (map[rows])
		rows++;
	game->map = map;
	game->map_width = cols;
	game->map_height = rows;
	game->moves = 0;
	game->collect_amount = 0;
	game->mlx = mlx_init(cols * 16, rows * 16, "so_long", false);
	if (!game->mlx)
	{
		write(2, "Error\n", 6);
		write(2, "It was impossible to open the game\n"i, 34);
	}
}
