/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 02:23:05 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 18:45:39 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * Function: line
 * ----------------
 * This function draws a line between
 * two points on the minimap using a
 * simple line algorithm.
 * It updates the pixels along the line to the
 * predefined minimap color.
 *
 * game: The main game structure containing the render context.
 * p1: The starting point of the line.
 * p2: The ending point of the line.
 *
 * The function calculates the step sizes
 * in both x and y directions, and
 * then it draws the line pixel by pixel.
 */

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

/*
 * Function: square
 * ----------------
 * This function draws a square
 * on the minimap at a specific location. The
 * square can represent different
 * types of tiles (e.g., walls, empty spaces,
 * forbidden areas).
 *
 * game: The main game structure containing the render context.
 * x: The x-coordinate of the square on the minimap grid.
 * y: The y-coordinate of the square on the minimap grid.
 * c: The color code for the square.
 * Different values represent different types
 *    of tiles (e.g., walls, forbidden areas, empty spaces).
 *
 * The function iterates over the pixels
 * in the square and assigns the correct
 * color based on the provided tile type.
 */

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
			if (c == 2)
				game->render.img_data[(y * TILE_SIZE + j) * SCREEN_WIDTH
					+ x * TILE_SIZE + i] = MINI_FORBIDDEN_COLOR;
			else if (c == 0)
				game->render.img_data[(y * TILE_SIZE + j) * SCREEN_WIDTH
					+ x * TILE_SIZE + i] = MINI_EMPTY_COLOR;
			j++;
		}
		i++;
	}
}

/*
 * Function: draw_player_direction
 * --------------------------------
 * This function draws an arrow
 * representing the player's direction on the
 * minimap. The direction is based
 * on the player's position and direction
 * vector.
 *
 * game: The main game structure containing the render context.
 *
 * It calculates the starting
 * and ending points of the direction line and
 * uses the `line` function to draw it.
 */

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

/*
 * Function: draw_player
 * ----------------------
 * This function draws the player
 * on the minimap as a small square. It also
 * draws the player's direction using an arrow.
 *
 * game: The main game structure
 * containing the render context.
 *
 * The function places a small square
 * at the player's position and calls
 * `draw_player_direction`
 * to represent the player's facing direction.
 */

void	draw_player(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = game->pos_x * TILE_SIZE - 4;
	y = game->pos_y * TILE_SIZE - 3;
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 6)
		{
			game->render.img_data[(y + i) * SCREEN_WIDTH + (x + j)] \
				= MINI_P_COLOR;
			j++;
		}
		i++;
	}
	draw_player_direction(game);
}

/*
 * Function: draw_minimap
 * -----------------------
 * This function draws the entire minimap
 * by iterating through the game map
 * and drawing each tile using the `square` function.
 * It then draws the player
 * on the minimap.
 *
 * game: The main game structure containing the game map and render context.
 *
 * The function iterates over the map's grid and calls `square` for each tile,
 * and after that, it draws the player using `draw_player`.
 */

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
