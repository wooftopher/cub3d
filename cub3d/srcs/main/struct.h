/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:55:49 by christo           #+#    #+#             */
/*   Updated: 2023/04/20 02:12:33 by christo          ###   ########.fr       */
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

typedef struct player
{
    int		pos_x;
    int		pos_y;
	float	direction;
	int		speed_x;
	int		speed_y;
}   t_player;

typedef struct mlx_struc
{
	mlx_t			*mlx;
    xpm_t           *xpm_player;
    xpm_t           *xpm_wall;
	mlx_image_t		*img_player;
    mlx_image_t		*img_wall;
}	t_mlx_struc;

typedef struct cub3d
{
//     mlx_t			*mlx;
//     xpm_t           *xpm_player;
//     xpm_t           *xpm_wall;
	t_mlx_struc		*mlx;
	t_player		*player;
    t_map           *map;
    // mlx_image_t*	img_player;
    // mlx_image_t*	img_wall;
}   t_cub3d;


typedef struct wall
{
    int		pos_x;
    int		pos_y;
}   t_wall;

#endif