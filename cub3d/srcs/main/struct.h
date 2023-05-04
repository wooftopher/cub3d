/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:55:49 by christo           #+#    #+#             */
/*   Updated: 2023/05/01 23:24:48 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../../lib/MLX42/include/MLX42/MLX42.h"

typedef struct map
{
    char   		**map;
    int    		lenght;
    int    		height;
	float		*wall_px;
    float		*wall_py;
	int			wall_count;
    
}   t_map;

typedef struct ray
{
	float		min_dist;
	float		min_dist_fov[1024];
	float		dist;
	float		dir_x;
	float		dir_y;
	float		fov_angle;
	int			angle_count;
	float		angle_div;
	float		angle;
	float		xn;
	float		yn;
}	t_ray;

typedef struct player
{
    float		pos_x;
    float		pos_y;
	float		d_x;
	float		d_y;
	float		angle;
	int			speed;
	float		rot_speed;
	bool		col_x;
	bool		col_y;
}   t_player;

typedef struct mlx_struc
{
	mlx_t			*mlx;
    xpm_t           *xpm_player;
    xpm_t			*xpm_wall;
	mlx_texture_t   *text_wall;
	mlx_image_t		*img_player;
    mlx_image_t		*img_wall;
	mlx_image_t		*img_dir_ind;
	mlx_image_t		*img_wall_3d;
}	t_mlx_struc;

typedef struct cub3d
{
	t_mlx_struc		*mlx_s;
	t_player		*player;
    t_map           *map;
	t_ray			*ray;
	int				tic;
	int				vision;
}   t_cub3d;

typedef struct wall
{
    int		pos_x;
    int		pos_y;
}   t_wall;

#endif