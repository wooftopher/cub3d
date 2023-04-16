/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:55:49 by christo           #+#    #+#             */
/*   Updated: 2023/04/16 02:16:47 by christo          ###   ########.fr       */
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
    xpm_t           *xpm;
    t_map           *map;
}   t_cub3d;

#endif