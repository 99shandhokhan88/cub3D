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
				game->posX = i + 0.5;
				game->posY = j + 0.5;
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
	map->height = matrix_len(game->parsed_map);
	map->width = find_max_line(game->parsed_map, 0);
	map->grid = (int **)ft_calloc(map->height, sizeof(int *));
	while (i < map->height)
	{
		j = 0;
		map->grid[i] = (int *)ft_calloc(map->width, sizeof(int));
		while (j < map->width)
		{
			if (j < (int)ft_strlen(game->parsed_map[i]))
			{
				if (game->parsed_map[i][j] == '1')
					map->grid[i][j] = 1;
			}
			j++;
		}
		i++;
	}
	find_player_position(game);
}

int	init_render2(t_render *params)
{
	params->mlx = mlx_init();
	if (!params->mlx)
		return (printf("Error: Failed to initialize mlx\n"), 1);
	params->window = mlx_new_window(params->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!params->window)
		return (printf("Error: Failed to create new window\n"), 1);
	params->img = mlx_new_image(params->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!params->img)
		return (printf("Error: Failed to create new image\n"), 1);
	params->img_data = (unsigned int *)mlx_get_data_addr(params->img,
			&params->bits_per_pixel, &params->size_line, &params->endian);
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
	if (game->parser.player_facing == NORTH)
	{
		game->dirX = -1;
		game->planeY = 0.66;
	}
	else if (game->parser.player_facing == SOUTH)
	{
		game->dirX = 1;
		game->planeY = -0.66;
	}
	else if (game->parser.player_facing == EAST)
	{
		game->dirY = 1;
		game->planeX = 0.66;
	}
	else if (game->parser.player_facing == WEST)
	{
		game->dirY = -1;
		game->planeX = -0.66;
	}
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		my_error(av);
	init_game(&game);
	if (!game)
		return (printf("Error: Failed to initialize game\n"), 1);
	init_render2(&game->render);
	parser(av[1], game);
	if (parsing_map(game))
		return (free_parse(game), 1);
	printf("napoli\n");
	init_map(game, game->map);
	init_player(game);
	load_textures(game);
	mlx_hook(game->render.window, 2, 1L << 0, handle_pressed, game);
	mlx_hook(game->render.window, 3, 1L << 1, handle_released, game);
	mlx_hook(game->render.window, 17, 1L << 17, close_window, game);
	mlx_loop_hook(game->render.mlx, draw, game);
	mlx_loop(game->render.mlx);
	return (0);
}
