#include "include/cub3D.h"

void transfer_parsed_data(t_game *game)
{
	// Transfer map data
	game->map->height = game->parser.len_y;
	game->map->width = find_max_line(game->parsed_map, 0);

	// Allocate memory for the map grid
	game->map->grid = (int **)ft_calloc(game->map->height, sizeof(int *));
	for (int i = 0; i < game->map->height; i++)
	{
		game->map->grid[i] = (int *)ft_calloc(game->map->width, sizeof(int));
		for (int j = 0; j < game->map->width; j++)
		{
			if (j < (int)ft_strlen(game->parsed_map[i]))
				game->map->grid[i][j] = game->parsed_map[i][j] == '1' ? 1 : 0;
			else
				game->map->grid[i][j] = 0;
		}
	}

	// Set initial player position and direction
	for (int i = 0; i < game->map->height; i++)
	{
		for (int j = 0; j < game->map->width; j++)
		{
			if (game->parsed_map[i][j] == 'N' || game->parsed_map[i][j] == 'S' || game->parsed_map[i][j] == 'E' || game->parsed_map[i][j] == 'W')
			{
				game->posX = i + 0.5;
				game->posY = j + 0.5;

				// Set initial direction and plane based on player orientation
				switch (game->parsed_map[i][j])
				{
				case 'N':
					game->dirX = -1;
					game->dirY = 0;
					game->planeX = 0;
					game->planeY = 0.66;
					break;
				case 'S':
					game->dirX = 1;
					game->dirY = 0;
					game->planeX = 0;
					game->planeY = -0.66;
					break;
				case 'E':
					game->dirX = 0;
					game->dirY = 1;
					game->planeX = 0.66;
					game->planeY = 0;
					break;
				case 'W':
					game->dirX = 0;
					game->dirY = -1;
					game->planeX = -0.66;
					game->planeY = 0;
					break;
				}
				break;
			}
		}
	}
}

int init_params2(t_params *params)
{
	params->mlx = mlx_init();
	if (!params->mlx)
		return (printf("Error: Failed to initialize mlx\n"), 1);

	params->window = mlx_new_window(params->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!params->window)
		return (printf("Error: Failed to create new window\n"), 1);

	params->img = mlx_new_image(params->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!params->img)
		return (printf("Error: Failed to create new image\n"), 1);

	params->img_data = (unsigned int *)mlx_get_data_addr(params->img, &params->bits_per_pixel, &params->size_line, &params->endian);
	if (!params->img_data)
		return (printf("Error: Failed to get image data address\n"), 1);

	params->bits_per_pixel = 32;
	params->size_line = SCREEN_WIDTH * 4;
	params->endian = 0;

	params->keys.a = false;
	params->keys.d = false;
	params->keys.s = false;
	params->keys.w = false;
	params->keys.left = false;
	params->keys.right = false;
	params->keys.shift = false;
	return (0);
}

void	init_game(t_game **game)
{
	*game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!(*game))
		return;
	(*game)->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!(*game)->map)
	{
		free(*game);
		*game = NULL;
		return;
	}
}

int main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		my_error(av);
	init_game(&game);
	if (!game)
		return (printf("Error: Failed to initialize game\n"), 1);
	init_params2(&game->params);
	parser(av[1], game);
	if (parsing_map(game))
		return (free_parse(game), 1);
	game->parser.len_y = matrix_len(game->parsed_map);
	printf("napoli\n");
	// TRANSFER PARSED DATA TO RAYCASTING STRUCTURES
	transfer_parsed_data(&game);
	// params.mlx = mlx_init();
	// params.window = mlx_new_window(params.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	free_parse(game);
	load_textures(&game);
	mlx_hook(game->params.window, 2, 1L << 0, handle_pressed, &game);
	mlx_hook(game->params.window, 3, 1L << 1, handle_released, &game);
	mlx_hook(game->params.window, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game->params.mlx, draw, &game);
	mlx_loop(game->params.mlx);
	return (0);
}
