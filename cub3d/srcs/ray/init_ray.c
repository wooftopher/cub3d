/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:34:38 by cperron           #+#    #+#             */
/*   Updated: 2023/05/31 18:13:16 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

void	init_ray(t_cub3d *cub3d)
{
	int	i;
	t_ray_angle_s *ray_angle_fov_s[1500];
	
	i = 0;
	while (i <= 1400)
	{
		ray_angle_fov_s[i] = calloc(1, sizeof(t_ray_angle_fov_s)); //libtf
		cub3d->ray->ray_angle_fov_s[i] = ray_angle_fov_s[i];
		i++;
	}
	cub3d->ray->fov_angle = 30;
	// cub3d.ray->angle_div = 0.035714f;
	cub3d->ray->angle_div = 0.042857f;
	cub3d->mlx_s->txt_wall = mlx_load_png("./img/nezukobig.png");
	cub3d->map->north = fill_int_array(cub3d->mlx_s->txt_wall->height
		* cub3d->mlx_s->txt_wall->height * 4, cub3d->mlx_s->txt_wall->height,
			cub3d->mlx_s->txt_wall->width, cub3d->mlx_s->txt_wall);
}