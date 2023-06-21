/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:24:28 by cperron           #+#    #+#             */
/*   Updated: 2023/06/21 18:48:02 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../main/struct.h"
# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <strings.h>
# include <stdio.h>

//ray_hor
void	ray_hor_up(t_player *player, t_map *map, t_ray *ray, int j);
void	ray_hor_down(t_player *player, t_map *map, t_ray *ray, int j);

//ray_hor_fov
void	ray_hor_up_fov(t_player *player, t_map *map, t_ray *ray, int j);
void	ray_hor_down_fov(t_player *player, t_map *map, t_ray *ray, int j);

//ray_ver
void	ray_ver_right(t_player *player, t_map *map, t_ray *ray, int j);
void	ray_ver_left(t_player *player, t_map *map, t_ray *ray, int j);

//ray_ver_fov
void	ray_ver_right_fov(t_player *player, t_map *map, t_ray *ray, int j);
void	ray_ver_left_fov(t_player *player, t_map *map, t_ray *ray, int j);

//ray_calcul
void	ft_calcul_render(t_cub3d *cub3d);

//ray_calcul_utils
void	create_pixel_image(t_cub3d *cub3d);
int		fish_eye_correction(t_cub3d *cub3d, int k, float wall_height);
void	check_orientation_1(t_cub3d *cub3d, int k, int i, int wall_height);
void	check_orientation_2(t_cub3d *cub3d, int k, int i, int wall_height);
int		find_y(t_cub3d *cub3d, int i, int wall_h, uint32_t txt_height);

int		check_feature_y(t_map *map, t_ray *ray, int x, int y);
int		check_feature_x(t_map *map, t_ray *ray, int x, int y);

int		**fill_int_array(mlx_texture_t *texture);
void	free_int_array(int **array, uint32_t heigth);

#endif