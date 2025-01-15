#include "cub3D.h"

void	check_file(t_game *game, char *file)
{
	char	*ext;
	size_t	len;

	ext = ft_strrchr(file, '.');
	if (ext == 0)
	{
		parser_errors(game, "Wrong filename\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(ext);
	if (len < 4)
		len = 4;
	if (!ext || ft_strncmp(ext, ".cub", len) != 0 || len == 0)
	{
		parser_errors(game, "Wrong filename\n");
		exit(EXIT_FAILURE);
	}
}

void	free_parse(t_game *game)
{
	free(game->textures.east.path);
	free(game->textures.north.path);
	free(game->textures.south.path);
	free(game->textures.west.path);
	free_map2(game->parsed_map);
	free(game);
	game = NULL;
}

void	check_inside_char(t_game *game, t_textures *textures)
{
	if (textures->east.path[0] == '\0')
	{
		printf(RED BOLD "Error\n" RESET "file empty north\n");
		free_parse(game);
		exit(EXIT_FAILURE);
	}
	if (textures->north.path[0] == '\0')
	{
		printf(RED BOLD "Error\n" RESET "file empty north\n");
		free_parse(game);
		exit(EXIT_FAILURE);
	}
	if (textures->south.path[0] == '\0')
	{
		printf(RED BOLD "Error\n" RESET "file empty south\n");
		free_parse(game);
		exit(EXIT_FAILURE);
	}
	if (textures->west.path[0] == '\0')
	{
		printf(RED BOLD "Error\n" RESET "file empty west\n");
		free_parse(game);
		exit(EXIT_FAILURE);
	}
}

void	parser(char *filename, t_game *game)
{
	check_file(game, filename);
	check_cub(&game->parser.init, filename);
	init_empty(game->parser.init);
	struct_filler(game, game->parser.init);
	free_struct(game->parser.init);
	check_inside_char(game, &game->textures);
}
