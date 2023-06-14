/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:55:49 by christo           #+#    #+#             */
/*   Updated: 2023/06/14 17:09:44 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../../libs/MLX/include/MLX42/MLX42.h"

typedef struct s_map
{
	char		**map;
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	uint8_t		width;
	uint8_t		height;
	uint16_t	wall_count;
	float		*wall_px;
	float		*wall_py;
	uint8_t		map_errno;
	int			**north;
	int			**south;
	int			**east;
	int			**west;
}	t_map;

typedef struct ray_angle_fov_s
{
	float	min_dist_fov;
	int		orientation;
	float	pos_on_texture;
	float	angle;

}	t_ray_angle_fov_s;


typedef struct ray
{
	float				min_dist;
	t_ray_angle_fov_s	*ray_angle_fov_s[1401];
	float				dist;
	float				fov_angle;
	int					angle_count;
	float				angle_div;
	float				angle;
	float				xn;
	float				yn;
	int					text_x;
	int					text_y;
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
	mlx_texture_t   *txt_wall_n;
	mlx_texture_t   *txt_wall_s;
	mlx_texture_t   *txt_wall_e;
	mlx_texture_t   *txt_wall_w;
	mlx_image_t		*img_back;
	mlx_image_t		*img_wall_3d;
}	t_mlx_struc;

typedef struct cub3d
{
	t_mlx_struc		*mlx_s;
	t_player		*player;
    t_map           *map;
	t_ray			*ray;
}   t_cub3d;

#endif