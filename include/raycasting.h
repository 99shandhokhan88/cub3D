#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_file
{
	char			*line;
	struct s_file	*next;
}	t_file;

typedef struct s_parser
{
	t_file				*init;
	int					player_facing;
}	t_parser;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_colors
{
	t_color	ceiling;
	t_color	floor;
}	t_colors;

typedef struct s_texture
{
	void			*img;
	unsigned int	*addr;
	char			*path;
	int				bits_per_pixel;
	int				endian;
	int				width;
	int				height;
	int				size_line;
}	t_texture;

typedef struct s_map
{
	int	**grid;
	int	width;
	int	height;
}	t_map;

typedef struct s_textures
{
	t_texture	east;
	t_texture	north;
	t_texture	south;
	t_texture	west;
}	t_textures;

typedef struct s_key_press
{
	bool	a;
	bool	d;
	bool	s;
	bool	w;
	bool	left;
	bool	right;
	bool	shift;
}	t_key_press;

typedef struct s_render
{
	void			*mlx;
	void			*window;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void			*img;
	unsigned int	*img_data;
	t_key_press		keys;
}	t_render;

typedef struct s_game
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	t_textures	textures;
	t_colors	colors;
	t_map		*map;
	char		**parsed_map;
	char		**map_copy;
	t_render	render;
	t_parser	parser;
}	t_game;

typedef struct s_ray
{
	double	camera_x;
	double	delta_dist_x;
	double	delta_dist_y;
	int		map_y;
	int		map_x;
	double	perp_wall_dist;
	double	ray_dir_x;
	double	ray_dir_y;
	int		side;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
}	t_ray;

typedef struct s_wall_slice_data
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	t_texture	*curr_texture;
}	t_wall_slice_data;

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
void			render_floor_ceiling(unsigned int *img_data, t_colors *colors);
int				draw(t_game *game);
void			draw_minimap(t_game *game);
int				my_error(char **av);
int				close_window(t_game *game);
void			free_textures(t_game *game);
void			ft_exit(t_game *game, int code);
void			load_single_texture(t_game *game,
					t_texture *texture, char *path);
void			load_textures(t_game *game);
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
