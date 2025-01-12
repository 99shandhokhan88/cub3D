#include "cub3D.h"

int close_window(t_params *params)
{
	ft_exit(params, 0);
	return (0);
}

void free_map(t_map *map)
{
	int i;

	i = 0;
	if (!map)
		return;
	while (map->height > i)
		free(map->grid[i++]);
	free(map->grid);
	free(map);
}

void free_textures(t_params *params)
{
	if (params->textures.north.img)
		mlx_destroy_image(params->mlx,
						  params->textures.north.img);
	if (params->textures.south.img)
		mlx_destroy_image(params->mlx,
						  params->textures.south.img);
	if (params->textures.east.img)
		mlx_destroy_image(params->mlx,
						  params->textures.east.img);
	if (params->textures.west.img)
		mlx_destroy_image(params->mlx,
						  params->textures.west.img);
	if (params->img)
		mlx_destroy_image(params->mlx, params->img);
}

void ft_exit(t_params *params, int code)
{
	if (params->mlx)
	{
		if (params->window)
			mlx_destroy_window(params->mlx, params->window);
		free_textures(params);
		mlx_destroy_display(params->mlx);
		free(params->mlx);
	}
	if (params->game->map)
		free_map(params->game->map);
	exit(code);
}
