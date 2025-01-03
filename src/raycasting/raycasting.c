/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:37:11 by vzashev           #+#    #+#             */
/*   Updated: 2024/12/30 18:45:50 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	raycasting(t_params *params)
{
	int		x;
	t_ray	ray;

	x = 0;
	if (!params || !params->game || !params->game->map || !params->img_data)
	{
		printf("Error: Invalid parameters in raycasting\n");
		ft_exit(params, 1);
	}
	while (x < SCREEN_WIDTH)
	{
		calculate_ray(params, &ray, x);
		perform_dda(params, &ray);
		draw_wall_slice(params, &ray, x, 0);
		x++;
	}
}
