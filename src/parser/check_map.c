
#include "../include/cub3D.h"

int	parsing_map(t_parser *parsed)
{
	char	**matrix_copy;
	int		error;

	matrix_copy = map_copy(parsed->map);
	if (matrix_copy == NULL || matrix_copy[0] == NULL)
	{
		printf("Error\n");
		printf("Malloc error\n");
		return (1);
	}
	error = check_inside(parsed, matrix_copy);
	if (error == 1 || parsed->player_position == 0)
	{
		printf("Error\n");
		printf("the player\n");
		return (free_map2(matrix_copy), 1);
	}
	if (error == 2)
	{
		printf("Error\n");
		printf("the spaces inside the map\n");
		return (free_map2(matrix_copy), 1);
	}
	return (border_check(matrix_copy));
}
