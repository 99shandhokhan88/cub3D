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

/* 
 * Function: calculate_wall_slice_dimensions
 * -----------------------------------------
 * This function calculates the vertical slice of the wall that will be drawn
 * on the screen for the current ray. It determines the height of the slice
 * and the range of pixels that will be affected by this slice (starting and 
 * ending pixel positions).
 * 
 * ray: The current ray being casted.
 * data: A structure to hold the slice data (height, start, end, etc.).
 */

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

/* 
 * Function: calculate_wall_x
 * -------------------------
 * This function calculates the exact point (x-coordinate) on the wall that 
 * the ray intersects. It uses the perpendicular distance from the player 
 * to determine this.
 * 
 * game: The game structure, containing the player's position.
 * ray: The current ray.
 * 
 * Returns: The fractional x-coordinate of the intersection on the wall.
 */

double	calculate_wall_x(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->pos_x + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->pos_y + ray->perp_wall_dist * ray->ray_dir_x;
	return (wall_x - floor(wall_x));
}

/* 
 * Function: select_wall_texture
 * -----------------------------
 * This function selects the correct texture for the wall the ray hits, based 
 * on which side of the grid the ray intersects (north, south, east, west).
 * 
 * game: The game structure, containing the textures.
 * ray: The current ray.
 * 
 * Returns: A pointer to the correct texture to use for drawing the wall slice.
 */

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

/* 
 * Function: calculate_tex_x
 * -------------------------
 * This function calculates the correct 
 * x-coordinate on the texture that 
 * corresponds to the current ray 
 * hit position on the wall. This is necessary
 * to ensure that the texture 
 * is mapped correctly on the wall slice.
 * 
 * data: The wall slice data, 
 * containing the wall x-coordinate.
 * ray: The current ray.
 * 
 * Returns: The x-coordinate 
 * on the texture to sample.
 */

int	calculate_tex_x(t_wall_slice_data *data, t_ray *ray)
{
	int	tex_x;

	tex_x = (int)(data->wall_x * data->curr_texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = data->curr_texture->width - tex_x - 1;
	return (tex_x);
}

/* 
 * Function: draw_wall_slice
 * -------------------------
 * This function draws a vertical slice 
 * of the wall at the current screen 
 * column (`x`) using the selected texture. 
 * It samples the texture and applies
 * the calculated shading based on the ray hit point.
 * 
 * game: The game structure, 
 * containing the current rendering context.
 * ray: The current ray.
 * x: The screen column where the wall slice is drawn.
 * y: The starting vertical position of the wall slice.
 */

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
