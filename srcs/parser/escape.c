/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:11:40 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:34:08 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * Handles incorrect argument count during program execution.
 * Prints an error message and exits the program.
 * Usage: expects the program
 * to be called with one argument for the map file.
 */

int	my_error(char **av)
{
	printf(RED BOLD "Error: wrong arguments (ac != 2)!\n" RESET);
	printf("Usage: %s <filename>.cub\n", av[0]);
	exit(1);
}

/*
 * Frees all dynamically allocated memory
 for the linked list of `t_file` structs.
 * Each `t_file` contains a `line` field,
 which is also freed.
 */

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

/*
 * Handles parser-related errors
 by freeing all allocated resources.
 * It frees the linked list of file lines,
 parsed map, textures, and the game structure itself.
 * Prints the error message and exits the program with failure status.
 */

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

/*
 * Handles errors that occur while opening the file for reading.
 * It prints an error message, frees the file list,
 * and exits the program.
 */

void	handle_escape_file(t_file *file)
{
	printf(RED BOLD "Error: couldn't open the file!\n" RESET);
	free_struct(file);
	exit(EXIT_FAILURE);
}

/*
 * Frees the memory allocated for the 2D map (array of strings).
 * It iterates through each row of the map,
 * frees each row, and finally frees the array itself.
 */

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
