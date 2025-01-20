/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:48:50 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 23:35:29 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	rotate_player(game, ROTATE_SPEED);
	return (0);
}

int	handle_mouse_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->render.keys.mouse_pressed = true;
	return (0);
}

int	handle_mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->render.keys.mouse_pressed = false;
	return (0);
}

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
