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
	int	i;

	i = -1;
	if (game != NULL)
	{
		free_struct(game->parser.init);
		// free(game->textures.north.path);
		// free(game->textures.south.path);
		// free(game->textures.east.path);
		// free(game->textures.west.path);
		if (game->parsed_map)
		{
			while (game->parsed_map[++i])
				free(game->parsed_map[i]);
			free(game->parsed_map);
		}
		free(game);
	}
	printf(RED BOLD "Error\n" RESET);
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
