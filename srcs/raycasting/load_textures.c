/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:04:01 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 01:51:24 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: load_single_texture
 * -----------------------------
 * This function loads a single texture 
 * from a specified file path. It uses 
 * the `mlx_xpm_file_to_image` function 
 * to load the texture, retrieves the 
 * data address, and ensures the texture 
 * is properly loaded by checking 
 * for errors at each stage.
 * 
 * game: The main game structure that holds the rendering context.
 * texture: The texture structure that will hold the texture data.
 * path: The file path to the texture.
 * 
 * If any error occurs during the loading process, the game will exit.
 */

void	load_single_texture(t_game *game, t_texture *texture, char *path)
{
	if (!path || !path[0])
	{
		printf(RED BOLD "Error: empty texture path!\n" RESET);
		ft_exit(game, 1);
	}
	texture->img = mlx_xpm_file_to_image(game->render.mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf(RED BOLD "Error: failed to load texture: \n%s\n" RESET, path);
		ft_exit(game, 1);
	}
	texture->addr = (unsigned int *)mlx_get_data_addr(texture->img,
			&texture->bits_per_pixel,
			&texture->size_line,
			&texture->endian);
	if (!texture->addr)
	{
		printf("Error: failed to get texture data address: \n%s\n", path);
		mlx_destroy_image(game->render.mlx, texture->img);
		ft_exit(game, 1);
	}
}

/* 
 * Function: load_textures
 * ------------------------
 * This function loads all four textures (north, south, east, west) 
 * for the 
 * game by calling `load_single_texture` for each of them. 
 * It also checks if 
 * the texture paths are valid before loading them.
 * 
 * game: The main game structure containing 
 * the paths for the textures.
 * 
 * If any texture fails to load, or if the paths are invalid, 
 * the game exits.
 */

void	load_textures(t_game *game)
{
	if (!game || !game->textures.east.path || !game->textures.north.path
		|| !game->textures.south.path || !game->textures.west.path)
	{
		printf("Error: invalid parameters for texture loading!\n");
		ft_exit(game, 1);
	}
	load_single_texture(game, &game->textures.north, game->textures.north.path);
	load_single_texture(game, &game->textures.south, game->textures.south.path);
	load_single_texture(game, &game->textures.east, game->textures.east.path);
	load_single_texture(game, &game->textures.west, game->textures.west.path);
}
