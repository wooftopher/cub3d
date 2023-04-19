/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:55:49 by christo           #+#    #+#             */
/*   Updated: 2023/04/19 03:43:21 by christo          ###   ########.fr       */
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
    
}   t_map;

typedef struct cub3d
{
    mlx_t			*mlx;
    xpm_t           *xpm_player;
    xpm_t           *xpm_wall;
    int             wall_px[50];
    int             wall_py[50];
    t_map           *map;
    mlx_image_t*	img_player;
    mlx_image_t*	img_wall;
}   t_cub3d;

#endif