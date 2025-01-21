/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:59:39 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 01:35:31 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
 * Initializes the graphics for rendering the game using the mlx library.
 * This includes setting up mlx, creating a window, an image, and retrieving 
 * the image data address for drawing.
 * Arguments: init_game (game state structure).
 * Returns: 0 on success, exits with error message on failure.
 */

int	init_render_graphics(t_game *init_game)
{
	init_game->render.mlx = mlx_init();
	if (!init_game->render.mlx)
		exit (printf("Error: failed to initialize mlx!\n"));
	init_game->render.window = mlx_new_window(init_game->render.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!init_game->render.window)
		exit (printf("Error: failed to create new window!\n"));
	init_game->render.img = mlx_new_image(init_game->render.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!init_game->render.img)
		exit (printf("Error: failed to create new image!\n"));
	init_game->render.img_data
		= (unsigned int *)mlx_get_data_addr(init_game->render.img,
			&init_game->render.bits_per_pixel,
			&init_game->render.size_line, &init_game->render.endian);
	if (!init_game->render.img_data)
		exit (printf("Error: failed to get image data address!\n"));
	return (0);
}

/*
 * Initializes the key states and rendering settings
 like pixel size, line size,
 * and other configurations related to input handling.
 * Arguments: init_game (game state structure).
 * No return value (void function).
 */

void	init_render_keys_and_settings(t_game *init_game)
{
	init_game->render.bits_per_pixel = 32;
	init_game->render.size_line = SCREEN_WIDTH * 4;
	init_game->render.endian = 0;
	init_game->render.keys.a = false;
	init_game->render.keys.d = false;
	init_game->render.keys.s = false;
	init_game->render.keys.w = false;
	init_game->render.keys.left = false;
	init_game->render.keys.right = false;
	init_game->render.keys.shift = false;
}

/*
 * Initializes both the rendering graphics
 and key settings by calling the
 * respective initialization functions.
 * Arguments: init_game (game state structure).
 * No return value (void function).
 */

void	init_render(t_game *init_game)
{
	init_render_graphics(init_game);
	init_render_keys_and_settings(init_game);
}
