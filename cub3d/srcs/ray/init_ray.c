/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:34:38 by cperron           #+#    #+#             */
/*   Updated: 2023/06/06 23:29:13 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

void	init_ray(t_cub3d *cub3d)
{
	int	i;
	t_ray_angle_fov_s *ray_angle_fov_s[1500];
	
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
	cub3d->mlx_s->txt_wall_n = mlx_load_png("./img/big.png");
	cub3d->mlx_s->txt_wall_s = mlx_load_png("./img/nezuko.png");
	cub3d->mlx_s->txt_wall_e = mlx_load_png("./img/zoe.png");
	cub3d->mlx_s->txt_wall_w = mlx_load_png("./img/trump.png");
	cub3d->map->north = fill_int_array(cub3d->mlx_s->txt_wall_n->height
		* cub3d->mlx_s->txt_wall_n->height * 4, cub3d->mlx_s->txt_wall_n->height,
			cub3d->mlx_s->txt_wall_n->width, cub3d->mlx_s->txt_wall_n);
	cub3d->map->south = fill_int_array(cub3d->mlx_s->txt_wall_s->height
		* cub3d->mlx_s->txt_wall_s->height * 4, cub3d->mlx_s->txt_wall_s->height,
			cub3d->mlx_s->txt_wall_s->width, cub3d->mlx_s->txt_wall_s);
	cub3d->map->east = fill_int_array(cub3d->mlx_s->txt_wall_n->height
		* cub3d->mlx_s->txt_wall_e->height * 4, cub3d->mlx_s->txt_wall_e->height,
			cub3d->mlx_s->txt_wall_e->width, cub3d->mlx_s->txt_wall_e);
	cub3d->map->west = fill_int_array(cub3d->mlx_s->txt_wall_n->height
		* cub3d->mlx_s->txt_wall_w->height * 4, cub3d->mlx_s->txt_wall_w->height,
			cub3d->mlx_s->txt_wall_w->width, cub3d->mlx_s->txt_wall_w);
}