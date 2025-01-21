/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:56:54 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:35:00 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * Initializes the map's height and width,
 then performs a flood fill from the player's start position.
 * It ensures that the game map is correctly populated
 with valid paths and checks for empty spaces.
 * Arguments: game (game state), map (map object to be initialized).
 * No return value (void function).
 */

void	init_map_part_1(t_game *game, t_map *map)
{
	map->height = matrix_len(game->map_copy);
	map->width = find_max_line(game->map_copy, NULL);
	flood_fill(game, game->pos_y, game->pos_x);
	check_flood(game);
}

/*
 * Allocates and initializes the grid representation
 of the map based on the map copy.
 * It converts '1' to walls and '2' to empty spaces,
 filling the grid with appropriate values.
 * Arguments: game (game state), map (map object to be initialized).
 * No return value (void function).
 */

void	init_map_part_2(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->grid = (int **)ft_calloc(map->height, sizeof(int *));
	while (i < map->height)
	{
		j = 0;
		map->grid[i] = (int *)ft_calloc(map->width, sizeof(int));
		while (j < map->width)
		{
			if (j < (int)ft_strlen(game->map_copy[i]))
			{
				if (game->map_copy[i][j] == '1')
					map->grid[i][j] = 1;
				else if (game->map_copy[i][j] == '2')
					map->grid[i][j] = 2;
			}
			j++;
		}
		i++;
	}
}

/*
 * Calls both parts
 of the map initialization (init_map_part_1 and init_map_part_2) in sequence.
 * It performs the necessary setup to prepare the game map
 * for further gameplay processing.
 * Arguments: game (game state), map (map object to be initialized).
 * No return value (void function).
 */

void	init_map(t_game *game, t_map *map)
{
	init_map_part_1(game, map);
	init_map_part_2(game, map);
}
