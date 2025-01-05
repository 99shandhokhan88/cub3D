
#include "include/cub3D.h"

char	*copy_str(char *copy, const char *original, int n)
{
	int	i;

	i = 0;
	while (original[i] && i < n)
	{
		copy[i] = original[i];
		i++;
	}
	while (i < n)
		copy[i++] = '\0';
	return (copy);
}

void transfer_parsed_data(t_params *params, t_parser *parsed_map)
{
	int index = 0;


	// Allocate memory for game, map, colors, and textures
	params->game = malloc(sizeof(t_game));
	params->game->map = malloc(sizeof(t_map));
	params->game->colors = malloc(sizeof(t_colors));
	params->game->textures = malloc(sizeof(t_textures));

	// Transfer map data
	params->game->map->height = parsed_map->len_y;
	params->game->map->width = find_max_line(parsed_map->map, &index);

	// Allocate memory for the map grid
	params->game->map->grid = malloc(sizeof(int *) * params->game->map->height);
	for (int i = 0; i < params->game->map->height; i++)
	{
		params->game->map->grid[i] = malloc(sizeof(int) * params->game->map->width);
		for (int j = 0; j < params->game->map->width; j++)
		{
			if (j < (int)len_str(parsed_map->map[i]))
				params->game->map->grid[i][j] = parsed_map->map[i][j] == '1' ? 1 : 0;
			else
				params->game->map->grid[i][j] = 0;
		}
	}

	// Transfer color data
	params->game->colors->ceiling[0] = parsed_map->ceiling.red;
	params->game->colors->ceiling[1] = parsed_map->ceiling.green;
	params->game->colors->ceiling[2] = parsed_map->ceiling.blue;

	params->game->colors->floor[0] = parsed_map->floor.red;
	params->game->colors->floor[1] = parsed_map->floor.green;
	params->game->colors->floor[2] = parsed_map->floor.blue;

	// Transfer texture paths
	copy_str(params->game->textures->north_path, parsed_map->textures_parse.north, 256);
	copy_str(params->game->textures->south_path, parsed_map->textures_parse.south, 256);
	copy_str(params->game->textures->east_path, parsed_map->textures_parse.east, 256);
	copy_str(params->game->textures->west_path, parsed_map->textures_parse.west, 256);

	// Set initial player position and direction
	for (int i = 0; i < params->game->map->height; i++)
	{
		for (int j = 0; j < params->game->map->width; j++)
		{
			if (parsed_map->map[i][j] == 'N' || parsed_map->map[i][j] == 'S'
				|| parsed_map->map[i][j] == 'E' || parsed_map->map[i][j] == 'W')
				{
					params->posX = i + 0.5;
					params->posY = j + 0.5;

				// Set initial direction and plane based on player orientation
				switch (parsed_map->map[i][j])
				{
					case 'N':
						params->dirX = -1; params->dirY = 0;
						params->planeX = 0; params->planeY = 0.66;
						break;
					case 'S':
						params->dirX = 1; params->dirY = 0;
						params->planeX = 0; params->planeY = -0.66;
						break;
					case 'E':
						params->dirX = 0; params->dirY = 1;
						params->planeX = 0.66; params->planeY = 0;
						break;
					case 'W':
						params->dirX = 0; params->dirY = -1;
						params->planeX = -0.66; params->planeY = 0;
						break;
				}
				break;
			}
		}
	}
}

int init_params2(t_params *params)
{
	// Check if params is NULL
	if (!params)
		return (1);

	// Initialize mlx
	params->mlx = mlx_init();
	if (!params->mlx)
	{
		printf("Error: Failed to initialize mlx\n");
		return (1);
	}

	// Create new window
	params->window = mlx_new_window(params->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!params->window)
	{
		printf("Error: Failed to create new window\n");
		return (1);
	}

	// Create new image
	params->img = mlx_new_image(params->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!params->img)
	{
		printf("Error: Failed to create new image\n");
		return (1);
	}

	// Get image data address
	params->img_data = (unsigned int *)mlx_get_data_addr(params->img, &params->bits_per_pixel, &params->size_line, &params->endian);
	if (!params->img_data)
	{
		printf("Error: Failed to get image data address\n");
		return (1);
	}

	// Set texture images to NULL
	params->textures.east.img = NULL;
	params->textures.north.img = NULL;
	params->textures.south.img = NULL;
	params->textures.west.img = NULL;

	// Set texture paths to empty strings
	params->textures.east_path[0] = '\0';
	params->textures.north_path[0] = '\0';
	params->textures.south_path[0] = '\0';
	params->textures.west_path[0] = '\0';

	// Set initial player position and direction
	params->posX = 0.0;
	params->posY = 0.0;
	params->dirX = 0.0;
	params->dirY = 0.0;
	params->planeX = 0.0;
	params->planeY = 0.0;
	params->bits_per_pixel = 32; // Typically 32-bit per pixel for RGB
	params->size_line = SCREEN_WIDTH * 4; // Assuming 32 bits per pixel
	params->endian = 0; // Usually 0 for little-endian systems

	// Initialize the game structure
	params->game = malloc(sizeof(t_game));
	if (!params->game)
	{
		printf("Error: Failed to allocate memory for game structure\n");
		return (1);
	}

	// Initialize the colors structure
	params->colors.ceiling[0] = 0;
	params->colors.ceiling[1] = 0;
	params->colors.ceiling[2] = 0;
	params->colors.floor[0] = 0;
	params->colors.floor[1] = 0;
	params->colors.floor[2] = 0;

	return (0);
}


int	main(int ac, char **av)
{
	t_parser *parsed_map;
	t_params params;

	if (ac != 2)
		my_error(av);
	if (init_params2(&params))
	{
		printf("Error: Failed to initialize parameters\n");
		return (1);
	}
	parsed_map = parser(av);
	if (parsing_map(parsed_map))
		return (free_parse(parsed_map), 1);
	parsed_map->len_y = matrix_len(parsed_map->map);
	printf("napoli\n");
	// TRANSFER PARSED DATA TO RAYCASTING STRUCTURES
	transfer_parsed_data(&params, parsed_map);
	params.mlx = mlx_init();
	params.window = mlx_new_window(params.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	free_parse(parsed_map);
	load_textures(&params);
	mlx_hook(params.window, 2, 1L << 0, move_player, &params);
	mlx_hook(params.window, 17, 1L << 17, close_window, &params);
	mlx_loop_hook(params.mlx, draw, &params);
	mlx_loop(params.mlx);
	return (0);
}
