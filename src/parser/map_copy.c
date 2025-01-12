#include "cub3D.h"

int find_max_line(char **map, int *i)
{
	int j;
	int check;
	int k;

	check = 0;
	j = 0;
	k = (i) ? *i : 0; // Use a local index if i is NULL

	while (map[k])
	{
		j = 0;
		while (map[k][j] != '\n' && map[k][j] != '\0')
			j++;
		if (check < j)
			check = j;
		if (i)
			*i = k + 1; // Update external index if provided
		k++;
	}
	return (check);
}

int line_copy(t_map_copy *map_copy, int i, int j, char **map)
{
	while (++map_copy->i < i - 1)
	{
		map_copy->j = 0;
		map_copy->copy_map[map_copy->i] = malloc((j + 2) * sizeof(char));
		if (map_copy->copy_map[map_copy->i] == NULL)
		{
			free_map2(map_copy->copy_map);
			return (1);
		}
		while (map[map_copy->i][map_copy->j] != '\n' && map[map_copy->i][map_copy->j])
		{
			map_copy->copy_map[map_copy->i][map_copy->j] = map[map_copy->i][map_copy->j];
			map_copy->j++;
		}
		map_copy->j--;
		while (++map_copy->j < j)
			map_copy->copy_map[map_copy->i][map_copy->j] = ' ';
		map_copy->copy_map[map_copy->i][map_copy->j] = '\n';
		map_copy->copy_map[map_copy->i][map_copy->j + 1] = '\0';
	}
	return (0);
}

void last_line_copy(t_map_copy *map_copy, int i, char **map, int k)
{
	int j;

	j = -1;
	map_copy->copy_map[i] = malloc((1 + k) * sizeof(char));
	if (map_copy->copy_map[i] == NULL)
	{
		free_map2(map_copy->copy_map);
		map_copy->copy_map = NULL;
		return;
	}
	while (map[i][++j] != '\n' && map[i][j])
		map_copy->copy_map[i][j] = map[i][j];
	while (j < k)
	{
		map_copy->copy_map[i][j] = ' ';
		j++;
	}
	map_copy->copy_map[i][j] = 0;
}

char **manage_spaces(char **map, int i, int j)
{
	t_map_copy copy_map;

	if (i == 0)
		return (NULL);
	ft_bzero(&copy_map, sizeof(copy_map));
	copy_map.i = -1;
	copy_map.copy_map = malloc(sizeof(char *) * (i + 1));
	if (copy_map.copy_map == NULL)
		return (NULL);
	copy_map.copy_map[i] = NULL;
	if (line_copy(&copy_map, i, j, map))
		return (NULL);
	last_line_copy(&copy_map, copy_map.i, map, j);
	return (copy_map.copy_map);
}

char **map_copy(char **map)
{
	int i;
	int check;
	char **copy_map;

	i = 0;
	check = find_max_line(map, &i);
	copy_map = manage_spaces(map, i, check);
	if (copy_map == NULL)
		return (NULL);
	return (copy_map);
}
