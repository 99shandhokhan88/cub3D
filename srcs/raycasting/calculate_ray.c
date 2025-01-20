/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:50:13 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 19:50:14 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	calculate_ray(t_game *game, t_ray *ray, int x)
{
	initialize_ray(game, ray, x);
	calculate_step_and_side(game, ray);
}
