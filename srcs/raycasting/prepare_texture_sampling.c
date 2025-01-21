/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_texture_sampling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:14:27 by flo-dolc           #+#    #+#             */
/*   Updated: 2025/01/21 01:40:07 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	prepare_texture_sampling(t_wall_slice_data *data,
	double *step, double *texPos)
{
	*step = 1.0 * data->curr_texture->height / data->line_height;
	*texPos = (data->draw_start - SCREEN_HEIGHT / 2 + data->line_height / 2) \
		* (*step);
}

unsigned int	get_shaded_color(t_wall_slice_data *data,
	int tex_y, int tex_x, t_ray *ray)
{
	unsigned int	color;

	color = data->curr_texture->addr[tex_y * data->curr_texture->width + tex_x];
	if (ray->side == 1)
		color = (color >> 1) & 0x7F7F7F;
	return (color);
}
