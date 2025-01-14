#ifndef PARSER_H
# define PARSER_H

typedef struct s_map_copy
{
	char	**copy_map;
	int		i;
	int		j;
}	t_map_copy;

// typedef struct s_file
// {
// 	char			*line;
// 	struct s_file	*next;
// }	t_file;

// typedef struct s_color
// {
// 	int		r;
// 	int		g;
// 	int		b;
// }	t_color;

// typedef struct s_textures_parse
// {
// 	char	*north;
// 	char	*south;
// 	char	*east;
// 	char	*west;
// }	t_textures_parse;

// typedef struct s_parser
// {
// 	// char				**map;
// 	// t_textures_parse	textures_parse;
// 	// t_color				floor;
// 	// t_color				ceiling;
// 	t_file				*init;
// 	int					player_position;
// 	int					len_y;
// }	t_parser;

int			my_error(char **av);
void		parser(char *filename, t_game *game);
void		check_file(char *file);
void		check_cub(t_file **init, char *file);
void		parsing_handle_escape(t_file *file);
void		free_struct(t_file *init);
char		*null_dest(char	*dst);
char		*get_line(char	*stat);
t_file		*lstnew(char *line);
t_file		*lstlast(t_file *lst);
void		lstadd_back(t_file **lst, t_file *new);
void		init_empty(t_file *init);
int			back_slash_trimmer(t_file *init);
void		parser_errors(t_game *game, char *message);
void		struct_filler(t_game *game, t_parser *parsed, t_file *init);
int			direction(t_game *game, t_file *init, char *dir, char **path);
int			background_fill(t_game *game, t_file *init, char platform, int *done);
int			fill_floor(t_game *game, t_file *init, int *index);
int			fill_ceiling(t_game *game, t_file *init, int *index);
int			skip_spaces(int index, t_game *game, t_file *init);
void		the_checker(t_game *game, t_file *init, int index);
void		fill_map(t_game *game, t_file *init);
void		free_map2(char **map);
void		check_inside_char(t_game *game, t_textures *textures);
void		free_parse(t_game *game);
int			parsing_map(t_game *game);
char		**map_copy(char **map);
int			find_max_line(char **map, int *i);
char		**manage_spaces(char **map, int i, int j);
int			line_copy(t_map_copy *map_copy, int i, int j, char **map);
void		last_line_copy(t_map_copy *d, int index, char **map, int j);
int			check_inside(t_parser *parsed, char **copy_map);
int			check_pos(char c, t_parser *parsed);
int			check_space_inside(char **map, int i, int j);
int			matrix_len(char **map);
int			is_empty(char c);
int			corner_check(char **map, int i, int j);
int			border_check(char **copy_map);
int			right_check(char **copy_map);
int			check_correct_walls(char **map, int x, int y, int type);
int			find_path(int i, int j, char **map, int type);
int			around_checker(char **map, int kind, int i, int j);
int			size_lst(t_file *lst);

// libft functions
char		*get_next_line_map(int fd);
char		*strjoin(char *dst, char *s);

#endif
