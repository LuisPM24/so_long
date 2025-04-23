/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:12:28 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/23 11:57:06 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_tile(mlx_t *mlx, t_tile *tile, const char *file_path)
{
	tile->texture = mlx_load_png(file_path);
	if (!tile->texture)
	{
		ft_printf("Error loading PNG: %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	tile->img = mlx_texture_to_image(mlx, tile->texture);
	if (!tile->img)
	{
		ft_printf("Error converting texture to image: %s\n", file_path);
		exit(EXIT_FAILURE);
	}
}

void	load_tiles(t_game *game)
{
	load_tile(game->mlx, &game->tile_floor, "textures/floor.png");
	load_tile(game->mlx, &game->tile_wall, "textures/wall.png");
	load_tile(game->mlx, &game->tile_player, "textures/player_front.png");
	load_tile(game->mlx, &game->tile_exit, "textures/exit.png");
	load_tile(game->mlx, &game->tile_collect, "textures/collectible.png");
}
