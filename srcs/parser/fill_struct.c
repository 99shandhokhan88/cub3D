/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:45:41 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:34:28 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function checks for a specific direction (NO, SO, WE, EA)
 in the file line.
 * If the direction is found, it extracts the path string
 after the direction and stores it in the corresponding texture path.
 * Returns 1 if the direction is found and processed, otherwise 0.
 * Arguments: game (game state), file (line of the configuration file),
 * dir (direction string), path (pointer to store path).
 */

int	direction(t_game *game, t_file *file, char *dir, char **path)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (file->line && file->line[i] == ' ')
		i++;
	if (ft_strncmp(&file->line[i], dir, ft_strlen(dir)) == 0)
	{
		i += 2;
		while (file->line[i] == ' ')
			i++;
		if (*path != NULL)
			parser_errors(game, "this direction already exists");
		while (file->line[i])
		{
			i++;
			len++;
		}
		*path = ft_substr(file->line, i - len, len - 1);
		if (*path == NULL)
			parser_errors(game, "substr error (malloc)");
		return (1);
	}
	return (0);
}

/*
 * This function fills the ceiling color values (red, green, blue)
 from the file line.
 * It performs bounds checking and ensures the values
 are valid RGB values between 0 and 255.
 * Arguments: game (game state), file (line of the configuration file),
 index (pointer to the position in the line).
 * Returns 0 after successfully filling the ceiling color.
 */

int	fill_ceiling(t_game *game, t_file *file, int *index)
{
	game->colors.ceiling.r = ft_atoi(&file->line[*index]);
	if (game->colors.ceiling.r > 255 || game->colors.ceiling.r < 0
		|| !ft_isdigit(file->line[*index]))
		parser_errors(game, "wrong red code (c)");
	*index = skip_spaces(*index, game, file);
	game->colors.ceiling.g = ft_atoi(&file->line[*index]);
	if (game->colors.ceiling.g > 255 || game->colors.ceiling.g < 0
		|| !ft_isdigit(file->line[*index]))
		parser_errors(game, "wrong green code (c)");
	*index = skip_spaces(*index, game, file);
	game->colors.ceiling.b = ft_atoi(&file->line[*index]);
	if (game->colors.ceiling.b > 255 || game->colors.ceiling.b < 0
		|| !ft_isdigit(file->line[*index]))
		parser_errors(game, "wrong blue code (c)");
	return (0);
}

/*
 * Similar to `fill_ceiling`,
 this function fills the floor color values (red, green, blue)
 from the file line.
 * It performs bounds checking to ensure the values are valid RGB values.
 * Arguments: game (game state), file (line of the configuration file),
 * index (pointer to the position in the line).
 * Returns 0 after successfully filling the floor color.
 */

int	fill_floor(t_game *game, t_file *file, int *index)
{
	game->colors.floor.r = ft_atoi(&file->line[*index]);
	if (game->colors.floor.r > 255 || game->colors.floor.r < 0
		|| !ft_isdigit(file->line[*index]))
		parser_errors(game, "wrong red code (f)");
	*index = skip_spaces(*index, game, file);
	game->colors.floor.g = ft_atoi(&file->line[*index]);
	if (game->colors.floor.g > 255 || game->colors.floor.g < 0
		|| !ft_isdigit(file->line[*index]))
		parser_errors(game, "wrong green code (f)");
	*index = skip_spaces(*index, game, file);
	game->colors.floor.b = ft_atoi(&file->line[*index]);
	if (game->colors.floor.b > 255 || game->colors.floor.b < 0
		|| !ft_isdigit(file->line[*index]))
		parser_errors(game, "wrong blue code (f)");
	return (0);
}

/*
 * This function handles the background color setup
 for either the ceiling or the floor.
 * It checks if the background has been previously set,
 then calls either `fill_ceiling`
 or `fill_floor` based on the platform type ('C' for ceiling, 'F' for floor).
 * Arguments: game (game state),
 file (line of the configuration file), platform (either 'F' or 'C'),
 flag (to track if background is set).
 * Returns 1 if background is successfully set, otherwise 0.
 */

int	background_fill(t_game *game, t_file *file, char platform, int *flag)
{
	int	i;

	i = 0;
	while (file->line && file->line[i] == ' ')
		i++;
	i++;
	if (file->line[i - 1] == platform)
	{
		if (*flag == 0)
			*flag = 1;
		else
			parser_errors(game, "there's already a background");
		while (file->line && file->line[i] == ' ')
			i++;
		if (file->line[i] < '0' && file->line[i] > '9')
			parser_errors(game, "wrong color code");
		if (platform == 'F')
			fill_floor(game, file, &i);
		if (platform == 'C')
			fill_ceiling(game, file, &i);
		file_lines_checker(game, file, i);
		return (1);
	}
	return (0);
}

/*
 * This function processes the entire configuration file
 and fills in the relevant structures in the game.
 * It checks for the presence of texture paths
 for all four directions and ceiling/floor colors.
 * Arguments: game (game state), file (linked list of file lines).
 * It exits the program with an error if anything is missing or invalid.
 */

void	struct_filler(t_game *game, t_file *file)
{
	int	check;
	int	count;
	int	ceiling;
	int	floor;

	check = 0;
	count = 0;
	ceiling = 0;
	floor = 0;
	while (file && count < 6)
	{
		check = 0;
		check += direction(game, file, "NO", &game->textures.north.path);
		check += direction(game, file, "SO", &game->textures.south.path);
		check += direction(game, file, "WE", &game->textures.west.path);
		check += direction(game, file, "EA", &game->textures.east.path);
		check += background_fill(game, file, 'C', &ceiling);
		check += background_fill(game, file, 'F', &floor);
		if (check <= 0)
			parser_errors(game, "lacks something (tex/c/f)");
		count++;
		file = file->next;
	}
	fill_map(game, file);
}
