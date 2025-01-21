/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_texture_sampling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:14:27 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 01:40:07 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* 
 * Function: prepare_texture_sampling
 * ----------------------------------
 * This function calculates the step size for sampling the texture and 
 * the initial texture position based on the wall slice data. It is used 
 * to prepare for texture mapping along the vertical slice of the wall.
 * 
 * data: A structure containing the current wall slice data, including 
 *       information about the texture and the height of the wall slice.
 * step: A pointer to a double where the step size 
 * for sampling will be stored.
 * texPos: A pointer to a double where the initial texture position 
 * will be stored.
 * 
 * This function calculates the step size (`step`) for traversing the texture 
 * vertically during rendering and computes the starting texture position 
 * (`texPos`) based on the vertical slice height and the screen's center.
 */

void	prepare_texture_sampling(t_wall_slice_data *data,
	double *step, double *texPos)
{
	*step = 1.0 * data->curr_texture->height / data->line_height;
	*texPos = (data->draw_start - SCREEN_HEIGHT / 2 + data->line_height / 2) \
		* (*step);
}

/* 
 * Function: get_shaded_color
 * --------------------------
 * This function retrieves the color from the texture 
 * and applies a shading effect 
 * based on the side of the wall the ray hit (front or back). 
 * The shading reduces 
 * the color intensity when the ray hits a wall from the back.
 * 
 * data: A structure containing the current wall slice data and the texture.
 * tex_y: The vertical position on the texture to sample.
 * tex_x: The horizontal position on the texture to sample.
 * ray: The ray structure, which holds the information about which side of 
 *      the wall the ray hit (either front or back).
 * 
 * This function returns the color from the texture, applying a shading effect 
 * if the ray hits the wall from the back (side = 1).
 */

unsigned int	get_shaded_color(t_wall_slice_data *data,
	int tex_y, int tex_x, t_ray *ray)
{
	unsigned int	color;

	color = data->curr_texture->addr[tex_y * data->curr_texture->width + tex_x];
	if (ray->side == 1)
		color = (color >> 1) & 0x7F7F7F;
	return (color);
}
