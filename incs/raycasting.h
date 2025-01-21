/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:44:05 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:25:50 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "structs.h"
# include "cub3D.h"

int				handle_pressed(int key, t_game *game);
int				handle_released(int key, t_game *game);
int				move_player(t_game *game, t_render *params);
void			initialize_ray(t_game *game, t_ray *ray, int x);
void			calculate_step_and_side(t_game *game, t_ray *ray);
void			calculate_ray(t_game *game, t_ray *ray, int x);
void			calculate_wall_slice_dimensions(t_ray *ray,
					t_wall_slice_data *data);
double			calculate_wall_x(t_game *game, t_ray *ray);
t_texture		*select_wall_texture(t_game *game, t_ray *ray);
int				calculate_tex_x(t_wall_slice_data *data, t_ray *ray);
void			draw_wall_slice(t_game *game, t_ray *ray, int x, int y);
int				draw(t_game *game);
void			render_floor_ceiling(unsigned int *img_data, t_colors *colors);
void			clamp_color(t_color *color);
int				close_window(t_game *game);
void			free_matrix(t_map *map);
void			free_textures_path(t_textures *textures);
void			free_textures(t_game *game);
void			ft_exit(t_game *game, int code);
void			load_textures(t_game *game);
void			load_single_texture(t_game *game,
					t_texture *texture, char *path);
void			draw_minimap(t_game *game);
void			draw_player(t_game *game);
void			draw_player_direction(t_game *game);
void			square(t_game *game, int x, int y, int c);
void			line(t_game *game, t_point p1, t_point p2);
int				mouse_move(int x, int y, t_game *game);
int				handle_mouse_press(int button, int x, int y, t_game *game);
int				handle_mouse_release(int button, int x, int y, t_game *game);
void			check_cursor_rotation(t_game *game, int mouse_x);
void			rotate_player(t_game *game, double rot_speed);
void			move_forward(t_game *game, double move_speed);
void			move_backward(t_game *game, double move_speed);
void			move_left(t_game *game, double move_speed);
void			move_right(t_game *game, double move_speed);
void			advance_ray(t_ray *ray);
int				check_hit(t_game *game, t_ray *ray);
void			progress_ray(t_game *game, t_ray *ray);
void			calculate_wall_distance(t_ray *ray);
void			perform_dda(t_game *game, t_ray *ray);
void			prepare_texture_sampling(t_wall_slice_data *data,
					double *step, double *texPos);
unsigned int	get_shaded_color(t_wall_slice_data *data,
					int tex_y, int tex_x, t_ray *ray);
void			raycasting(t_game *game, t_render *params);

#endif
