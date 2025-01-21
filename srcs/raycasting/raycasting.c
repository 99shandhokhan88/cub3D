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

/* 
 * Function: raycasting
 * --------------------
 * This is the main function for raycasting, 
 * which is responsible for casting rays 
 * for each vertical column (screen x-coordinate) 
 * and drawing the corresponding 
 * wall slice based on the ray's intersection with a wall.
 * 
 * game: The game structure containing all the game data, 
 * such as the map and player position.
 * params: The render parameters including the image data 
 * for drawing the final screen.
 * 
 * This function loops over all screen columns (from 0 to SCREEN_WIDTH), 
 * calculates the corresponding ray for each column, performs the Digital 
 * Differential Analyzer (DDA) algorithm to find wall intersections, 
 * and draws the wall slice to the screen.
 */

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
