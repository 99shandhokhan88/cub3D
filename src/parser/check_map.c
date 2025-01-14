#include "cub3D.h"

// void	print_map_non_printable(char **matrix)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (matrix[i])
// 	{
// 		j = 0;
// 		printf("'");
// 		while (matrix[i][j])
// 		{
// 			if (matrix[i][j] == '\n')
// 				printf("\\n");
// 			else
// 				printf("%c", matrix[i][j]);
// 			j++;
// 		}
// 		printf("'\n");
// 		i++;
// 	}
// }

int	parsing_map(t_game *game)
{
	char	**matrix_copy;
	int		error;

	matrix_copy = map_copy(game->parsed_map);
	if (matrix_copy == NULL || matrix_copy[0] == NULL)
	{
		printf("Error\n");
		printf("Malloc error\n");
		return (1);
	}
	// print_map_non_printable(matrix_copy);
	error = check_inside(&game->parser, matrix_copy);
	if (error == 1 || game->parser.player_position == 0)
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
