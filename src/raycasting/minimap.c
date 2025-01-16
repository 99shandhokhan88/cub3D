#include "cub3D.h"

void	square(t_game *game, int x, int y, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (c == 1)
				game->render.img_data[(y * TILE_SIZE + j) * SCREEN_WIDTH
					+ x * TILE_SIZE + i] = 0xFF0000;
			else if (c == 0)
				game->render.img_data[(y * TILE_SIZE + j) * SCREEN_WIDTH
					+ x * TILE_SIZE + i] = 0x00FF00;
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = game->pos_x * TILE_SIZE - 1;
	y = game->pos_y * TILE_SIZE - 1;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			game->render.img_data[(y + i) * SCREEN_WIDTH + (x + j)] = 0x0000FF;
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			square(game, x, y, game->map->grid[y][x]);
			x++;
		}
		y++;
	}
	draw_player(game);
}
