#include "cub3D.h"

int	handle_pressed(int key, t_params *params)
{
	if (key == KEY_W)
		params->keys.w = true;
	else if (key == KEY_S)
		params->keys.s = true;
	else if (key == KEY_A)
		params->keys.a = true;
	else if (key == KEY_D)
		params->keys.d = true;
	else if (key == KEY_LEFT)
		params->keys.left = true;
	else if (key == KEY_RIGHT)
		params->keys.right = true;
	else if (key == KEY_SHIFT)
		params->keys.shift = true;
	else if (key == KEY_ESC || key == KEY_Q)
		ft_exit(params, 0);
	return (0);
}

int	handle_released(int key, t_params *params)
{
	if (key == KEY_W)
		params->keys.w = false;
	else if (key == KEY_S)
		params->keys.s = false;
	else if (key == KEY_A)
		params->keys.a = false;
	else if (key == KEY_D)
		params->keys.d = false;
	else if (key == KEY_LEFT)
		params->keys.left = false;
	else if (key == KEY_RIGHT)
		params->keys.right = false;
	else if (key == KEY_SHIFT)
		params->keys.shift = false;
	return (0);
}

int	move_player(t_params *params)
{
	double	move_speed;
	int		run_mul;

	run_mul = 1;
	if (params->keys.shift)
		run_mul = 3;
	move_speed = MOVE_SPEED * run_mul;
	if (params->keys.w)
		move_forward(params, move_speed);
	if (params->keys.s)
		move_backward(params, move_speed);
	if (params->keys.a)
		move_left(params, move_speed);
	if (params->keys.d)
		move_right(params, move_speed);
	if (params->keys.left)
		rotate_player(params, ROTATE_SPEED);
	if (params->keys.right)
		rotate_player(params, -ROTATE_SPEED);
	return (0);
}
