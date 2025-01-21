/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:20:49 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:26:15 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3D.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map_copy
{
	char	**copy_map;
	int		i;
	int		j;
}	t_map_copy;

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

typedef struct s_map
{
	int	**grid;
	int	height;
	int	width;
}	t_map;

typedef struct s_file
{
	char			*line;
	struct s_file	*next;
}	t_file;

typedef struct s_player_pars
{
	int					player_facing;
	t_file				*file;
}	t_player_pars;

typedef struct s_key_press
{
	bool	a;
	bool	d;
	bool	s;
	bool	w;
	bool	left;
	bool	right;
	bool	shift;
	bool	mouse_pressed;
}	t_key_press;

typedef struct s_render
{
	void			*mlx;
	void			*img;
	void			*window;
	unsigned int	*img_data;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
	t_key_press		keys;
}	t_render;

typedef struct s_texture
{
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				endian;
	int				height;
	int				width;
	int				size_line;
	char			*path;
}	t_texture;

typedef struct s_textures
{
	t_texture	east;
	t_texture	north;
	t_texture	south;
	t_texture	west;
}	t_textures;

typedef struct s_game
{
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				pos_x;
	double				pos_y;
	char				**map_copy;
	char				**parsed_map;
	t_colors			colors;
	t_map				*map;
	t_player_pars		player_pars;
	t_render			render;
	t_textures			textures;
}	t_game;

typedef struct s_ray
{
	double	camera_x;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	int		map_y;
	int		map_x;
	int		side;
	int		step_x;
	int		step_y;
}	t_ray;

typedef struct s_wall_slice_data
{
	double		wall_x;
	int			draw_start;
	int			draw_end;
	int			line_height;
	int			tex_x;
	t_texture	*curr_texture;
}	t_wall_slice_data;

#endif
