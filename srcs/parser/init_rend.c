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
 * Arguments: init_rend (render state structure).
 * Returns: 0 on success, exits with error message on failure.
 */

int	init_render_graphics(t_render *init_rend)
{
	init_rend->mlx = mlx_init();
	if (!init_rend->mlx)
		exit (printf("Error: failed to initialize mlx!\n"));
	init_rend->window = mlx_new_window(init_rend->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!init_rend->window)
		exit (printf("Error: failed to create new window!\n"));
	init_rend->img = mlx_new_image(init_rend->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!init_rend->img)
		exit (printf("Error: failed to create new image!\n"));
	init_rend->img_data
		= (unsigned int *)mlx_get_data_addr(init_rend->img,
			&init_rend->bits_per_pixel,
			&init_rend->size_line, &init_rend->endian);
	if (!init_rend->img_data)
		exit (printf("Error: failed to get image data address!\n"));
	return (0);
}

/*
 * Initializes the key states and rendering settings
 like pixel size, line size,
 * and other configurations related to input handling.
 * Arguments: init_rend (render state structure).
 * No return value (void function).
 */

void	init_render_keys_and_settings(t_render *init_rend)
{
	init_rend->bits_per_pixel = 32;
	init_rend->size_line = SCREEN_WIDTH * 4;
	init_rend->endian = 0;
	init_rend->keys.a = false;
	init_rend->keys.d = false;
	init_rend->keys.s = false;
	init_rend->keys.w = false;
	init_rend->keys.left = false;
	init_rend->keys.right = false;
	init_rend->keys.shift = false;
	init_rend->keys.mouse_pressed = false;
}

/*
 * Initializes both the rendering graphics
 and key settings by calling the
 * respective initialization functions.
 * Arguments: init_render (render state structure).
 * No return value (void function).
 */

void	init_render(t_render *init_rend)
{
	init_render_graphics(init_rend);
	init_render_keys_and_settings(init_rend);
}
