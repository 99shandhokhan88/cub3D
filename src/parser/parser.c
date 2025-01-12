#include "cub3D.h"

void check_file(char *file)
{
	char *ext;
	size_t len;

	ext = ft_strrchr(file, '.');
	if (ext == 0)
	{
		printf(RED BOLD "Error\n" RESET "Wrong filename\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(ext);
	if (len < 4)
		len = 4;
	if (!ext || ft_strncmp(ext, ".cub", len) != 0 || len == 0)
	{
		printf(RED BOLD "Error\n" RESET "Wrong filename\n");
		exit(EXIT_FAILURE);
	}
}

t_parser *parse_init(void)
{
	t_parser *parsed;

	parsed = malloc(sizeof(t_parser));
	if (parsed == NULL)
		return (NULL);
	ft_bzero(parsed, sizeof(t_parser));

	// Initialize textures
	parsed->textures_parse.north = NULL;
	parsed->textures_parse.south = NULL;
	parsed->textures_parse.east = NULL;
	parsed->textures_parse.west = NULL;

	// Initialize colors
	parsed->floor.r = 0;
	parsed->floor.g = 0;
	parsed->floor.b = 0;
	parsed->ceiling.r = 0;
	parsed->ceiling.g = 0;
	parsed->ceiling.b = 0;

	parsed->player_position = 0;
	parsed->map = NULL;
	parsed->init = NULL;
	parsed->len_y = 0;

	return (parsed);
}

void free_parse(t_parser *parsed)
{
	free(parsed->textures_parse.north);
	free(parsed->textures_parse.south);
	free(parsed->textures_parse.east);
	free(parsed->textures_parse.west);
	free_map2(parsed->map);
	free(parsed);
	parsed = 0;
}

void check_inside_char(t_parser *parse)
{
	if (parse->textures_parse.north[0] == '\0')
	{
		printf(RED BOLD "Error\n" RESET "file empty north\n");
		free_parse(parse);
		exit(EXIT_FAILURE);
	}
	if (parse->textures_parse.south[0] == '\0')
	{
		printf(RED BOLD "Error\n" RESET "file empty south\n");
		free_parse(parse);
		exit(EXIT_FAILURE);
	}
	if (parse->textures_parse.west[0] == '\0')
	{
		printf(RED BOLD "Error\n" RESET "file empty west\n");
		free_parse(parse);
		exit(EXIT_FAILURE);
	}
	if (parse->textures_parse.east[0] == '\0')
	{
		printf(RED BOLD "Error\n" RESET "file empty east\n");
		free_parse(parse);
		exit(EXIT_FAILURE);
	}
}

t_parser *parser(char **av)
{
	t_file *init;
	t_parser *parsed_map;

	init = 0;
	check_file(av[1]);
	check_cub(&init, av[1]);
	init_empty(init);
	parsed_map = parse_init();
	if (parsed_map == NULL)
	{
		free_struct(init);
		parser_errors(NULL, "Malloc error\n");
	}
	struct_filler(parsed_map, init);
	free_struct(init);
	check_inside_char(parsed_map);
	return (parsed_map);
}
