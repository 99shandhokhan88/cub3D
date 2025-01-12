#include "cub3D.h"

void clamp_color(t_color *color)
{
	if (color->r > 255)
		color->r = 255;
	if (color->r < 0)
		color->r = 0;

	if (color->g > 255)
		color->g = 255;
	if (color->g < 0)
		color->g = 0;

	if (color->b > 255)
		color->b = 255;
	if (color->b < 0)
		color->b = 0;
}

void render_floor_ceiling(unsigned int *img_data, t_colors *colors)
{
	int y, x;
	unsigned int floor_color;
	unsigned int ceiling_color;

	y = 0;

	// Clamping the color components to ensure they are within the 0-255 range
	clamp_color(&colors->ceiling);
	clamp_color(&colors->floor);

	// Construct color values (0xRRGGBB format)
	floor_color = (colors->floor.r << 16) | (colors->floor.g << 8) | colors->floor.b;
	ceiling_color = (colors->ceiling.r << 16) | (colors->ceiling.g << 8) | colors->ceiling.b;

	// Debugging prints
	// printf("Ceiling color: R=%d, G=%d, B=%d\n", colors->ceiling.r, colors->ceiling.g, colors->ceiling.b);
	// printf("Floor color: R=%d, G=%d, B=%d\n", colors->floor.r, colors->floor.g, colors->floor.b);

	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				img_data[y * SCREEN_WIDTH + x] = ceiling_color;
			else
				img_data[y * SCREEN_WIDTH + x] = floor_color;
			x++;
		}
		y++;
	}
}

int draw(t_params *params)
{
	if (!params || !params->mlx || !params->window || !params->img || !params->img_data)
	{
		printf("Error: Invalid parameters in draw function\n");
		return (1);
	}

	ft_bzero(params->img_data,
			 SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(unsigned int));
	render_floor_ceiling(params->img_data, params->game->colors);
	raycasting(params);
	mlx_put_image_to_window(params->mlx, params->window, params->img, 0, 0);
	return (0);
}
