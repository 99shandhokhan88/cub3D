/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_texture_sampling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:04:51 by vzashev           #+#    #+#             */
/*   Updated: 2024/12/30 18:45:46 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	prepare_texture_sampling(t_wall_slice_data *data,
		double *step, double *texPos)
{
	*step = 1.0 * data->current_texture->height / data->lineHeight;
	*texPos = (data->drawStart - SCREEN_HEIGHT
			/ 2 + data->lineHeight / 2) * (*step);
}

unsigned int	get_shaded_color(t_wall_slice_data *data,
		int texY, int texX, t_ray *ray)
{
	unsigned int	color;

	color = data->current_texture->addr[texY
		* data->current_texture->width + texX];
	if (ray->side == 1)
		color = (color >> 1) & 0x7F7F7F;
	return (color);
}
