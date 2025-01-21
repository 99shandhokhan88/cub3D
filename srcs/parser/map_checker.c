/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:11:06 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:36:26 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * Checks the surrounding cells of a given map position (i, j) based on the 
 * specified `kind` (UP, DOWN, LEFT, RIGHT). Determines if any of the adjacent 
 * cells contain a '0', 'N', 'S', 'W', 'E' or the edge of the map, indicating 
 * that the space is invalid for movement.
 * Arguments: `map` (game map), `kind` (direction type), `i` (row), `j` (column).
 * Returns: 1 if surrounding cells are valid (open space or player), 0 otherwise.
 */

int	around_checker(char **map, int kind, int i, int j)
{
	if (map[i][j] == '\0' || map[i][j] == '0'
		|| map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'W' || map[i][j] == 'E')
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

/*
 * Recursively attempts to find a path
 in the specified direction (UP, DOWN, LEFT, RIGHT).
 * The function explores the map,
 marking cells as '2' to prevent revisiting, 
 * until it either finds an invalid area or reaches the edge of the map.
 * Arguments: `i` (row), `j` (column), `map` (game map),
 * `kind` (direction type).
 * Returns: 1 if path is found, 0 if path is blocked.
 */

int	find_path(int i, int j, char **map, int kind)
{
	int	len_max;

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

/*
 * Checks if there is an open space
 in the given direction (UP, DOWN, LEFT, RIGHT)
 * from the specified position (`x`, `y`).
 If there is an open space, an error message 
 * is printed with the relevant error type.
 * Arguments: `map` (game map), `x` (row), `y` (column), `type` (direction).
 * Returns: 1 if an error is found (open space in an invalid position),
 * 0 otherwise.
 */

int	check_correct_walls(char **map, int x, int y, int type)
{
	if (type == UP && find_path(x, y, map, type) == 1)
	{
		printf(RED BOLD "Error: open in the top of the map\n" RESET);
		return (1);
	}
	else if (type == DOWN && find_path(x, y, map, type) == 1)
	{
		printf(RED BOLD "Error: open in the bottom of the map\n" RESET);
		return (1);
	}
	else if (type == RIGHT && find_path(x, y, map, type) == 1)
	{
		printf(RED BOLD "Error: open in the right of the map\n" RESET);
		return (1);
	}
	else if (type == LEFT && find_path(x, y, map, type) == 1)
	{
		printf(RED BOLD "Error: open in the left of the map\n" RESET);
		return (1);
	}
	return (0);
}

/*
 * Checks the right side of the map for any invalid open spaces by calling 
 * `check_correct_walls` for the rightmost position of each row.
 * Arguments: `copy_map` (game map).
 * Returns: 1 if an error is found, 0 otherwise.
 */

int	right_check(char **copy_map)
{
	int	i;

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

/*
 * Performs a full border check on the map
 to ensure all edges (up, down, left, right) 
 * are properly enclosed by walls.
 Calls `check_correct_walls` for each edge.
 * Arguments: `copy_map` (game map).
 * Returns: 1 if an error is found, 0 otherwise.
 */

int	border_check(char **copy_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (right_check(copy_map) == 1)
		return (free_map(copy_map), 1);
	while (copy_map[0][++i + 1] != '\n')
		if (check_correct_walls(copy_map, 0, i, UP) == 1)
			return (free_map(copy_map), 1);
	while (copy_map[++j + 1] != NULL)
	{
		if (check_correct_walls(copy_map, j, 0, LEFT) == 1)
			return (free_map(copy_map), 1);
		if (check_correct_walls(copy_map, j, i, RIGHT) == 1)
			return (free_map(copy_map), 1);
	}
	i = 0;
	while (copy_map[j][++i + 1] != '\0')
		if (check_correct_walls(copy_map, j, i, DOWN) == 1)
			return (free_map(copy_map), 1);
	return (0);
}
