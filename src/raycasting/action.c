#include "cub3D.h"

int	move_player(int key, t_params *params)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.1;
	rot_speed = 0.05;
	if (key == KEY_W)
		move_forward(params, move_speed, 0, 0);
	else if (key == KEY_S)
		move_backward(params, move_speed, 0, 0);
	else if (key == KEY_A)
		move_left(params, move_speed, 0, 0);
	else if (key == KEY_D)
		move_right(params, move_speed, 0, 0);
	else if (key == KEY_LEFT)
		rotate_player(params, rot_speed);
	else if (key == KEY_RIGHT)
		rotate_player(params, -rot_speed);
	else if (key == KEY_ESC || key == KEY_Q)
		ft_exit(params, 0);
	return (0);
}
