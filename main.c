#include "include/cub3D.h"

void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->parsed_map[i])
	{
		j = 0;
		while (game->parsed_map[i][j])
		{
			if (game->parsed_map[i][j] == 'N'
				|| game->parsed_map[i][j] == 'S'
				|| game->parsed_map[i][j] == 'E'
				|| game->parsed_map[i][j] == 'W')
			{
				game->pos_y = i + 0.5;
				game->pos_x = j + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_map(t_game *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->height = matrix_len(game->map_copy);
	map->width = find_max_line(game->map_copy, NULL);
	floodfill(game, game->pos_y, game->pos_x);
	check_flood(game);
	// print_map(game->map_copy);
	map->grid = (int **)ft_calloc(map->height, sizeof(int *));
	while (i < map->height)
	{
		j = 0;
		map->grid[i] = (int *)ft_calloc(map->width, sizeof(int));
		while (j < map->width)
		{
			if (j < (int)ft_strlen(game->map_copy[i]))
			{
				if (game->map_copy[i][j] == '1')
					map->grid[i][j] = 1;
				else if (game->map_copy[i][j] == '2')
					map->grid[i][j] = 2;
			}
			j++;
		}
		i++;
	}
}

int	init_render(t_game *params)
{
	params->render.mlx = mlx_init();
	if (!params->render.mlx)
		return (printf("Error: Failed to initialize mlx\n"), 1);
	params->render.window = mlx_new_window(params->render.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!params->render.window)
		return (printf("Error: Failed to create new window\n"), 1);
	params->render.img = mlx_new_image(params->render.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!params->render.img)
		return (printf("Error: Failed to create new image\n"), 1);
	params->render.img_data = (unsigned int *)mlx_get_data_addr(params->render.img,
			&params->render.bits_per_pixel, &params->render.size_line, &params->render.endian);
	if (!params->render.img_data)
		return (printf("Error: Failed to get image data address\n"), 1);
	params->render.bits_per_pixel = 32;
	params->render.size_line = SCREEN_WIDTH * 4;
	params->render.endian = 0;
	params->render.keys.a = false;
	params->render.keys.d = false;
	params->render.keys.s = false;
	params->render.keys.w = false;
	params->render.keys.left = false;
	params->render.keys.right = false;
	params->render.keys.shift = false;


	//mlx_mouse_hide(params->render.mlx, params->render.window);

   // mlx_hook(params->render.window, 6, 1L << 6, mouse_move, params);


	return (0);
}

void	init_game(t_game **game)
{
	*game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!(*game))
		return ;
	(*game)->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!(*game)->map)
	{
		free(*game);
		*game = NULL;
		return ;
	}
}

void	init_player(t_game *game)
{
	find_player_position(game);
	if (game->parser.player_facing == NORTH)
	{
		game->dir_x = -1;
		game->plane_y = 0.66;
	}
	else if (game->parser.player_facing == SOUTH)
	{
		game->dir_x = 1;
		game->plane_y = -0.66;
	}
	else if (game->parser.player_facing == EAST)
	{
		game->dir_y = 1;
		game->plane_x = 0.66;
	}
	else if (game->parser.player_facing == WEST)
	{
		game->dir_y = -1;
		game->plane_x = -0.66;
	}
}



int main(int ac, char **av)
{
    t_game *game;

    if (ac != 2)
        my_error(av);

    init_game(&game);
    if (!game)
        return (printf("Error: Failed to initialize game\n"), 1);

    parser(av[1], game);
    if (parsing_map(game))
        return (free_parse(game), 1);

    init_render(game);
    init_player(game);
    init_map(game, game->map);

    load_textures(game);

    mlx_hook(game->render.window, 2, 1L << 0, handle_pressed, game);    // Key press event
    mlx_hook(game->render.window, 3, 1L << 1, handle_released, game);  // Key release event
    mlx_hook(game->render.window, 4, 1L << 2, handle_mouse_press, game);  // Mouse press event
    mlx_hook(game->render.window, 5, 1L << 3, handle_mouse_release, game); // Mouse release event
    mlx_hook(game->render.window, 17, 1L << 17, close_window, game); // Window close event

    mlx_loop_hook(game->render.mlx, draw, game);
    mlx_loop(game->render.mlx);

    return (0);
}

