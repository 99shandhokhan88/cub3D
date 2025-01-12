#include "cub3D.h"

void	load_single_texture(t_params *params, t_texture *texture, char *path)
{
	if (!path || !path[0])
	{
		printf("Error: Empty texture path\n");
		ft_exit(params, 1);
	}
	texture->img = mlx_xpm_file_to_image(params->mlx, path,
										 &texture->width, &texture->height);
	if (!texture->img)
	{
		printf("Error: Failed to load texture: %s\n", path);
		ft_exit(params, 1);
	}
	texture->addr = (unsigned int *)mlx_get_data_addr(texture->img,
													  &texture->bits_per_pixel,
													  &texture->size_line,
													  &texture->endian);
	if (!texture->addr)
	{
		printf("Error: Failed to get texture data address: %s\n", path);
		mlx_destroy_image(params->mlx, texture->img);
		ft_exit(params, 1);
	}
}

void	load_textures(t_params *params)
{
	if (!params || !params->game || !params->game->textures)
	{
		printf("Error: Invalid parameters for texture loading\n");
		ft_exit(params, 1);
	}
	load_single_texture(params,
						&params->textures.north, params->game->textures->north.path);
	load_single_texture(params,
						&params->textures.south, params->game->textures->south.path);
	load_single_texture(params,
						&params->textures.east, params->game->textures->east.path);
	load_single_texture(params,
						&params->textures.west, params->game->textures->west.path);
}
