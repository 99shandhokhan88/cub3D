#include "cub3D.h"

void	advance_ray(t_ray *ray)
{
	if (ray->sideDistX < ray->sideDistY)
	{
		ray->sideDistX += ray->deltaDistX;
		ray->map_y += ray->stepX;
		ray->side = 0;
	}
	else
	{
		ray->sideDistY += ray->deltaDistY;
		ray->map_x += ray->stepY;
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
		ray->perpWallDist = ray->sideDistX - ray->deltaDistX;
	else
		ray->perpWallDist = ray->sideDistY - ray->deltaDistY;
}

void	perform_dda(t_game *game, t_ray *ray)
{
	progress_ray(game, ray);
	calculate_wall_distance(ray);
}
