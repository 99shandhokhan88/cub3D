#include "cub3D.h"

void	clamp_color(t_color *color)
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

void	render_floor_ceiling(unsigned int *img_data, t_colors *colors)
{
	int				x;
	int				y;
	unsigned int	floor_color;
	unsigned int	ceiling_color;

	y = 0;
	clamp_color(&colors->ceiling);
	clamp_color(&colors->floor);
	floor_color = (colors->floor.r << 16) | (colors->floor.g << 8) \
				| colors->floor.b;
	ceiling_color = (colors->ceiling.r << 16) | (colors->ceiling.g << 8) \
				| colors->ceiling.b;
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


/*
int	draw(t_game *game)
{
	t_render	*params;

	params = &game->render;
	if (!params || !params->mlx || !params->window
		|| !params->img || !params->img_data)
	{
		printf("Error: Invalid parameters in draw function\n");
		return (1);
	}
	move_player(game, params);
	ft_bzero(params->img_data,
		SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(unsigned int));
	render_floor_ceiling(params->img_data, &game->colors);
	raycasting(game, params);
	draw_minimap(game);
	mlx_put_image_to_window(params->mlx, params->window, params->img, 0, 0);
	return (0);
}
*/

int draw(t_game *game)
{
    t_render    *params;
    int mouse_x, mouse_y;

    params = &game->render;

    if (!params || !params->mlx || !params->window || !params->img || !params->img_data)
    {
        printf("Error: Invalid parameters in draw function\n");
        return (1);
    }

    // Get the current mouse position
    mlx_mouse_get_pos(params->mlx, params->window, &mouse_x, &mouse_y);

    // Check and rotate the player based on the mouse or key press
    check_cursor_rotation(game, mouse_x);

    move_player(game, params);
    ft_bzero(params->img_data, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(unsigned int));
    render_floor_ceiling(params->img_data, &game->colors);
    raycasting(game, params);
    draw_minimap(game);
    mlx_put_image_to_window(params->mlx, params->window, params->img, 0, 0);

    return (0);
}