/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:36:09 by christo           #+#    #+#             */
/*   Updated: 2023/04/24 23:46:03 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

// # include "../main/cub3d.h"
# include "../main/struct.h"
# include <math.h>

//player_move
void	ft_move(t_cub3d *cub3d);
void	ft_rotate(t_cub3d *cub3d);

//fir_indicator
void	set_direction_indicator(t_player *player, t_mlx_struc *mlx);
void	set_direction_indicator_2(t_player *player, t_mlx_struc *mlx, t_ray *ray);

//ray_hor
void ray_hor_up(t_player *player, t_map *map, t_ray *ray, int j);
void ray_hor_down(t_player *player, t_map *map, t_ray *ray, int j);

#endif