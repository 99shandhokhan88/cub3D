
#include "../include/cub3D.h"

int	my_error(char **av)
{
	printf(RED BOLD "ERROR: wrong arguments\n" RESET);
	printf("Usage: %s <filename>.cub\n", av[0]);
	exit (1);
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

	if (init == NULL)
		return ;
	while (init->next)
	{
		temp = init->next;
		if (init->line)
			free(init->line);
		free(init);
		init = temp;
	}
	if (init->line)
		free(init->line);
	free(init);
}

void	parser_errors(t_parser *parsed, char *message)
{
	int	i;

	i = -1;
	if (parsed != NULL)
	{
		free_struct(parsed->init);
		free(parsed->textures_parse.north);
		free(parsed->textures_parse.south);
		free(parsed->textures_parse.east);
		free(parsed->textures_parse.west);
		if (parsed->map)
		{
			while (parsed->map[++i])
				free(parsed->map[i]);
			free(parsed->map);
		}
		free(parsed);
	}
	printf(RED BOLD "Error\n" RESET);
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}
