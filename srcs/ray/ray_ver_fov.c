/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ver_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:32:47 by cperron           #+#    #+#             */
/*   Updated: 2023/06/20 05:55:13 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

int	col_left_v2(t_map *map, t_player *player, t_ray *ray)
{
	int		y;
	int		x;
	float	ys;
	float	xs;

	xs = 100;
	ys = xs * (tan((ray->angle - 90) * M_PI / 180));
	y = ((player->pos_y + ray->yn) / 100);
	x = ((player->pos_x - ray->xn) / 100) - 1;
	while (y >= 0 && x >= 0 && y < map->height && x < map->width)
	{
		if (map->map[y][x] == '1')
		{
			ray->text_y = y;
			return (1);
		}
		else
		{
			ray->yn += ys;
			ray->xn += xs;
		}
		y = (player->pos_y + ray->yn) / 100;
		x = (player->pos_x - ray->xn) / 100 - 1;
	}
	return (0);
}

void	ray_ver_left_fov(t_player *player, t_map *map, t_ray *ray, int j)
{
	ray->xn = player->pos_x - (floor(player->pos_x / 100)) * 100;
	ray->yn = ray->xn * (tan((ray->angle - 90) * M_PI / 180));
	if (col_left_v2(map, player, ray) == 1)
	{
		ray->dist = sqrt((ray->xn * ray->xn) + (ray->yn * ray->yn));
		if (ray->dist < ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov)
		{
			ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = ray->dist;
			ray->ray_angle_fov_s[ray->angle_count]->angle = ray->angle;
			ray->ray_angle_fov_s[ray->angle_count]->orientation = 3;
			ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture
				= 100 - (player->pos_y + ray->yn - ray->text_y * 100);
		}	
	}
}

int	col_right_v2(t_map *map, t_player *player, t_ray *ray)
{
	int		y;
	int		x;
	float	ys;
	float	xs;

	xs = 100;
	ys = xs * (tan((ray->angle - 90) * M_PI / 180));
	y = ((player->pos_y - ray->yn) / 100);
	x = ((player->pos_x + ray->xn) / 100);
	while (y >= 0 && x >= 0 && y < map->height && x < map->width)
	{
		if (map->map[y][x] == '1')
		{
			ray->text_y = y;
			return (1);
		}		
		else
		{
			ray->yn += ys;
			ray->xn += xs;
		}
		y = (player->pos_y - ray->yn) / 100;
		x = (player->pos_x + ray->xn) / 100;
	}
	return (0);
}

void	ray_ver_right_fov(t_player *player, t_map *map, t_ray *ray, int j)
{
	float	ys;
	float	xs;

	xs = 100;
	ys = xs * (tan((ray->angle - 90) * M_PI / 180));
	ray->xn = ((floor(player->pos_x / 100)) + 1) * 100 - player->pos_x;
	ray->yn = ray->xn * (tan((ray->angle - 90) * M_PI / 180));
	if (col_right_v2(map, player, ray) == 1)
	{
		ray->dist = sqrt((ray->xn * ray->xn) + (ray->yn * ray->yn));
		if (ray->dist < ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov)
		{
			ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = ray->dist;
			ray->ray_angle_fov_s[ray->angle_count]->angle = ray->angle;
			ray->ray_angle_fov_s[ray->angle_count]->orientation = 4;
			ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture
				= player->pos_y - ray->yn - ray->text_y * 100;
		}	
	}
}
