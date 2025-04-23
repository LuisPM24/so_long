/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:08:18 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/23 10:58:43 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game, char **map)
{
	int	rows;
	int	columns;

	rows = 0;
	columns = ft_strlen(map[0]);
	while (map[rows])
		rows++;
	game->map = map;
	game->map_width = columns;
	game->map_height = rows;
	game->can_move = 1;
	game->moves = 0;
	game->collect_amount = 0;
	game->mlx = mlx_init(columns * 16, rows * 16, "so_long", false);
	if (!game->mlx)
	{
		write(2, "Error\n", 6);
		write(2, "It was impossible to open the game\n", 36);
		exit(EXIT_FAILURE);
	}
}

static void	tile_selector(t_game *game, char tile, int row, int col)
{
	mlx_image_t	*img;

	if (tile == '1')
		mlx_image_to_window(game->mlx, game->tile_wall.img, col * 16, row * 16);
	else if (tile == 'C')
	{
		img = mlx_texture_to_image(game->mlx, game->tile_collect.texture);
		if (!img)
		{
			write(2, "Error\nFailed to create collectible image\n", 42);
			exit(EXIT_FAILURE);
		}
		mlx_image_to_window(game->mlx, img, col * 16, row * 16);
		game->collect[game->collect_amount].x = col;
		game->collect[game->collect_amount].y = row;
		game->collect[game->collect_amount].img = img;
		game->collect_amount++;
	}
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->tile_exit.img, col * 16, row * 16);
	else if (tile == 'P')
	{
		game->player.x = col;
		game->player.y = row;
		game->map[row][col] = '0';
	}
}

static void	draw_map(t_game *game)
{
	int		row;
	int		col;
	char	tile;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			tile = game->map[row][col];
			mlx_image_to_window(game->mlx, game->tile_floor.img,
				col * 16, row * 16);
			tile_selector(game, tile, row, col);
			col++;
		}
		row++;
	}
	mlx_image_to_window(game->mlx, game->tile_player.img,
		game->player.x * 16, game->player.y * 16);
	game->tile_player.img->instances[0].x += 0;
}

void	start_game(char **map)
{
	t_game	game;

	if (!map)
	{
		write(2, "Error\nFailed to load map.\n", 26);
		exit(EXIT_FAILURE);
	}
	init_game(&game, map);
	load_tiles(&game);
	game.collect_amount = 0;
	game.collect = malloc(sizeof(t_collectible) *
		get_amount_tile(&game, 'C'));
	if (!game.collect)
	{
		write(2, "Error\nNo memory for collectibles\n", 34);
		exit(EXIT_FAILURE);
	}
	draw_map(&game);
	mlx_key_hook(game.mlx, input_hook, &game);
	mlx_close_hook(game.mlx, exit_game, &game);
	mlx_loop(game.mlx);
}
