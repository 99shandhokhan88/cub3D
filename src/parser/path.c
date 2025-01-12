#include "cub3D.h"

int around_checker(char **map, int kind, int i, int j)
{
	if (map[i][j] == '\0' || map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
		return (1);
	if (kind == UP || kind == DOWN)
	{
		if (map[i][j + 1] != '\0' && map[i][j + 1] == '0')
			return (1);
		if (map[i][j - 1] != '\0' && map[i][j - 1] == '0')
			return (1);
	}
	else
	{
		if (map[i - 1][j] != '\0' && map[i - 1][j] == '0')
			return (1);
		if (map[i + 1][j] != '\0' && map[i + 1][j] == '0')
			return (1);
	}
	return (0);
}

int find_path(int i, int j, char **map, int kind)
{
	int len_max;

	len_max = matrix_len(map);
	if (around_checker(map, kind, i, j) == 1)
		return (1);
	if (map[i][j] == ' ')
	{
		map[i][j] = '2';
		if (kind == UP)
			if ((i + 1 > len_max) && find_path(i + 1, j, map, kind))
				return (1);
		if (kind == DOWN)
			if ((i - 1 < 0) && find_path(i - 1, j, map, kind))
				return (1);
		if (kind == LEFT)
			if (find_path(i, j + 1, map, kind))
				return (1);
		if (kind == RIGHT)
			if (find_path(i, j - 1, map, kind))
				return (1);
	}
	return (0);
}

int check_correct_walls(char **map, int x, int y, int type)
{
	if (type == UP && find_path(x, y, map, type) == 1)
	{
		printf(RED BOLD "Error\n" RESET);
		return (printf("Empty in the top of the map\n"), 1);
	}
	else if (type == DOWN && find_path(x, y, map, type) == 1)
	{
		printf(RED BOLD "Error\n" RESET);
		return (printf("Empty in the bottom of the map\n"), 1);
	}
	else if (type == RIGHT && find_path(x, y, map, type) == 1)
	{
		printf(RED BOLD "Error\n" RESET);
		return (printf("Empty in the right of the map\n"), 1);
	}
	else if (type == LEFT && find_path(x, y, map, type) == 1)
	{
		printf(RED BOLD "Error\n" RESET);
		return (printf("Empty in the left of the map\n"), 1);
	}
	return (0);
}

int right_check(char **copy_map)
{
	int i;

	i = 1;
	if (copy_map == NULL || copy_map[0] == NULL)
		return (1);
	while (copy_map[i + 1] && copy_map[i])
	{
		if (copy_map[i][ft_strlen(copy_map[i]) - 1] == ' ')
		{
			if (check_correct_walls(copy_map, i,
									ft_strlen(copy_map[i]) - 2, RIGHT) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

int border_check(char **copy_map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (right_check(copy_map) == 1)
		return (free_map2(copy_map), 1);
	while (copy_map[0][++i + 1] != '\n')
		if (check_correct_walls(copy_map, 0, i, UP) == 1)
			return (free_map2(copy_map), 1);
	while (copy_map[++j + 1] != NULL)
	{
		if (check_correct_walls(copy_map, j, 0, LEFT) == 1)
			return (free_map2(copy_map), 1);
		if (check_correct_walls(copy_map, j, i, RIGHT) == 1)
			return (free_map2(copy_map), 1);
	}
	i = 0;
	while (copy_map[j][++i + 1] != '\0')
		if (check_correct_walls(copy_map, j, i, DOWN) == 1)
			return (free_map2(copy_map), 1);
	return (free_map2(copy_map), 0);
}
