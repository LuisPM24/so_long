/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:32:47 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/23 17:02:56 by lpalomin         ###   ########.fr       */
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

static void	move_player(t_game *game, int next_x, int next_y)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player.x + next_x;
	new_y = game->player.y + next_y;
	tile = game->map[new_y][new_x];
	ft_printf("Actual: (%d, %d)\nMove to: (%d, %d)\n", game->player.x, game->player.y, new_x, new_y);
	if (tile == '1')
		return ;
	if (tile == 'C')
	{
		for (int i = 0; i < game->collect_amount; i++)
		{
			if (game->collect[i].x == new_x && game->collect[i].y == new_y)
			{
				mlx_delete_image(game->mlx, game->collect[i].img);
				game->collect[i] = game->collect[game->collect_amount - 1];
				game->collect_amount--;
				break;
			}
		}
		game->map[new_y][new_x] = '0';
	}
	if (tile == 'E')
	{
		if (game->collect_amount == 0)
		{
			ft_printf("You win!\nTotal Moves: %d", game->moves + 1);
			exit_game(game);
		}
	}
	game->player.x = new_x;
	game->player.y = new_y;
	game->moves++;
	ft_printf("Player instances: %d\n", game->tile_player.img->count);
	ft_printf("Movimientos: %d\n", game->moves);
	game->tile_player.img->instances[0].x = new_x * 16;
	game->tile_player.img->instances[0].y = new_y * 16;
}

static int	check_valid_move(t_game *game, keys_t key)
{
	int	next_x;
	int	next_y;

	next_x = game->player.x;
	next_y = game->player.y;
	if (key == MLX_KEY_W)
	{
		next_y -= 1;
		ft_printf("Pressing W\n");
	}
	else if (key == MLX_KEY_S)
	{
		next_y += 1;
		ft_printf("Pressing S\n");
	}
	else if (key == MLX_KEY_A)
	{
		next_x -= 1;
		ft_printf("Pressing A\n");
	}
	else if (key == MLX_KEY_D)
	{
		next_x += 1;
		ft_printf("Pressing D\n");
	}
	if (game->map[next_y][next_x] == '1')
		return (0);
	return (1);
}

void	input_hook(mlx_key_data_t keydata, void	*param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS && game->can_move)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			exit_game(game);
		else if (check_valid_move(game, keydata.key))
		{
			if (keydata.key == MLX_KEY_W)
				move_player(game, 0, -1);
			if (keydata.key == MLX_KEY_S)
				move_player(game, 0, 1);
			if (keydata.key == MLX_KEY_A)
				move_player(game, -1, 0);
			if (keydata.key == MLX_KEY_D)
				move_player(game, 1, 0);
			game->can_move = 0;
		}
	}
	else if (keydata.action == MLX_RELEASE)
		game->can_move = true;
}
