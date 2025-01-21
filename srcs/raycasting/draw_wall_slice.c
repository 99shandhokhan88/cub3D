/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:05:32 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:48:07 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_wall_slice_dimensions(t_ray *ray, t_wall_slice_data *data)
{
	data->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist) * 1.2;
	data->draw_start = -(data->line_height) / 2 + SCREEN_HEIGHT / 2;
	data->draw_end = (data->line_height) / 2 + SCREEN_HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_end >= SCREEN_HEIGHT)
		data->draw_end = SCREEN_HEIGHT - 1;
}

double	calculate_wall_x(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->pos_x + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->pos_y + ray->perp_wall_dist * ray->ray_dir_x;
	return (wall_x - floor(wall_x));
}

t_texture	*select_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (&game->textures.east);
		return (&game->textures.west);
	}
	else
	{
		if (ray->step_y > 0)
			return (&game->textures.south);
		return (&game->textures.north);
	}
}

int	calculate_tex_x(t_wall_slice_data *data, t_ray *ray)
{
	int	tex_x;

	tex_x = (int)(data->wall_x * data->curr_texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = data->curr_texture->width - tex_x - 1;
	return (tex_x);
}

void	draw_wall_slice(t_game *game, t_ray *ray, int x, int y)
{
	t_wall_slice_data	data;
	double				step;
	double				tex_pos;
	int					tex_y;
	unsigned int		color;

	calculate_wall_slice_dimensions(ray, &data);
	data.wall_x = calculate_wall_x(game, ray);
	data.curr_texture = select_wall_texture(game, ray);
	data.tex_x = calculate_tex_x(&data, ray);
	prepare_texture_sampling(&data, &step, &tex_pos);
	y = data.draw_start;
	while (y <= data.draw_end)
	{
		if (y >= 0 && y < SCREEN_HEIGHT && x >= 0 && x < SCREEN_WIDTH)
		{
			tex_y = (int)tex_pos & (data.curr_texture->height - 1);
			tex_pos += step;
			color = get_shaded_color(&data, tex_y, data.tex_x, ray);
			game->render.img_data[y * SCREEN_WIDTH + x] = color;
		}
		y++;
	}
}
