/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:30:33 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 23:42:16 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		my_error(av);
	init_game(&game);
	if (!game)
		return (printf("Error: failed to initialize game!\n"), 1);
	parser(av[1], game);
	if (parsing_map(game))
		return (free_parser(game), 1);
	init_render(game);
	init_player(game);
	init_map(game, game->map);
	load_textures(game);
	mlx_hook(game->render.window, 2, 1L << 0, handle_pressed, game);
	mlx_hook(game->render.window, 3, 1L << 1, handle_released, game);
	mlx_hook(game->render.window, 4, 1L << 2, handle_mouse_press, game);
	mlx_hook(game->render.window, 5, 1L << 3, handle_mouse_release, game);
	mlx_hook(game->render.window, 17, 1L << 17, close_window, game);
	mlx_loop_hook(game->render.mlx, draw, game);
	mlx_loop(game->render.mlx);
	return (0);
}
