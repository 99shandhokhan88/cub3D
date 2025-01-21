/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:51:35 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:33:50 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Functions to validate and analyze a map in the game. 
 * `check_pos` checks if the player has been assigned
 * a direction (N, S, E, W) for movement and validates invalid characters. 
 * `corner_check` verifies if any corner of a specific
 * position is empty (invalid space). 
 * `is_empty` determines if a character is an invalid
 * or non-wall character (' ', tab, '1', or newline). 
 * `check_space_inside` checks if a space is surrounded
 * by valid characters (walls or player direction). 
 * `check_inside` iterates through the map
 * to ensure proper player positioning and map validity,
 * returning errors for invalid positions or spacing issues. 
 */

int	check_pos(char c, t_player_pars *player_pars)
{
	if (c == 'N' && player_pars->player_facing == 0)
		player_pars->player_facing = NORTH;
	else if (c == 'S' && player_pars->player_facing == 0)
		player_pars->player_facing = SOUTH;
	else if (c == 'E' && player_pars->player_facing == 0)
		player_pars->player_facing = EAST;
	else if (c == 'W' && player_pars->player_facing == 0)
		player_pars->player_facing = WEST;
	else if (c != '\0' && c != '1' && c != '0'
		&& c != '\n' && c != ' ' && c != '	')
		return (1);
	return (0);
}

int	corner_check(char **map, int i, int j)
{
	int	maxj;

	maxj = ft_strlen(map[i]);
	if (i + 1 < matrix_len(map) && j - 1 > 0)
		if (is_empty(map[i + 1][j - 1]))
			return (1);
	if (i - 1 > 0 && j + 1 < maxj)
		if (is_empty(map[i - 1][j + 1]))
			return (1);
	if (j + 1 < maxj && i + 1 < matrix_len(map))
		if (is_empty(map[i + 1][j + 1]))
			return (1);
	if (j - 1 > 0 && i - 1 > 0)
		if (is_empty(map[i - 1][j - 1]))
			return (1);
	return (0);
}

int	is_empty(char c)
{
	if (c && c != ' ' && c != '	' && c != '1' && c != '\n')
		return (1);
	return (0);
}

int	check_space_inside(char **map, int i, int j)
{
	int	maxj;

	maxj = ft_strlen(map[i]);
	if (i + 1 < matrix_len(map))
		if (is_empty(map[i + 1][j]))
			return (1);
	if (i - 1 > 0)
		if (is_empty(map[i - 1][j]))
			return (1);
	if (j + 1 < maxj)
		if (is_empty(map[i][j + 1]))
			return (1);
	if (j - 1 > 0)
		if (is_empty(map[i][j - 1]))
			return (1);
	if (corner_check(map, i, j) == 1)
		return (1);
	return (0);
}

int	check_inside(t_player_pars *parsed, char **copy_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (copy_map == NULL || copy_map[0] == NULL)
		return (1);
	while (copy_map[i])
	{
		j = 0;
		while (copy_map[i][j])
		{
			if (check_pos(copy_map[i][j], parsed) != 0)
				return (1);
			if (copy_map[i][j] == ' ' || copy_map[i][j] == '	')
				if (check_space_inside(copy_map, i, j) == 1)
					return (2);
			j++;
		}
		i++;
	}
	return (0);
}
