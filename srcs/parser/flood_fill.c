/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 06:16:50 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:34:43 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	flood_fill(t_game *game, int row, int col)
{
	if (game->map_copy[row][col] == '1' || game->map_copy[row][col] == '3')
		return ;
	game->map_copy[row][col] = '3';
	flood_fill(game, row - 1, col);
	flood_fill(game, row + 1, col);
	flood_fill(game, row, col - 1);
	flood_fill(game, row, col + 1);
}

void	check_flood(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map_copy[i][j] == '0'
				|| game->map_copy[i][j] == ' '
				|| game->map_copy[i][j] == '\t')
				game->map_copy[i][j] = '2';
			j++;
		}
		i++;
	}
}
