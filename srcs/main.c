/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:42:38 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:43:45 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: main
 * ----------------
 * The entry point of the program that sets up the game, initializes necessary 
 * components, and enters the game loop. The main function is responsible for 
 * managing the initialization, input handling, and game execution.
 *
 * ac: The argument count passed from the command line.
 * av: The argument vector (array of strings) passed from the command line.
 * 
 * Steps in the main function:
 * 1. Checks if the user has passed the correct number of arguments.
 * 2. Initializes the game, player, and map.
 * 3. Loads the textures and sets up the rendering.
 * 4. Hooks events for user input (keyboard and mouse).
 * 5. Enters the main loop of the game, which repeatedly renders the game scene.
 */

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
