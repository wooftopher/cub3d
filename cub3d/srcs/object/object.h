/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:36:09 by christo           #+#    #+#             */
/*   Updated: 2023/05/29 22:46:20 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
#define OBJECT_H

// # include "../main/cub3d.h"
# include "../main/struct.h"
# include <math.h>
# include <stdlib.h>
# include <strings.h>

//player_move
void	ft_move(t_cub3d *cub3d);
void	ft_rotate(t_cub3d *cub3d);

//fir_indicator
void	set_direction_indicator(t_player *player, t_mlx_struc *mlx);
void	set_direction_indicator_2(t_player *player, t_mlx_struc *mlx, t_ray *ray);
void	set_direction_indicator_3(t_player *player, t_mlx_struc *mlx, t_ray *ray);

//ray_hor
void 	ray_hor_up(t_player *player, t_map *map, t_ray *ray, int j);
void 	ray_hor_down(t_player *player, t_map *map, t_ray *ray, int j);

//ray_hor_fov
void 	ray_hor_up_fov(t_player *player, t_map *map, t_ray *ray, int j);
void 	ray_hor_down_fov(t_player *player, t_map *map, t_ray *ray, int j);

//ray_ver
void	ray_ver_right(t_player *player, t_map *map, t_ray *ray, int j);
void	ray_ver_left(t_player *player, t_map *map, t_ray *ray, int j);

//ray_ver_fov
void	ray_ver_right_fov(t_player *player, t_map *map, t_ray *ray, int j);
void	ray_ver_left_fov(t_player *player, t_map *map, t_ray *ray, int j);

//find_pixel_color
uint32_t	pixel_color(t_xpm *xpm_s, int x, int y);

#endif