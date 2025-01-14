#include "cub3D.h"

void	fill_map(t_game *game, t_file *init)
{
	int		i;
	char	**map;

	i = size_lst(init);
	map = malloc(sizeof(char *) * (i + 1));
	if (map == NULL)
		parser_errors(game, "Error malloc");
	map[i] = 0;
	i = 0;
	while (init)
	{
		map[i] = ft_strdup(init->line);
		if (map[i] == NULL)
		{
			free_map2(map);
			parser_errors(game, "Error malloc");
		}
		init = init->next;
		i++;
	}
	game->parsed_map = map;
}
