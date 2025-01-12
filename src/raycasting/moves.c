#include "cub3D.h"

void	rotate_player(t_params *params, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = params->dirX;
	old_plane_x = params->planeX;
	params->dirX = params->dirX * cos(rot_speed) - params->dirY * sin(rot_speed);
	params->dirY = old_dir_x * sin(rot_speed) + params->dirY * cos(rot_speed);
	params->planeX = params->planeX * cos(rot_speed) - params->planeY * sin(rot_speed);
	params->planeY = old_plane_x * sin(rot_speed) + params->planeY * cos(rot_speed);
}

void	move_forward(t_params *params,
				double move_speed, double new_pos_x, double new_pos_y)
{
	int	check_x1;
	int	check_y1;
	int	check_x2;
	int	check_y2;

	new_pos_x = (params->posX + params->dirX * move_speed) - 0.0042;
	new_pos_y = (params->posY + params->dirY * move_speed) - 0.0042;
	if (new_pos_x >= 0 && new_pos_x < params->game->map->height && new_pos_y >= 0 && new_pos_y < params->game->map->width)
	{
		check_x1 = (int)new_pos_x;
		check_y1 = (int)params->posY;
		check_x2 = (int)params->posX;
		check_y2 = (int)new_pos_y;
		if (params->game->map->grid[check_x1][check_y1] == 0 &&
			params->game->map->grid[check_x2][check_y2] == 0)
		{
			params->posX = new_pos_x;
			params->posY = new_pos_y;
		}
	}
}

void	move_backward(t_params *params,
				double move_speed, double new_pos_x, double new_pos_y)
{
	int	check_x1;
	int	check_y1;
	int	check_x2;
	int	check_y2;

	new_pos_x = (params->posX - params->dirX * move_speed) + 0.0042;
	new_pos_y = (params->posY - params->dirY * move_speed) + 0.0042;
	if (new_pos_x >= 0 && new_pos_x < params->game->map->height && new_pos_y >= 0 && new_pos_y < params->game->map->width)
	{
		check_x1 = (int)new_pos_x;
		check_y1 = (int)params->posY;
		check_x2 = (int)params->posX;
		check_y2 = (int)new_pos_y;
		if (params->game->map->grid[check_x1][check_y1] == 0 &&
			params->game->map->grid[check_x2][check_y2] == 0)
		{
			params->posX = new_pos_x;
			params->posY = new_pos_y;
		}
	}
}

void	move_left(t_params *params,
				double move_speed, double new_pos_x, double new_pos_y)
{
	int	check_x1;
	int	check_y1;
	int	check_x2;
	int	check_y2;

	new_pos_x = params->posX + (-params->dirY) * move_speed;
	new_pos_y = params->posY + (params->dirX) * move_speed;
	if (new_pos_x >= 0 && new_pos_x < params->game->map->height && new_pos_y >= 0 && new_pos_y < params->game->map->width)
	{
		check_x1 = (int)new_pos_x;
		check_y1 = (int)params->posY;
		check_x2 = (int)params->posX;
		check_y2 = (int)new_pos_y;
		if (params->game->map->grid[check_x1][check_y1] == 0 &&
			params->game->map->grid[check_x2][check_y2] == 0)
		{
			params->posX = new_pos_x - 0.0042;
			params->posY = new_pos_y - 0.0042;
		}
	}
}

void	move_right(t_params *params,
				double move_speed, double new_pos_x, double new_pos_y)
{
	int	check_x1;
	int	check_y1;
	int	check_x2;
	int	check_y2;

	new_pos_x = params->posX + (params->dirY) * move_speed;
	new_pos_y = params->posY + (-params->dirX) * move_speed;
	if (new_pos_x >= 0 && new_pos_x < params->game->map->height && new_pos_y >= 0 && new_pos_y < params->game->map->width)
	{
		check_x1 = (int)new_pos_x;
		check_y1 = (int)params->posY;
		check_x2 = (int)params->posX;
		check_y2 = (int)new_pos_y;
		if (params->game->map->grid[check_x1][check_y1] == 0 &&
			params->game->map->grid[check_x2][check_y2] == 0)
		{
			params->posX = new_pos_x - 0.0042;
			params->posY = new_pos_y - 0.0042;
		}
	}
}
