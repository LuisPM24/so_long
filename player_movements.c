/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:32:47 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/23 19:36:40 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_to_collect(t_game *game, int new_x, int new_y)
{
	int	count;

	count = 0;
	while (count < game->collect_amount)
	{
		if (game->collect[count].x == new_x
			&& game->collect[count].y == new_y)
		{
			mlx_delete_image(game->mlx, game->collect[count].img);
			game->collect[count] = game->collect[game->collect_amount - 1];
			game->collect_amount--;
			break ;
		}
		count++;
	}
	game->map[new_y][new_x] = '0';
}

static void	move_player(t_game *game, int next_x, int next_y)
{
	int		new_x;
	int		new_y;

	new_x = game->player.x + next_x;
	new_y = game->player.y + next_y;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		move_to_collect(game, new_x, new_y);
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collect_amount == 0)
		{
			ft_printf("You win!\nTotal Moves: %d\n", game->moves + 1);
			exit_game(game);
		}
	}
	game->player.x = new_x;
	game->player.y = new_y;
	game->moves++;
	ft_printf("Movements: %d\n", game->moves);
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
		next_y -= 1;
	else if (key == MLX_KEY_S)
		next_y += 1;
	else if (key == MLX_KEY_A)
		next_x -= 1;
	else if (key == MLX_KEY_D)
		next_x += 1;
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
