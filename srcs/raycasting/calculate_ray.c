/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 04:34:48 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 01:40:34 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: initialize_ray
 * -------------------------
 * Initializes the properties of a ray for a specific column (x) 
 * of the screen.
 * This function calculates the direction of the ray 
 * and the distance between grid lines 
 * for both the x and y axes.
 *
 * game: The game structure containing player position and direction.
 * ray: The ray structure to store calculated values.
 * x: The column of the screen (pixel index) for which the ray is being cast.
 */

void	initialize_ray(t_game *game, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_dir_x = game->dir_x + game->plane_x * ray->camera_x;
	ray->ray_dir_y = game->dir_y + game->plane_y * ray->camera_x;
	ray->map_y = (int)game->pos_y;
	ray->map_x = (int)game->pos_x;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

/* 
 * Function: calculate_step_and_side
 * ---------------------------------
 * Calculates the step and side distance for the ray. 
 * This function determines 
 * the direction in which the ray will step in the grid (either -1 or 1) 
 * and 
 * calculates the initial side distance based on 
 * the player's position relative 
 * to the ray's direction.
 *
 * game: The game structure containing the player's position.
 * ray: The ray structure where the step and side distances are stored.
 */

void	calculate_step_and_side(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->pos_y - ray->map_y) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_y + 1.0 - game->pos_y) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->pos_x - ray->map_x) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_x + 1.0 - game->pos_x) * ray->delta_dist_y;
	}
}

/* 
 * Function: calculate_ray
 * ------------------------
 * This function combines the initialization 
 * of the ray with the calculation 
 * of the step and side distances. 
 * It sets up the ray for the raycasting algorithm 
 * that will eventually be used to 
 * determine which walls the ray hits.
 *
 * game: The game structure containing 
 * the player's position and direction.
 * ray: The ray structure 
 * to store the ray properties.
 * x: The column of the screen (pixel index) 
 * to which the ray corresponds.
 */

void	calculate_ray(t_game *game, t_ray *ray, int x)
{
	initialize_ray(game, ray, x);
	calculate_step_and_side(game, ray);
}
