/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:31:08 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 00:03:55 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structs.h"
# include "cub3D.h"

int			check_pos(char c, t_player_pars *player_pars);
int			corner_check(char **map, int i, int j);
int			is_empty(char c);
int			check_space_inside(char **map, int i, int j);
int			check_inside(t_player_pars *parsed, char **copy_map);
int			my_error(char **av);
void		free_struct(t_file *file);
void		parser_errors(t_game *game, char *message);
void		handle_escape_file(t_file *file);
void		free_map(char **map);
int			direction(t_game *game, t_file *file, char *dir, char **path);
int			fill_ceiling(t_game *game, t_file *file, int *index);
int			fill_floor(t_game *game, t_file *file, int *index);
int			background_fill(t_game *game,
				t_file *file, char platform, int *flag);
void		struct_filler(t_game *game, t_file *file);
void		flood_fill(t_game *game, int row, int col);
void		check_flood(t_game *game);
void		init_game(t_game **game);
int			init_render_graphics(t_game *init_game);
void		init_render_keys_and_settings(t_game *init_game);
void		init_render(t_game *init_game);
void		find_player_position(t_game *game);
void		init_player(t_game *init_player);
void		init_map(t_game *game, t_map *map);
void		init_map_part_2(t_game *game, t_map *map);
void		init_map_part_1(t_game *game, t_map *map);
int			around_checker(char **map, int kind, int i, int j);
int			find_path(int i, int j, char **map, int kind);
int			check_correct_walls(char **map, int x, int y, int type);
int			right_check(char **copy_map);
int			border_check(char **copy_map);
int			find_max_line(char **map, int *i);
int			line_copy(t_map_copy *map_copy, int i, int j, char **map);
void		last_line_copy(t_map_copy *map_copy, int i, char **map, int k);
char		**manage_spaces(char **map, int i, int j);
char		**map_copy(char **map);
void		fill_map(t_game *game, t_file *init);
int			parsing_map(t_game *game);
void		check_file(t_game *game, char *file);
void		check_cub(t_file **mat, char *file);
int			back_slash_trimmer(t_file *file);
int			size_lst(t_file *lst);
void		init_pars_check(t_game *game, t_file *file);
void		free_parser(t_game *game);
void		check_inside_char(t_game *game, t_textures *textures);
void		parser(char *file, t_game *game);
void		file_lines_checker(t_game *game, t_file *file, int i);
char		*null_dest(char *dst);
char		*ft_strjoin(char *dst, char *s);
int			skip_spaces(int i, t_game *game, t_file *init);
int			matrix_len(char **map);
void		init_map_part_1(t_game *game, t_map *map);
void		init_map_part_2(t_game *game, t_map *map);

#endif
