/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:30:59 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 00:05:23 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_render_graphics(t_game *init_game)
{
	init_game->render.mlx = mlx_init();
	if (!init_game->render.mlx)
		return (printf("Error: failed to initialize mlx!\n"), 1);
	init_game->render.window = mlx_new_window(init_game->render.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!init_game->render.window)
		return (printf("Error: failed to create new window!\n"), 1);
	init_game->render.img = mlx_new_image(init_game->render.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!init_game->render.img)
		return (printf("Error: failed to create new image!\n"), 1);
	init_game->render.img_data
		= (unsigned int *)mlx_get_data_addr(init_game->render.img,
			&init_game->render.bits_per_pixel,
			&init_game->render.size_line, &init_game->render.endian);
	if (!init_game->render.img_data)
		return (printf("Error: failed to get image data address!\n"), 1);
	return (0);
}

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

void	init_render(t_game *init_game)
{
	init_render_graphics(init_game);
	init_render_keys_and_settings(init_game);
}
