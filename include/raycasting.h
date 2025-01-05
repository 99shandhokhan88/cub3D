#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_map		t_map;
typedef struct s_texture	t_texture;
typedef struct s_textures	t_textures;
typedef struct s_game		t_game;
typedef struct s_params		t_params;

typedef struct s_colors
{
	int	ceiling[3];
	int	floor[3];
}	t_colors;

typedef struct s_texture
{
	unsigned int	*addr;
	int				bits_per_pixel;
	int				endian;
	int				height;
	void			*img;
	int				size_line;
	int				width;
}	t_texture;

typedef struct s_map
{
	int	**grid;
	int	height;
	int	width;
}	t_map;

typedef struct s_textures
{
	t_texture	east;
	char		east_path[256];
	t_texture	north;
	char		north_path[256];
	t_texture	south;
	char		south_path[256];
	t_texture	west;
	char		west_path[256];
}	t_textures;

typedef struct s_game
{
	t_colors	*colors;
	t_map		*map;
	t_params	*params;
	t_textures	*textures;
	int flag;
}	t_game;

typedef struct s_params
{
	int				bits_per_pixel;
	t_colors		colors;
	double			dirX;
	double			dirY;
	int				endian;
	t_game			*game;
	void			*img;
	unsigned int	*img_data;
	void			*mlx;
	double			planeX;
	double			planeY;
	double			posX;
	double			posY;
	int				size_line;
	t_textures		textures;
	void			*window;
}	t_params;

typedef struct s_ray
{
	double	cameraX;
	double	deltaDistX;
	double	deltaDistY;
	int		mapX;
	int		mapY;
	double	perpWallDist;
	double	rayDirX;
	double	rayDirY;
	int		side;
	double	sideDistX;
	double	sideDistY;
	int		stepX;
	int		stepY;
}	t_ray;

typedef struct s_wall_slice_data
{
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		wallX;
	int			texX;
	t_texture	*current_texture;
}	t_wall_slice_data;

int		move_player(int key, t_params *params);
void	initialize_ray(t_params *params, t_ray *ray, int x);
void	calculate_step_and_side(t_params *params, t_ray *ray);
void	calculate_ray(t_params *params, t_ray *ray, int x);
void	calculate_wall_slice_dimensions(t_ray *ray, t_wall_slice_data *data);
double	calculate_wall_x(t_params *params, t_ray *ray);
t_texture	*select_wall_texture(t_params *params, t_ray *ray);
int		calculate_tex_x(t_wall_slice_data *data, t_ray *ray);
void	draw_wall_slice(t_params *params, t_ray *ray, int x, int y);
void	render_floor_ceiling(unsigned int *img_data, t_colors *colors);
int		draw(void *param);
int		my_error(char **av);
int		close_window(t_params *params);
void	free_textures(t_params *params);
void	ft_exit(t_params *params, int code);
void	load_single_texture(t_params *params, t_texture *texture, char *path);
void	load_textures(t_params *params);
void	rotate_player(t_params *params, double rot_speed);
void	move_forward(t_params *params,
		double move_speed, double new_pos_x, double new_pos_y);
void	move_backward(t_params *params,
		double move_speed, double new_pos_x, double new_pos_y);
void	move_left(t_params *params,
		double move_speed, double new_pos_x, double new_pos_y);
void	move_right(t_params *params,
		double move_speed, double new_pos_x, double new_pos_y);
void	advance_ray(t_ray *ray);
int		check_hit(t_params *params, t_ray *ray);
void	progress_ray(t_params *params, t_ray *ray);
void	calculate_wall_distance(t_ray *ray);
void	perform_dda(t_params *params, t_ray *ray);
void	prepare_texture_sampling(t_wall_slice_data *data,
		double *step, double *texPos);
unsigned int	get_shaded_color(t_wall_slice_data *data,
		int texY, int texX, t_ray *ray);
void	raycasting(t_params *params);

#endif
