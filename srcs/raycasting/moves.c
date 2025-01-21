/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 03:56:43 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 01:42:05 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: rotate_player
 * ------------------------
 * This function rotates the player's direction 
 * and view plane based on the 
 * specified rotation speed. It applies 
 * a 2D rotation matrix to both the 
 * player's direction vector and the camera's view plane vector.
 * 
 * game: The main game structure containing 
 * the player's current state.
 * rot_speed: The rotation speed to apply 
 * to the player's direction and view plane.
 * 
 * This function modifies the player's direction and view plane vectors by 
 * rotating them around the origin by 
 * an angle specified by `rot_speed`.
 */

void	rotate_player(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	old_plane_x = game->plane_x;
	game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
	game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);
	game->plane_x = game->plane_x * cos(rot_speed) \
		- game->plane_y * sin(rot_speed);
	game->plane_y = old_plane_x * sin(rot_speed) \
		+ game->plane_y * cos(rot_speed);
}

/* 
 * Function: move_forward
 * ----------------------
 * This function moves the player forward in 
 * the direction they are currently facing.
 * It calculates the new position based on 
 * the player's direction vector and the 
 * specified movement speed. 
 * The new position is only applied if it is valid 
 * (i.e., within the map bounds and not colliding with obstacles).
 * 
 * game: The main game structure containing 
 * the player's current state and map.
 * move_speed: The speed at which the player moves.
 * 
 * The player's position is updated 
 * if the new position does not collide with walls
 * or go out of bounds.
 */

void	move_forward(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = (game->pos_y + game->dir_x * move_speed);
	new_pos_y = (game->pos_x + game->dir_y * move_speed);
	if (new_pos_x >= 0 && new_pos_x < game->map->height
		&& new_pos_y >= 0 && new_pos_y < game->map->width)
	{
		if (game->map->grid[(int)new_pos_x][(int)new_pos_y] == 0
			&& game->map->grid[(int)game->pos_y][(int)game->pos_x] == 0)
		{
			game->pos_y = new_pos_x;
			game->pos_x = new_pos_y;
		}
	}
}

/* 
 * Function: move_backward
 * ------------------------
 * This function moves the player backward 
 * in the direction they are currently facing.
 * It calculates the new position based on 
 * the player's direction vector and the 
 * specified movement speed. 
 * The new position is only applied if it is valid 
 * (i.e., within the map bounds and not colliding with obstacles).
 * 
 * game: The main game structure containing 
 * the player's current state and map.
 * move_speed: The speed at which the player moves.
 * 
 * The player's position is updated 
 * if the new position does not collide with walls
 * or go out of bounds.
 */

void	move_backward(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = (game->pos_y - game->dir_x * move_speed);
	new_pos_y = (game->pos_x - game->dir_y * move_speed);
	if (new_pos_x >= 0 && new_pos_x < game->map->height
		&& new_pos_y >= 0 && new_pos_y < game->map->width)
	{
		if (game->map->grid[(int)new_pos_x][(int)new_pos_y] == 0
			&& game->map->grid[(int)game->pos_y][(int)game->pos_x] == 0)
		{
			game->pos_y = new_pos_x;
			game->pos_x = new_pos_y;
		}
	}
}

/* 
 * Function: move_left
 * -------------------
 * This function moves 
 * the player left (strafe left) relative to their current
 * facing direction. It uses the player's direction 
 * and rotates the movement
 * direction by 90 degrees to the left.
 * 
 * game: The main game structure 
 * containing the player's current state and map.
 * move_speed: The speed at which the player moves.
 * 
 * The player's position is updated 
 * if the new position does not collide with walls
 * or go out of bounds.
 */

void	move_left(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->pos_y + (-game->dir_y) * move_speed;
	new_pos_y = game->pos_x + (game->dir_x) * move_speed;
	if (new_pos_x >= 0 && new_pos_x < game->map->height
		&& new_pos_y >= 0 && new_pos_y < game->map->width)
	{
		if (game->map->grid[(int)new_pos_x][(int)new_pos_y] == 0
			&& game->map->grid[(int)game->pos_y][(int)game->pos_x] == 0)
		{
			game->pos_y = new_pos_x;
			game->pos_x = new_pos_y;
		}
	}
}

/* 
 * Function: move_right
 * --------------------
 * This function moves the player right (strafe right) 
 * relative to their current
 * facing direction. It uses 
 * the player's direction and rotates the movement
 * direction by 90 degrees to the right.
 * 
 * game: The main game structure containing the player's current state and map.
 * move_speed: The speed at which the player moves.
 * 
 * The player's position is updated 
 * if the new position does not collide with walls
 * or go out of bounds.
 */

void	move_right(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->pos_y + (game->dir_y) * move_speed;
	new_pos_y = game->pos_x + (-game->dir_x) * move_speed;
	if (new_pos_x >= 0 && new_pos_x < game->map->height
		&& new_pos_y >= 0 && new_pos_y < game->map->width)
	{
		if (game->map->grid[(int)new_pos_x][(int)new_pos_y] == 0
			&& game->map->grid[(int)game->pos_y][(int)game->pos_x] == 0)
		{
			game->pos_y = new_pos_x;
			game->pos_x = new_pos_y;
		}
	}
}
