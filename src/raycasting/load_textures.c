#include "cub3D.h"

void	load_single_texture(t_game *game, t_texture *texture, char *path)
{
	if (!path || !path[0])
	{
		printf("Error: Empty texture path\n");
		ft_exit(game, 1);
	}
	texture->img = mlx_xpm_file_to_image(game->render.mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("Error: Failed to load texture: %s\n", path);
		ft_exit(game, 1);
	}
	texture->addr = (unsigned int *)mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel,
			&texture->size_line,
			&texture->endian);
	if (!texture->addr)
	{
		printf("Error: Failed to get texture data address: %s\n", path);
		mlx_destroy_image(game->render.mlx, texture->img);
		ft_exit(game, 1);
	}
}

void	load_textures(t_game *game)
{
	if (!game || !game->textures.east.path || !game->textures.north.path
		|| !game->textures.south.path || !game->textures.west.path)
	{
		printf("Error: Invalid parameters for texture loading\n");
		ft_exit(game, 1);
	}
	load_single_texture(game, &game->textures.north, game->textures.north.path);
	load_single_texture(game, &game->textures.south, game->textures.south.path);
	load_single_texture(game, &game->textures.east, game->textures.east.path);
	load_single_texture(game, &game->textures.west, game->textures.west.path);
}
