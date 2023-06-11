/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:34:38 by cperron           #+#    #+#             */
/*   Updated: 2023/06/10 15:22:19 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

void	init_ray(t_cub3d *cub3d, t_map *map)
{
	int	i;
	t_ray_angle_fov_s *ray_angle_fov_s[1500];
	t_ray_angle_s *ray_angle_s;
	
	ray_angle_s = calloc(1, sizeof(t_ray_angle_s)); //ADDED TWO TO FIX TEMP VALGRIND ERROR
	cub3d->ray->ray_angle_s = ray_angle_s;
	i = 0;
	while (i <= 1400)
	{
		ray_angle_fov_s[i] = calloc(1, sizeof(t_ray_angle_fov_s)); //ADDED TWO TO FIX TEMP VALGRIND ERROR
		cub3d->ray->ray_angle_fov_s[i] = ray_angle_fov_s[i];
		i++;
	}
	cub3d->ray->fov_angle = 30;
	// cub3d.ray->angle_div = 0.035714f;
	cub3d->ray->angle_div = 0.042857f;
}
