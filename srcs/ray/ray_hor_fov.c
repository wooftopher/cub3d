/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hor_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:08:23 by cperron           #+#    #+#             */
/*   Updated: 2023/06/21 14:34:35 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

int	col_up_v2(t_map *map, t_player *player, t_ray *ray)
{
	int		y;
	int		x;
	float	ys;
	float	xs;

	ys = 100;
	xs = ys / (tan((ray->angle - 90) * M_PI / 180));
	y = (player->pos_y - ray->yn) / 100 - 1;
	x = (player->pos_x + ray->xn) / 100;
	while (y >= 0 && x >= 0 && y < map->height && x < map->width)
	{
		if (map->map[y][x] == '1')
		{
			ray->text_x = x;
			return (1);
		}
		else
		{
			ray->yn += ys;
			ray->xn += xs;
		}
		y = (player->pos_y - ray->yn) / 100 - 1;
		x = (player->pos_x + ray->xn) / 100;
	}
	return (0);
}

void	ray_hor_up_fov(t_player *player, t_map *map, t_ray *ray, int j)
{
	ray->yn = player->pos_y - (floor((player->pos_y / 100))) * 100;
	ray->xn = ray->yn / (tan((ray->angle - 90) * M_PI / 180));
	if (col_up_v2(map, player, ray) == 1)
	{
		ray->dist = sqrt((ray->xn * ray->xn) + (ray->yn * ray->yn));
		ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = ray->dist;
		ray->ray_angle_fov_s[ray->angle_count]->angle = ray->angle;
		ray->ray_angle_fov_s[ray->angle_count]->orientation = 1;
		ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture
			= player->pos_x + ray->xn - ray->text_x * 100;
	}
}

int	col_down_v2(t_map *map, t_player *player, t_ray *ray)
{
	int		y;
	int		x;
	float	ys;
	float	xs;

	ys = 100;
	xs = ys / (tan((ray->angle - 90) * M_PI / 180));
	y = ((player->pos_y + ray->yn) / 100);
	x = ((player->pos_x - ray->xn) / 100);
	while (y >= 0 && x >= 0 && y < map->height && x < map->width)
	{
		if (map->map[y][x] == '1')
		{
			ray->text_x = x;
			return (1);
		}
		else
		{
			ray->yn += ys;
			ray->xn += xs;
		}
		y = round((player->pos_y + ray->yn) / 100);
		x = (player->pos_x - ray->xn) / 100;
	}
	return (0);
}

void	ray_hor_down_fov(t_player *player, t_map *map, t_ray *ray, int j)
{
	ray->yn = (floor((player->pos_y / 100)) + 1) * 100 - player->pos_y;
	ray->xn = ray->yn / (tan((ray->angle - 90) * M_PI / 180));
	if (col_down_v2(map, player, ray) == 1)
	{
		ray->dist = sqrt((ray->xn * ray->xn) + (ray->yn * ray->yn));
		ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = ray->dist;
		ray->ray_angle_fov_s[ray->angle_count]->angle = ray->angle;
		ray->ray_angle_fov_s[ray->angle_count]->orientation = 2;
		ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture
			= 100 - (player->pos_x - ray->xn - ray->text_x * 100);
	}
}
