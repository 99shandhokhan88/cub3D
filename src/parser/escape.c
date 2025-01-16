#include "cub3D.h"

int	my_error(char **av)
{
	printf(RED BOLD "ERROR: wrong arguments\n" RESET);
	printf("Usage: %s <filename>.cub\n", av[0]);
	exit(1);
}

void	parsing_handle_escape(t_file *file)
{
	printf(RED BOLD "Error parser\n" RESET);
	free_struct(file);
	exit(EXIT_FAILURE);
}

void	free_struct(t_file *init)
{
	t_file	*temp;

	while (init)
	{
		temp = init->next;
		if (init->line)
			free(init->line);
		free(init);
		init = temp;
	}
}

void	parser_errors(t_game *game, char *message)
{
	if (game != NULL)
	{
		free_struct(game->parser.init);
		if (game->parsed_map)
			free_map2(game->parsed_map);
		if (game->map)
			free_map(game->map);
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
	printf(RED BOLD "Error\n" RESET);
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	free_map2(char **map)
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
