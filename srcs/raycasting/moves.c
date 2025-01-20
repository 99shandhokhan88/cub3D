/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:48:45 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 19:48:46 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
