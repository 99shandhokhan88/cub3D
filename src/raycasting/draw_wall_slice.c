#include "cub3D.h"

void	calculate_wall_slice_dimensions(t_ray *ray, t_wall_slice_data *data)
{
	data->lineHeight = (int)(SCREEN_HEIGHT / ray->perpWallDist) * 1.2;
	data->drawStart = -(data->lineHeight) / 2 + SCREEN_HEIGHT / 2;
	data->drawEnd = (data->lineHeight) / 2 + SCREEN_HEIGHT / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	if (data->drawEnd >= SCREEN_HEIGHT)
		data->drawEnd = SCREEN_HEIGHT - 1;
}

double	calculate_wall_x(t_game *game, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->pos_x + ray->perpWallDist * ray->rayDirY;
	else
		wall_x = game->pos_y + ray->perpWallDist * ray->rayDirX;
	return (wall_x - floor(wall_x));
}

t_texture	*select_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->stepX > 0)
			return (&game->textures.east);
		return (&game->textures.west);
	}
	else
	{
		if (ray->stepY > 0)
			return (&game->textures.south);
		return (&game->textures.north);
	}
}

int	calculate_tex_x(t_wall_slice_data *data, t_ray *ray)
{
	int	tex_x;

	tex_x = (int)(data->wallX * data->curr_texture->width);
	if ((ray->side == 0 && ray->rayDirX > 0)
		|| (ray->side == 1 && ray->rayDirY < 0))
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
	data.wallX = calculate_wall_x(game, ray);
	data.curr_texture = select_wall_texture(game, ray);
	data.texX = calculate_tex_x(&data, ray);
	prepare_texture_sampling(&data, &step, &tex_pos);
	y = data.drawStart;
	while (y <= data.drawEnd)
	{
		if (y >= 0 && y < SCREEN_HEIGHT && x >= 0 && x < SCREEN_WIDTH)
		{
			tex_y = (int)tex_pos & (data.curr_texture->height - 1);
			tex_pos += step;
			color = get_shaded_color(&data, tex_y, data.texX, ray);
			game->render.img_data[y * SCREEN_WIDTH + x] = color;
		}
		y++;
	}
}
