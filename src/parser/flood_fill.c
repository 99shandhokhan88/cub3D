/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 03:52:09 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/17 03:52:11 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	floodfill(t_game *game, int row, int col)
{
	if (game->map_copy[row][col] == '1' || game->map_copy[row][col] == '3')
		return ;
	game->map_copy[row][col] = '3';
	floodfill(game, row - 1, col);
	floodfill(game, row + 1, col);
	floodfill(game, row, col - 1);
	floodfill(game, row, col + 1);
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
