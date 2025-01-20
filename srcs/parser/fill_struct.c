/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:38:09 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 23:17:49 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
