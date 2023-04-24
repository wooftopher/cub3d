/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:58:54 by christo           #+#    #+#             */
/*   Updated: 2023/04/23 23:47:43 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../lib/MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include <float.h>

#include "../map/map.h"
#include "./struct.h"

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

// typedef struct cub3d
// {
//     mlx_t			*mlx;
//     xpm_t           *xpm;
//     t_map           map;
// }   t_cub3d;

void	ft_map_init(t_cub3d *cub3d);

# define true 1
# define false 0

#endif