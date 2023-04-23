/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:55:49 by christo           #+#    #+#             */
/*   Updated: 2023/04/23 17:52:09 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../../lib/MLX42/include/MLX42/MLX42.h"

typedef struct map
{
    char    **map;
    int     lenght;
    int     height;
	int		*wall_px;
    int		*wall_py;
	int		wall_count;
    
}   t_map;

typedef struct ray
{
	int		min_dist;
	int		dist;
	float	dir_x;
	float	dir_y;
	int		fov;
	int		angle;
	int		inter_x;
	int		inter_y;
}	t_ray;

typedef struct player
{
    int		pos_x;
    int		pos_y;
	int		d_x;
	int		d_y;
	int		angle;
	int		speed;
	bool	col_x;
	bool	col_y;
}   t_player;

typedef struct mlx_struc
{
	mlx_t			*mlx;
    xpm_t           *xpm_player;
    xpm_t           *xpm_wall;
	mlx_image_t		*img_player;
    mlx_image_t		*img_wall;
	mlx_image_t		*img_dir_ind;
}	t_mlx_struc;

typedef struct cub3d
{
	t_mlx_struc		*mlx;
	t_player		*player;
    t_map           *map;
	t_ray			*ray;
	int				tic;
}   t_cub3d;

typedef struct wall
{
    int		pos_x;
    int		pos_y;
}   t_wall;

#endif