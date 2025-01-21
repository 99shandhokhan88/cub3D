/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:41:29 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:42:59 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: mouse_move
 * --------------------
 * This function handles mouse movement 
 * events and updates the player's rotation.
 * It adjusts the player's direction based 
 * on the mouse's position.
 * 
 * x: The x-coordinate of the mouse (not used here).
 * y: The y-coordinate of the mouse (not used here).
 * game: The main game structure containing the current game state.
 * 
 * The function is called when the mouse moves 
 * and triggers a player's rotation.
 */

int	mouse_move(int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	rotate_player(game, ROTATE_SPEED);
	return (0);
}

/* 
 * Function: handle_mouse_press
 * -----------------------------
 * This function handles mouse press events, 
 * specifically for the left mouse button.
 * It updates the mouse state in the game when the button is pressed.
 * 
 * button: The mouse button that was pressed (1 for the left button).
 * x: The x-coordinate of the mouse (not used here).
 * y: The y-coordinate of the mouse (not used here).
 * game: The main game structure containing the current game state.
 * 
 * The function updates the mouse pressed 
 * state when the left mouse button is pressed.
 */

int	handle_mouse_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->render.keys.mouse_pressed = true;
	return (0);
}

/* 
 * Function: handle_mouse_release
 * ------------------------------
 * This function handles mouse release events, specifically 
 * for the left mouse button.
 * It updates the mouse state in the game when the button is released.
 * 
 * button: The mouse button that was released (1 for the left button).
 * x: The x-coordinate of the mouse (not used here).
 * y: The y-coordinate of the mouse (not used here).
 * game: The main game structure containing the current game state.
 * 
 * The function updates the mouse pressed state 
 * when the left mouse button is released.
 */

int	handle_mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->render.keys.mouse_pressed = false;
	return (0);
}

/* 
 * Function: check_cursor_rotation
 * -------------------------------
 * This function checks the position 
 * of the mouse and adjusts the player's rotation
 * based on the mouse's 
 * horizontal position (left or right of the screen center).
 * 
 * game: The main game structure containing 
 * the current game state.
 * mouse_x: The x-coordinate of the mouse.
 * 
 * It compares the mouse's x-coordinate 
 * to the screen center and rotates the player 
 * accordingly. If the mouse is on the left side 
 * of the screen, the player rotates 
 * in one direction, and if it's on the right side, 
 * the player rotates in the opposite direction.
 */

void	check_cursor_rotation(t_game *game, int mouse_x)
{
	int	screen_center;

	screen_center = SCREEN_WIDTH / 2;
	if (game->render.keys.left)
		rotate_player(game, ROTATE_SPEED);
	else if (game->render.keys.right)
		rotate_player(game, -ROTATE_SPEED);
	else if (game->render.keys.mouse_pressed)
	{
		if (mouse_x < screen_center)
			rotate_player(game, ROTATE_SPEED);
		else if (mouse_x > screen_center)
			rotate_player(game, -ROTATE_SPEED);
	}
}
