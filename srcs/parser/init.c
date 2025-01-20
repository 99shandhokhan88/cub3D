/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:32:43 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 23:31:08 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
