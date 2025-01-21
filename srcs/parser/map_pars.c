/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:01:47 by flo-dolc           #+#    #+#             */
/*   Updated: 2025/01/21 01:47:20 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing_map(t_game *game)
{
	int		error;
	char	**matrix_copy;

	error = 0;
	matrix_copy = map_copy(game->parsed_map);
	game->map_copy = matrix_copy;
	if (matrix_copy == NULL || matrix_copy[0] == NULL)
	{
		printf(RED BOLD "Error: malloc!\n" RESET);
		return (1);
	}
	error = check_inside(&game->player_pars, matrix_copy);
	if (error == 1 || game->player_pars.player_facing == 0)
	{
		printf(RED BOLD "Error: player position!\n" RESET);
		return (free_map(matrix_copy), 1);
	}
	if (error == 2)
	{
		printf(RED BOLD "Error: spaces inside map!\n" RESET);
		return (free_map(matrix_copy), 1);
	}
	return (border_check(matrix_copy));
}
