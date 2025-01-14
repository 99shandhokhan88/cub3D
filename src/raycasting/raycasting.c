#include "cub3D.h"

void	raycasting(t_game *game, t_params *params)
{
	int		x;
	t_ray	ray;

	x = 0;
	if (!params || !game || !game->map || !params->img_data)
	{
		printf("Error: Invalid parameters in raycasting\n");
		ft_exit(game, 1);
	}
	while (x < SCREEN_WIDTH)
	{
		calculate_ray(game, &ray, x);
		perform_dda(game, &ray);
		draw_wall_slice(game, params, &ray, x, 0);
		x++;
	}
}
