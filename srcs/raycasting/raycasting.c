/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:29:14 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:39:14 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycasting(t_game *game, t_render *params)
{
	int		x;
	t_ray	ray;

	x = 0;
	if (!params || !game || !game->map || !params->img_data)
	{
		printf(RED BOLD "Error: Invalid parameters in raycasting!\n" RESET);
		ft_exit(game, 1);
	}
	while (x < SCREEN_WIDTH)
	{
		calculate_ray(game, &ray, x);
		perform_dda(game, &ray);
		draw_wall_slice(game, &ray, x, 0);
		x++;
	}
}
