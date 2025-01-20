/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:48:39 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 19:48:40 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	calculate_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void	perform_dda(t_game *game, t_ray *ray)
{
	progress_ray(game, ray);
	calculate_wall_distance(ray);
}
