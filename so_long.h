/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:34:40 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/23 10:42:33 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"
# include "MLX42/MLX42.h"

typedef struct s_tile
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;
}		t_tile;

typedef struct s_player
{
	int			x;
	int			y;
}		t_player;

typedef struct	s_collectible
{
	int			x;
	int			y;
	mlx_image_t	*img;
}	t_collectible;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				map_width;
	int				map_height;
	t_collectible	*collect;
	int				collect_amount;
	int				can_move;
	int				moves;
	t_player		player;
	t_tile			tile_wall;
	t_tile			tile_floor;
	t_tile			tile_player;
	t_tile			tile_exit;
	t_tile			tile_collect;
}		t_game;

// map_validations.c
void	map_validations(char **map);
// object_validations.c
void	object_validations(char **map);
// map_methods.c
char	**get_map(char *map_arg);
void	print_map(char **map);
// route_validation.c
void	route_validation(char **map);
// charge_textures.c
void	load_tiles(t_game *game);
// load_game.c
void	start_game(char **map);
// player_movements.c
int		get_amount_tile(t_game *game, char tile);
void	input_hook(mlx_key_data_t keydata, void *param);
// exit_game.c
void	exit_game(void *param);
#endif
