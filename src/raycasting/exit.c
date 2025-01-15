#include "cub3D.h"

int	close_window(t_game *game)
{
	ft_exit(game, 0);
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return;
	while (map->height > i)
		free(map->grid[i++]);
	free(map->grid);
	free(map);
}

void	free_textures(t_game *game)
{
	if (game->textures.north.img)
		mlx_destroy_image(game->render.mlx, game->textures.north.img);
	if (game->textures.south.img)
		mlx_destroy_image(game->render.mlx, game->textures.south.img);
	if (game->textures.east.img)
		mlx_destroy_image(game->render.mlx, game->textures.east.img);
	if (game->textures.west.img)
		mlx_destroy_image(game->render.mlx, game->textures.west.img);
	if (game->render.img)
		mlx_destroy_image(game->render.mlx, game->render.img);
}

void	ft_exit(t_game *game, int code)
{
	if (game->render.mlx)
	{
		if (game->render.window)
			mlx_destroy_window(game->render.mlx, game->render.window);
		free_textures(game);
		mlx_destroy_display(game->render.mlx);
		free(game->render.mlx);
	}
	if (game->map)
		free_map(game->map);
	exit(code);
}
