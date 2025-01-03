
#include "../include/cub3D.h"

void	fill_map(t_parser *parsed, t_file *init)
{
	int		i;
	char	**map;

	i = file_len(init);
	map = malloc(sizeof(char *) * (i + 1));
	if (map == NULL)
		parser_errors(parsed, "Error malloc");
	map[i] = 0;
	i = 0;
	while (init)
	{
		map[i] = ft_strdup(init->line);
		if (map[i] == NULL)
		{
			free_map2(map);
			parser_errors(parsed, "Error malloc");
		}
		init = init->next;
		i++;
	}
	parsed->map = map;
}

