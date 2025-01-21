/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:15:27 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:37:23 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_map(t_game *game, t_file *init)
{
	int		i;
	char	**map;

	i = size_lst(init);
	map = malloc(sizeof(char *) * (i + 1));
	if (map == NULL)
		parser_errors(game, "error malloc");
	map[i] = 0;
	i = 0;
	while (init)
	{
		map[i] = ft_strdup(init->line);
		if (map[i] == NULL)
		{
			free_map(map);
			parser_errors(game, "error malloc");
		}
		init = init->next;
		i++;
	}
	game->parsed_map = map;
}
