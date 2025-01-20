/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:33:19 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 19:44:14 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	parser(char *file, t_game *game)
{
	check_file(game, file);
	check_cub(&game->player_pars.file, file);
	init_pars_check(game, game->player_pars.file);
	struct_filler(game, game->player_pars.file);
	free_struct(game->player_pars.file);
	check_inside_char(game, &game->textures);
}
