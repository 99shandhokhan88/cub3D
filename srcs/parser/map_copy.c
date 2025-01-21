/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:45:32 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:36:54 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * This function calculates the maximum line length
 in the map (i.e., the longest
 * string in the map array)
 and also optionally updates the provided integer `i` 
 * with the total number of rows in the map.
 * Arguments: `map` (array of strings representing the map),
 * `i` (optional pointer 
 * to store the number of rows).
 * Returns: the length of the longest line in the map.
 */

int	find_max_line(char **map, int *i)
{
	int	j;
	int	k;
	int	check;

	j = 0;
	k = 0;
	check = 0;
	if (i)
		k = *i;
	while (map[k])
	{
		j = 0;
		while ((map[k][j] != '\n') && (map[k][j] != '\0'))
			j++;
		if (check < j)
			check = j;
		if (i)
			*i = k + 1;
		k++;
	}
	return (check);
}

/*
 * This function copies a portion of the map
 into a new `copy_map` structure,
 * padding the lines with spaces
 if they are shorter than the longest line.
 * Arguments: `map_copy` (structure to hold the copied map), `i` (total rows), 
 * `j` (length of the longest line),
 * `map` (original map).
 * Returns: 0 if copying is successful,
 * 1 if there's an error (e.g., memory allocation failure).
 */

int	line_copy(t_map_copy *map_copy, int i, int j, char **map)
{
	while (++map_copy->i < i - 1)
	{
		map_copy->j = 0;
		map_copy->copy_map[map_copy->i] = malloc((j + 2) * sizeof(char));
		if (map_copy->copy_map[map_copy->i] == NULL)
		{
			free_map(map_copy->copy_map);
			return (1);
		}
		while (map[map_copy->i][map_copy->j] != '\n'
			&& map[map_copy->i][map_copy->j])
		{
			map_copy->copy_map[map_copy->i][map_copy->j] = \
					map[map_copy->i][map_copy->j];
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

/*
 * This function copies the last line of the map
 into the `copy_map` structure.
 * It ensures the last line is padded with spaces
 * if it is shorter than the longest 
 * line in the map.
 * Arguments: `map_copy` (structure to hold the copied map), `i` (row index), 
 * `map` (original map), `k` (length of the longest line).
 */

void	last_line_copy(t_map_copy *map_copy, int i, char **map, int k)
{
	int	j;

	j = -1;
	map_copy->copy_map[i] = malloc((1 + k) * sizeof(char));
	if (map_copy->copy_map[i] == NULL)
	{
		free_map(map_copy->copy_map);
		map_copy->copy_map = NULL;
		return ;
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

/*
 * This function handles the allocation and copying of the map, as well as 
 * padding any shorter rows with spaces.
 * Arguments: `map` (original map),
 * `i` (number of rows), `j` (length of the longest line).
 * Returns: a new map with the spaces padded, or NULL if there is an error.
 */

char	**manage_spaces(char **map, int i, int j)
{
	t_map_copy	copy_map;

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

/*
 * This function creates a copy of the original map,
 ensuring that all lines 
 * have equal length by padding shorter lines with spaces.
 * Arguments: `map` (original map).
 * Returns: a new map with padded lines, or NULL if there is an error.
 */

char	**map_copy(char **map)
{
	int		i;
	int		check;
	char	**copy_map;

	i = 0;
	check = find_max_line(map, &i);
	copy_map = manage_spaces(map, i, check);
	if (copy_map == NULL)
		return (NULL);
	return (copy_map);
}
