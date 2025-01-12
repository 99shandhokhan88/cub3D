#include "cub3D.h"

void initialize_ray(t_params *params, t_ray *ray, int x)
{
	ray->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->rayDirX = params->dirX + params->planeX * ray->cameraX;
	ray->rayDirY = params->dirY + params->planeY * ray->cameraX;
	ray->mapX = (int)params->posX;
	ray->mapY = (int)params->posY;
	if (ray->rayDirX == 0)
		ray->deltaDistX = 1e30;
	else
		ray->deltaDistX = fabs(1 / ray->rayDirX);
	if (ray->rayDirY == 0)
		ray->deltaDistY = 1e30;
	else
		ray->deltaDistY = fabs(1 / ray->rayDirY);
}

void calculate_step_and_side(t_params *params, t_ray *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (params->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - params->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (params->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - params->posY) * ray->deltaDistY;
	}
}

void calculate_ray(t_params *params, t_ray *ray, int x)
{
	initialize_ray(params, ray, x);
	calculate_step_and_side(params, ray);
}
