#include "cub3D.h"

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
