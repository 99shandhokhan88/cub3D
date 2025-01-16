/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:03:10 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/16 18:03:12 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	line(t_game *game, t_point p1, t_point p2)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = p2.x - p1.x;
	delta_y = p2.y - p1.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = p1.x;
	pixel_y = p1.y;
	while (pixels)
	{
		game->render.img_data[(int)pixel_y * SCREEN_WIDTH + (int)pixel_x] \
			= MINI_P_COLOR;
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

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
					+ x * TILE_SIZE + i] = MINI_WALL_COLOR;
			else if (c == 0)
				game->render.img_data[(y * TILE_SIZE + j) * SCREEN_WIDTH
					+ x * TILE_SIZE + i] = MINI_EMPTY_COLOR;
			j++;
		}
		i++;
	}
}

void	draw_player_direction(t_game *game)
{
	t_point	p1;
	t_point	p2;

	p1.x = game->pos_x * TILE_SIZE;
	p1.y = game->pos_y * TILE_SIZE;
	p2.x = p1.x + game->dir_y * 10;
	p2.y = p1.y + game->dir_x * 10;
	line(game, p1, p2);
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
			game->render.img_data[(y + i) * SCREEN_WIDTH + (x + j)] \
				= MINI_P_COLOR;
			j++;
		}
		i++;
	}
	draw_player_direction(game);
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
