/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:29:23 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:38:32 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: free_parser
 * ----------------------
 * Frees the memory allocated for the game structure,
 * textures, and map data.
 *
 * game: The game structure to free.
 * 
 * This function ensures that all dynamically
 * allocated memory related to the game,
 * including textures and map data,
 * is properly freed to avoid memory leaks.
 */

void	free_parser(t_game *game)
{
	free(game->textures.east.path);
	free(game->textures.north.path);
	free(game->textures.south.path);
	free(game->textures.west.path);
	free_map(game->parsed_map);
	free(game->map);
	free(game);
	game = NULL;
}

/* 
 * Function: check_inside_char
 * ----------------------------
 * Checks that the texture paths
 * for all four directions (north, south, east, west)
 * are properly initialized and non-empty.
 *
 * game: The game structure used for error handling.
 * textures: The textures structure
 * containing paths for each direction.
 * 
 * If any of the texture paths are empty,
 * an error message is printed, and the game 
 * is cleaned up and exited.
 */

void	check_inside_char(t_game *game, t_textures *textures)
{
	if (textures->north.path[0] == '\0')
	{
		printf(RED BOLD "Error: file north empty\n" RESET);
		free_parser(game);
		exit(EXIT_FAILURE);
	}
	if (textures->south.path[0] == '\0')
	{
		printf(RED BOLD "Error: file south empty\n" RESET);
		free_parser(game);
		exit(EXIT_FAILURE);
	}
	if (textures->west.path[0] == '\0')
	{
		printf(RED BOLD "Error: file west empty\n" RESET);
		free_parser(game);
		exit(EXIT_FAILURE);
	}
	if (textures->east.path[0] == '\0')
	{
		printf(RED BOLD "Error: file east empty\n" RESET);
		free_parser(game);
		exit(EXIT_FAILURE);
	}
}

/* 
 * Function: parser
 * ----------------
 * Main function responsible
 * for parsing the provided map file and initializing 
 * the game environment. It checks the file,
 * processes the map, fills in the
 * required structures, and performs error handling.
 *
 * file: The path to the .cub file to parse.
 * game: The game structure that will hold all the parsed data.
 * 
 * This function coordinates
 * the parsing process and ensures the game is ready
 * for further processing.
 * If any errors are encountered during parsing, the game
 * is cleaned up and the program exits.
 */

void	parser(char *file, t_game *game)
{
	check_file(game, file);
	check_cub(&game->player_pars.file, file);
	init_pars_check(game, game->player_pars.file);
	struct_filler(game, game->player_pars.file);
	free_struct(game->player_pars.file);
	check_inside_char(game, &game->textures);
}
