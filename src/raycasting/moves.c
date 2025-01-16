#include "cub3D.h"

void	rotate_player(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dirX;
	old_plane_x = game->planeX;
	game->dirX = game->dirX * cos(rot_speed) - game->dirY * sin(rot_speed);
	game->dirY = old_dir_x * sin(rot_speed) + game->dirY * cos(rot_speed);
	game->planeX = game->planeX * cos(rot_speed) \
		- game->planeY * sin(rot_speed);
	game->planeY = old_plane_x * sin(rot_speed) + game->planeY * cos(rot_speed);
}

void	move_forward(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = (game->pos_y + game->dirX * move_speed);
	new_pos_y = (game->pos_x + game->dirY * move_speed);
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

void	move_backward(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = (game->pos_y - game->dirX * move_speed);
	new_pos_y = (game->pos_x - game->dirY * move_speed);
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

void	move_left(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->pos_y + (-game->dirY) * move_speed;
	new_pos_y = game->pos_x + (game->dirX) * move_speed;
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

void	move_right(t_game *game, double move_speed)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = game->pos_y + (game->dirY) * move_speed;
	new_pos_y = game->pos_x + (-game->dirX) * move_speed;
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
