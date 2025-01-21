/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:01:03 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:36:09 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * Allocates memory for the game structure (`t_game`) and its map substructure
 * (`t_map`). If memory allocation fails for either, the function frees any 
 * already allocated memory and sets the `game` pointer to NULL.
 * Arguments: `game` (pointer to the game structure).
 * Returns: None, modifies the `game` pointer directly.
 */

void	init_game(t_game **game)
{
	*game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!(*game))
		return ;
	(*game)->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!(*game)->map)
	{
		free(*game);
		*game = NULL;
		return ;
	}
}

/*
 * Searches the parsed map
 for the player's initial position (denoted by 'N', 'S', 'E', or 'W')
 * and sets the `pos_x` and `pos_y` coordinates accordingly.
 The player's position is stored
 * with a fractional value (e.g., 0.5) to represent the center of the player.
 * Arguments: `game` (game structure with parsed map).
 * Returns: None.
 */

void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->parsed_map[i])
	{
		j = 0;
		while (game->parsed_map[i][j])
		{
			if (game->parsed_map[i][j] == 'N'
				|| game->parsed_map[i][j] == 'S'
				|| game->parsed_map[i][j] == 'E'
				|| game->parsed_map[i][j] == 'W')
			{
				game->pos_y = i + 0.5;
				game->pos_x = j + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

/*
 * Initializes the player's direction (`dir_x`, `dir_y`)
 and the camera plane 
 * (`plane_x`, `plane_y`) based on the player's initial facing direction. 
 * Uses the `player_facing` value (NORTH, SOUTH, EAST, WEST)
 * to set the correct 
 * movement and camera plane orientation.
 * Arguments: `init_player` (game structure with player data).
 * Returns: None.
 */

void	init_player(t_game *init_player)
{
	find_player_position(init_player);
	if (init_player->player_pars.player_facing == NORTH)
	{
		init_player->dir_x = -1;
		init_player->plane_y = 0.66;
	}
	else if (init_player->player_pars.player_facing == SOUTH)
	{
		init_player->dir_x = 1;
		init_player->plane_y = -0.66;
	}
	else if (init_player->player_pars.player_facing == EAST)
	{
		init_player->dir_y = 1;
		init_player->plane_x = 0.66;
	}
	else if (init_player->player_pars.player_facing == WEST)
	{
		init_player->dir_y = -1;
		init_player->plane_x = -0.66;
	}
}
