/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:36:59 by lpalomin          #+#    #+#             */
/*   Updated: 2025/05/11 10:36:17 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (1);
	map = get_map(argv[1]);
	if (!map)
	{
		write(2, "Error\nFailed to load map.\n", 26);
		exit(EXIT_FAILURE);
	}
	map_validations(map);
	object_validations(map);
	route_validation(map);
	start_game(map);
	return (0);
}

/*int	main(void)
{
	mlx_t	*mlx = mlx_init(200, 200, "Test", false);
	if (!mlx)
		return (EXIT_FAILURE);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}*/
