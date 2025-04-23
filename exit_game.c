/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:07:58 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/23 18:58:23 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_tiles(t_game *game)
{
	int	count;

	count = 0;
	if (game->tile_floor.img)
		mlx_delete_image(game->mlx, game->tile_floor.img);
	if (game->tile_wall.img)
		mlx_delete_image(game->mlx, game->tile_wall.img);
	if (game->tile_player.img)
		mlx_delete_image(game->mlx, game->tile_player.img);
	if (game->tile_exit.img)
		mlx_delete_image(game->mlx, game->tile_exit.img);
	if (game->tile_collect.img)
		mlx_delete_image(game->mlx, game->tile_collect.img);
	while (count < game->collect_amount)
	{
		if (game->collect[count].img)
			mlx_delete_image(game->mlx, game->collect[count].img);
		count++;
	}
}

static void	delete_textures(t_game *game)
{
	free(game->collect);
	mlx_delete_texture(game->tile_floor.texture);
	mlx_delete_texture(game->tile_wall.texture);
	mlx_delete_texture(game->tile_player.texture);
	mlx_delete_texture(game->tile_exit.texture);
	mlx_delete_texture(game->tile_collect.texture);
}

void	exit_game(void *param)
{
	int		count;
	t_game	*game;

	count = 0;
	game = (t_game *)param;
	free_tiles(game);
	delete_textures(game);
	if (game->map)
	{
		while (game->map[count])
		{
			free(game->map[count]);
			count++;
		}
		free(game->map);
	}
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
