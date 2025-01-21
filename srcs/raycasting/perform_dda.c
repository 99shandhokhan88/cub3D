/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:07:14 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:41:17 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: advance_ray
 * ----------------------
 * This function advances the ray by one step in the direction it is traveling.
 * It checks which side of the grid (X or Y axis) the ray will hit first, 
 * then moves the ray's position accordingly.
 * 
 * ray: The current ray object being processed, which holds the ray's current 
 *      position and direction.
 * 
 * This function modifies the `side_dist_x`, `side_dist_y`, and `map_x`, `map_y` 
 * coordinates to advance the ray to the next grid point.
 */

void	advance_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_y += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_x += ray->step_y;
		ray->side = 1;
	}
}

/* 
 * Function: check_hit
 * -------------------
 * This function checks if the ray has hit a wall or is out of bounds. 
 * If the ray hits a wall or goes outside the map, it returns 1 (hit), 
 * otherwise, it returns 0 (no hit).
 * 
 * game: The main game structure, which contains the map and other game data.
 * ray: The current ray object being processed.
 * 
 * It checks if the ray's current position is inside the map bounds, and 
 * whether the grid cell at that position is a wall (`1`).
 */

int	check_hit(t_game *game, t_ray *ray)
{
	if (ray->map_y >= 0 && ray->map_x >= 0 && ray->map_y < game->map->height
		&& ray->map_x < game->map->width)
	{
		if (game->map->grid[ray->map_y][ray->map_x] == 1)
			return (1);
	}
	else
		return (1);
	return (0);
}

/* 
 * Function: progress_ray
 * -----------------------
 * This function repeatedly advances the ray 
 * and checks for hits until the ray 
 * hits a wall or goes out of bounds.
 * 
 * game: The main game structure, which contains the map and other game data.
 * ray: The current ray object being processed.
 * 
 * It calls `advance_ray` to move the ray and `check_hit` 
 * to check for collisions.
 */

void	progress_ray(t_game *game, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		advance_ray(ray);
		hit = check_hit(game, ray);
	}
}

/* 
 * Function: calculate_wall_distance
 * ----------------------------------
 * This function calculates the perpendicular distance 
 * from the ray's current 
 * position to the wall it has hit. The perpendicular distance is used to 
 * determine how far the wall is from the player in a 3D rendering system.
 * 
 * ray: The current ray object being processed.
 * 
 * This function updates the `perp_wall_dist` field in the ray structure, 
 * which stores the calculated distance.
 */

void	calculate_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

/* 
 * Function: perform_dda
 * ---------------------
 * This function performs the entire 
 * Digital Differential Analyzer (DDA) algorithm 
 * for raycasting. It calculates the ray's progression 
 * across the map, checks for 
 * wall hits, and computes the perpendicular distance to the wall.
 * 
 * game: The main game structure, 
 * which contains the map and other game data.
 * ray: The current ray object being processed.
 * 
 * It calls `progress_ray` to advance 
 * the ray and `calculate_wall_distance` to 
 * calculate the distance to the wall.
 */

void	perform_dda(t_game *game, t_ray *ray)
{
	progress_ray(game, ray);
	calculate_wall_distance(ray);
}
