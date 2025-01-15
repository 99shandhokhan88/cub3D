#include "cub3D.h"

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
	else if (key == KEY_ESC || key == KEY_Q)
		ft_exit(game, 0);
	return (0);
}

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

int	move_player(t_game *game, t_render *params)
{
	double	move_speed;
	int		run_mul;

	run_mul = 1;
	if (params->keys.shift)
		run_mul = 3;
	move_speed = MOVE_SPEED * run_mul;
	if (params->keys.w)
		move_forward(game, move_speed);
	if (params->keys.s)
		move_backward(game, move_speed);
	if (params->keys.a)
		move_left(game, move_speed);
	if (params->keys.d)
		move_right(game, move_speed);
	if (params->keys.left)
		rotate_player(game, ROTATE_SPEED);
	if (params->keys.right)
		rotate_player(game, -ROTATE_SPEED);
	return (0);
}
