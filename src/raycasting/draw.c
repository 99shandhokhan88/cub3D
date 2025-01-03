
#include "../include/cub3D.h"

void render_floor_ceiling(unsigned int *img_data, t_colors *colors)
{
    int y, x;
    unsigned int floor_color;
    unsigned int ceiling_color;

    y = 0;

    // Clamping the color components to ensure they are within the 0-255 range
    for (int i = 0; i < 3; i++) {
        if (colors->ceiling[i] > 255) colors->ceiling[i] = 255;
        if (colors->ceiling[i] < 0) colors->ceiling[i] = 0;

        if (colors->floor[i] > 255) colors->floor[i] = 255;
        if (colors->floor[i] < 0) colors->floor[i] = 0;
    }

    // Construct color values (0xRRGGBB format)
    floor_color = (colors->floor[0] << 16) | (colors->floor[1] << 8) | colors->floor[2];
    ceiling_color = (colors->ceiling[0] << 16) | (colors->ceiling[1] << 8) | colors->ceiling[2];

    // Debugging prints
    //printf("Ceiling color: R=%d, G=%d, B=%d\n", colors->ceiling[0], colors->ceiling[1], colors->ceiling[2]);
    //printf("Floor color: R=%d, G=%d, B=%d\n", colors->floor[0], colors->floor[1], colors->floor[2]);

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


int	draw(void *param)
{
	t_params	*params;

	params = (t_params *)param;
if (!params || !params->mlx || !params->window || !params->img || !params->img_data)
{
    printf("Error: Invalid parameters in draw function\n");
    return (1);
}

	set_to_zero(params->img_data, 0,
		SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(unsigned int));
	render_floor_ceiling(params->img_data, params->game->colors);
	raycasting(params);
	mlx_put_image_to_window(params->mlx, params->window, params->img, 0, 0);
	return (0);
}
