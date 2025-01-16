#include "cub3D.h"

void	initialize_ray(t_game *game, t_ray *ray, int x)
{
	ray->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->rayDirX = game->dirX + game->planeX * ray->cameraX;
	ray->rayDirY = game->dirY + game->planeY * ray->cameraX;
	ray->map_y = (int)game->pos_y;
	ray->map_x = (int)game->pos_x;
	if (ray->rayDirX == 0)
		ray->deltaDistX = 1e30;
	else
		ray->deltaDistX = fabs(1 / ray->rayDirX);
	if (ray->rayDirY == 0)
		ray->deltaDistY = 1e30;
	else
		ray->deltaDistY = fabs(1 / ray->rayDirY);
}

void	calculate_step_and_side(t_game *game, t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (game->pos_y - ray->map_y) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->map_y + 1.0 - game->pos_y) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (game->pos_x - ray->map_x) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->map_x + 1.0 - game->pos_x) * ray->deltaDistY;
	}
}

void	calculate_ray(t_game *game, t_ray *ray, int x)
{
	initialize_ray(game, ray, x);
	calculate_step_and_side(game, ray);
}
