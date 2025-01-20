/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:32:03 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 23:17:38 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	my_error(char **av)
{
	printf(RED BOLD "Error: wrong arguments (ac != 2)!" RESET);
	printf("Usage: %s <filename>.cub\n", av[0]);
	exit(1);
}

void	free_struct(t_file *file)
{
	t_file	*temp;

	while (file)
	{
		temp = file->next;
		if (file->line)
			free(file->line);
		free(file);
		file = temp;
	}
}

void	parser_errors(t_game *game, char *message)
{
	if (game != NULL)
	{
		free_struct(game->player_pars.file);
		if (game->parsed_map)
			free_map(game->parsed_map);
		if (game->map)
			free_matrix(game->map);
		if (game->textures.north.path)
			free(game->textures.north.path);
		if (game->textures.south.path)
			free(game->textures.south.path);
		if (game->textures.east.path)
			free(game->textures.east.path);
		if (game->textures.west.path)
			free(game->textures.west.path);
		free(game);
	}
	printf(RED BOLD "Error: in parser_errors!\n" RESET);
	printf("Debug: %s!\n", message);
	exit(EXIT_FAILURE);
}

void	handle_escape_file(t_file *file)
{
	printf(RED BOLD "Error: couldn't open the file!\n" RESET);
	free_struct(file);
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
	}
}
