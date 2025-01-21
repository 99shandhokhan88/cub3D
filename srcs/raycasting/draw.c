/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:41:54 by flo-dolc           #+#    #+#             */
/*   Updated: 2025/01/21 01:41:29 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clamp_color(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->r < 0)
		color->r = 0;
	if (color->g > 255)
		color->g = 255;
	if (color->g < 0)
		color->g = 0;
	if (color->b > 255)
		color->b = 255;
	if (color->b < 0)
		color->b = 0;
}

void	render_floor_ceiling(unsigned int *img_data, t_colors *colors)
{
	int				x;
	int				y;
	unsigned int	floor_color;
	unsigned int	ceiling_color;

	y = 0;
	clamp_color(&colors->ceiling);
	clamp_color(&colors->floor);
	floor_color = (colors->floor.r << 16) | (colors->floor.g << 8) \
				| colors->floor.b;
	ceiling_color = (colors->ceiling.r << 16) | (colors->ceiling.g << 8) \
				| colors->ceiling.b;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				img_data[y * SCREEN_WIDTH + x] = ceiling_color;
			else
				img_data[y * SCREEN_WIDTH + x] = floor_color;
			x++;
		}
		y++;
	}
}

int	draw(t_game *game)
{
	int			mouse_x;
	int			mouse_y;
	t_render	*params;

	mouse_x = 0;
	mouse_y = 0;
	params = &game->render;
	if (!params || !params->mlx || !params->window
		|| !params->img || !params->img_data)
	{
		printf(RED BOLD "Error: invalid parameters in draw function!\n" RESET);
		return (1);
	}
	mlx_mouse_get_pos(params->mlx, params->window, &mouse_x, &mouse_y);
	check_cursor_rotation(game, mouse_x);
	move_player(game, params);
	ft_bzero(params->img_data,
		SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(unsigned int));
	render_floor_ceiling(params->img_data, &game->colors);
	raycasting(game, params);
	draw_minimap(game);
	mlx_put_image_to_window(params->mlx, params->window, params->img, 0, 0);
	return (0);
}
