/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 04:28:33 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:39:39 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: handle_pressed
 * -------------------------
 * This function handles key press events. 
 * When a key is pressed, it updates the
 * corresponding boolean value 
 * in the `game->render.keys` struct to true. 
 * This allows the game to track 
 * the player's input in real-time.
 * If the ESC key is pressed, 
 * it triggers the game to exit.
 *
 * key: The keycode representing the key 
 * that was pressed.
 * game: The game structure, which stores 
 * the current state of the game and inputs.
 *
 * Returns: Always returns 0 to satisfy 
 * the event callback function's expected return type.
 */

int	handle_pressed(int key, t_game *game)
{
	if (key == KEY_W)
		game->render.keys.w = true;
	else if (key == KEY_S)
		game->render.keys.s = true;
	else if (key == KEY_A)
		game->render.keys.a = true;
	else if (key == KEY_D)
		game->render.keys.d = true;
	else if (key == KEY_LEFT)
		game->render.keys.left = true;
	else if (key == KEY_RIGHT)
		game->render.keys.right = true;
	else if (key == KEY_SHIFT)
		game->render.keys.shift = true;
	else if (key == KEY_ESC)
		ft_exit(game, 0);
	return (0);
}

/* 
 * Function: handle_released
 * --------------------------
 * This function handles key release events. 
 * When a key is released, it updates the
 * corresponding boolean value 
 * in the `game->render.keys` struct to false. 
 * This stops the player's movement 
 * or rotation once the key is released.
 *
 * key: The keycode representing the 
 * key that was released.
 * game: The game structure, which 
 * stores the current state of the game and inputs.
 *
 * Returns: Always returns 0 to satisfy 
 * the event callback function's expected return type.
 */

int	handle_released(int key, t_game *game)
{
	if (key == KEY_W)
		game->render.keys.w = false;
	else if (key == KEY_S)
		game->render.keys.s = false;
	else if (key == KEY_A)
		game->render.keys.a = false;
	else if (key == KEY_D)
		game->render.keys.d = false;
	else if (key == KEY_LEFT)
		game->render.keys.left = false;
	else if (key == KEY_RIGHT)
		game->render.keys.right = false;
	else if (key == KEY_SHIFT)
		game->render.keys.shift = false;
	return (0);
}

/* 
 * Function: move_player
 * ----------------------
 * This function updates the player's 
 * position and rotation based on the keys 
 * that are currently pressed. 
 * It checks the state of the input keys and moves
 * or rotates the player accordingly. 
 * The movement speed is affected by whether
 * the shift key (sprint) is held down, increasing the movement speed.
 *
 * game: The game structure, which holds the player's position and other states.
 * params: A struct containing the current state of the keys pressed.
 *
 * Returns: Always returns 0 to satisfy 
 * the event callback function's expected return type.
 */

int	move_player(t_game *game, t_render *params)
{
	int		run_mul;

	run_mul = 1;
	if (params->keys.shift)
		run_mul = 3;
	if (params->keys.w)
		move_forward(game, MOVE_SPEED * run_mul);
	if (params->keys.s)
		move_backward(game, MOVE_SPEED * run_mul);
	if (params->keys.a)
		move_left(game, MOVE_SPEED * run_mul);
	if (params->keys.d)
		move_right(game, MOVE_SPEED * run_mul);
	if (params->keys.left)
		rotate_player(game, ROTATE_SPEED * run_mul);
	if (params->keys.right)
		rotate_player(game, -ROTATE_SPEED * run_mul);
	return (0);
}
