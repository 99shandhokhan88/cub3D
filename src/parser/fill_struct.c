#include "cub3D.h"

int	direction(t_game *game, t_file *init, char *dir, char **path)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (init->line && init->line[i] == ' ')
		i++;
	if (ft_strncmp(&init->line[i], dir, ft_strlen(dir)) == 0)
	{
		i += 2;
		while (init->line[i] == ' ')
			i++;
		if (*path != NULL)
			parser_errors(game, "This dir already exists\n");
		while (init->line[i])
		{
			i++;
			len++;
		}
		*path = ft_substr(init->line, i - len, len - 1);
		if (*path == NULL)
			parser_errors(game, "Substr error malloc\n");
		return (1);
	}
	return (0);
}

int	fill_ceiling(t_game *game, t_file *init, int *index)
{
	game->colors.ceiling.r = ft_atoi(&init->line[*index]);
	if (game->colors.ceiling.r > 255 || game->colors.ceiling.r < 0
		|| !ft_isdigit(init->line[*index]))
		parser_errors(game, "Wrong red code\n");
	*index = skip_spaces(*index, game, init);
	game->colors.ceiling.g = ft_atoi(&init->line[*index]);
	if (game->colors.ceiling.g > 255 || game->colors.ceiling.g < 0
		|| !ft_isdigit(init->line[*index]))
		parser_errors(game, "Wrong green code\n");
	*index = skip_spaces(*index, game, init);
	game->colors.ceiling.b = ft_atoi(&init->line[*index]);
	if (game->colors.ceiling.b > 255 || game->colors.ceiling.b < 0
		|| !ft_isdigit(init->line[*index]))
		parser_errors(game, "Wrong blue code\n");
	return (0);
}

int	fill_floor(t_game *game, t_file *init, int *index)
{
	game->colors.floor.r = ft_atoi(&init->line[*index]);
	if (game->colors.floor.r > 255 || game->colors.floor.r < 0
		|| !ft_isdigit(init->line[*index]))
		parser_errors(game, "Wrong red code\n");
	*index = skip_spaces(*index, game, init);
	game->colors.floor.g = ft_atoi(&init->line[*index]);
	if (game->colors.floor.g > 255 || game->colors.floor.g < 0
		|| !ft_isdigit(init->line[*index]))
		parser_errors(game, "Wrong green code\n");
	*index = skip_spaces(*index, game, init);
	game->colors.floor.b = ft_atoi(&init->line[*index]);
	if (game->colors.floor.b > 255 || game->colors.floor.b < 0
		|| !ft_isdigit(init->line[*index]))
		parser_errors(game, "Wrong blue code\n");
	return (0);
}

void	the_checker(t_game *game, t_file *init, int i)
{
	int	count;

	count = 0;
	while (init->line[i] != '\n')
	{
		if (count >= 3)
			parser_errors(game, "error color or ceiling\n");
		if (ft_isdigit(init->line[i]) == 0 && init->line[i] != '\n')
			parser_errors(game, "error color or ceiling\n");
		count++;
		i++;
	}
}

int	background_fill(t_game *game, t_file *init, char platform, int *flag)
{
	int	i;

	i = 0;
	while (init->line && init->line[i] == ' ')
		i++;
	i++;
	if (init->line[i - 1] == platform)
	{
		if (*flag == 0)
			*flag = 1;
		else
			parser_errors(game, "There is already a background.\n");
		while (init->line && init->line[i] == ' ')
			i++;
		if (init->line[i] < '0' && init->line[i] > '9')
			parser_errors(game, "Wrong color code\n");
		if (platform == 'F')
			fill_floor(game, init, &i);
		if (platform == 'C')
			fill_ceiling(game, init, &i);
		the_checker(game, init, i);
		return (1);
	}
	return (0);
}

void	struct_filler(t_game *game, t_file *init)
{
	int	check;
	int	count;
	int	ceiling;
	int	floor;

	count = 0;
	ceiling = 0;
	floor = 0;
	while (init && count < 6)
	{
		check = 0;
		check += direction(game, init, "NO", &game->textures.north.path);
		check += direction(game, init, "EA", &game->textures.east.path);
		check += direction(game, init, "SO", &game->textures.south.path);
		check += direction(game, init, "WE", &game->textures.west.path);
		check += background_fill(game, init, 'F', &floor);
		check += background_fill(game, init, 'C', &ceiling);
		if (check <= 0)
			parser_errors(game, "Lacks something\n");
		count++;
		init = init->next;
	}
	fill_map(game, init);
}
