/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:34:40 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/12 10:56:55 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//# include <mlx.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_tile
{
	void	*tile_ptr;
	int		tile_width;
	int		tile_height;
}		t_tile;

typedef struct s_player
{
	int		x;
	int		y;
}		t_player;

typedef struct s_game
{
	void		*mlx_init;
	void		*window;
	char		**map;
	int			map_width;
	int			map_height;
	int			collect_amount;
	int			moves;
	t_player	player;
	t_tile		tile_wall;
	t_tile		tile_floor;
	t_tile		tile_player;
	t_tile		tile_exit;
	t_tile		tile_collect;
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
#endif
