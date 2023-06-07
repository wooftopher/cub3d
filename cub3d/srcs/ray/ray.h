/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:24:28 by cperron           #+#    #+#             */
/*   Updated: 2023/06/06 23:16:21 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

# include "../main/struct.h"
# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <strings.h>
# include <stdio.h>

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
// uint32_t	pixel_color(t_xpm *xpm_s, int x, int y);

//ray_calcul
void	ft_calcul_render(t_cub3d *cub3d);

//ini_ray
void	init_ray(t_cub3d *cub3d);

int		**fill_int_array(uint32_t length, uint32_t heigth, uint32_t witdh, mlx_texture_t *texture);
void	free_int_array(int **array, uint32_t heigth);

#endif