/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:24:28 by cperron           #+#    #+#             */
/*   Updated: 2023/06/22 13:31:59 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_BONUS_H
# define RAY_BONUS_H

# include "../main/struct_bonus.h"
# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <strings.h>
# include <stdio.h>

//ray_hor_fov
void	ray_hor_up_fov(t_player *player, t_map *map, t_ray *ray);
void	ray_hor_down_fov(t_player *player, t_map *map, t_ray *ray);

//ray_ver_fov
void	ray_ver_right_fov(t_player *player, t_map *map, t_ray *ray);
void	ray_ver_left_fov(t_player *player, t_map *map, t_ray *ray);

//ray_calcul
void	ft_calcul_render(t_cub3d *cub3d);

//ray_calcul_utils
int		fish_eye_correction(t_cub3d *cub3d, int k, float wall_height);
void	check_orientation_1(t_cub3d *cub3d, int k, int i, int wall_height);
void	check_orientation_2(t_cub3d *cub3d, int k, int i, int wall_height);
int		find_y(int i, int wall_h, uint32_t txt_height);

int		check_feature_y(t_map *map, t_ray *ray, int x, int y);
int		check_feature_x(t_map *map, t_ray *ray, int x, int y);

int		**fill_int_array(mlx_texture_t *texture);
void	free_int_array(int **array, uint32_t heigth);

#endif