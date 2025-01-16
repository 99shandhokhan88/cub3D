#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <stddef.h>
# include <stdbool.h>
# include <errno.h>
# include <stdint.h>

# include "raycasting.h"
# include "parser.h"

# define BOLD "\x1b[1m"
# define RED "\x1b[31m"
# define BLUE "\x1b[36m"
# define RESET "\x1b[0m"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define MAP_WIDTH 38
# define MAP_HEIGHT 38
# define TILE_SIZE 10

# define MOVE_SPEED 0.021
# define ROTATE_SPEED 0.021

# define MINI_P_COLOR 0x0000FF
# define MINI_WALL_COLOR 0xFF0000
# define MINI_EMPTY_COLOR 0x00FF00

# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4
# define NORTH 5
# define SOUTH 6
# define EAST 7
# define WEST 8

typedef enum e_keys
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_ESC = 65307,
	KEY_Q = 113,
	KEY_SHIFT = 65505,
}	t_keys;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	print_map(char **copy_map);

#endif
