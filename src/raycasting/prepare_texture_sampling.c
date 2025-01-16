#include "cub3D.h"

void	prepare_texture_sampling(t_wall_slice_data *data,
	double *step, double *texPos)
{
	*step = 1.0 * data->curr_texture->height / data->lineHeight;
	*texPos = (data->drawStart - SCREEN_HEIGHT / 2 + data->lineHeight / 2) \
		* (*step);
}

unsigned int	get_shaded_color(t_wall_slice_data *data,
	int texY, int texX, t_ray *ray)
{
	unsigned int	color;

	color = data->curr_texture->addr[texY * data->curr_texture->width + texX];
	if (ray->side == 1)
		color = (color >> 1) & 0x7F7F7F;
	return (color);
}
