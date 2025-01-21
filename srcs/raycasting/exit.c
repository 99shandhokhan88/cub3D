/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:21:57 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:41:44 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: close_window
 * -----------------------
 * This function is called when the user closes the window. It exits the 
 * game gracefully by calling the `ft_exit` function.
 * 
 * game: The main game structure containing the current game state.
 * 
 * Returns: 0 to indicate the window was closed successfully.
 */

int	close_window(t_game *game)
{
	ft_exit(game, 0);
	return (0);
}

/* 
 * Function: free_matrix
 * ----------------------
 * This function frees the memory allocated for the game map. It iterates 
 * through each row and frees them individually, followed by freeing the 
 * overall grid and the map structure itself.
 * 
 * map: A pointer to the map structure that needs to be freed.
 */

void	free_matrix(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map->height > i)
		free(map->grid[i++]);
	free(map->grid);
	free(map);
}

/* 
 * Function: free_textures_path
 * ----------------------------
 * This function frees the file paths of the textures (north, south, east, 
 * west) stored in the `textures` structure. If a texture path is not NULL, 
 * it will be freed.
 * 
 * textures: A pointer to the textures structure containing texture paths.
 */

void	free_textures_path(t_textures *textures)
{
	if (textures->north.path)
		free(textures->north.path);
	if (textures->south.path)
		free(textures->south.path);
	if (textures->east.path)
		free(textures->east.path);
	if (textures->west.path)
		free(textures->west.path);
}

/* 
 * Function: free_textures
 * ------------------------
 * This function frees the textures loaded into memory, including their 
 * associated images (north, south, east, west), by destroying them using 
 * the `mlx_destroy_image` function. It also frees the texture paths.
 * 
 * game: The main game structure containing the textures to be freed.
 */

void	free_textures(t_game *game)
{
	free_textures_path(&game->textures);
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

/* 
 * Function: ft_exit
 * -----------------
 * This function is used to free all allocated 
 * memory and resources before 
 * exiting the program. It destroys the window, 
 * frees textures, closes the 
 * display, and finally frees all game-related 
 * structures and exits with the 
 * specified code.
 * 
 * game: The main game structure containing 
 * all the resources to be freed.
 * code: The exit code to return upon termination.
 */

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
		free_matrix(game->map);
	if (game->parsed_map)
		free_map(game->parsed_map);
	if (game->map_copy)
		free_map(game->map_copy);
	free(game);
	exit(code);
}
