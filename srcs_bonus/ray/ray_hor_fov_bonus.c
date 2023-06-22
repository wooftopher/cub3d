/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hor_fov_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:08:23 by cperron           #+#    #+#             */
/*   Updated: 2023/06/22 12:56:56 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray_bonus.h"

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
		if (map->map[y][x] == '1' || map->map[y][x] == '3'
			|| map->map[y][x] == '2')
			return (check_feature_x(map, ray, x, y));
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

void	ray_hor_up_fov(t_player *player, t_map *map, t_ray *ray)
{
	int	finish;

	ray->yn = player->pos_y - (floor((player->pos_y / 100))) * 100;
	ray->xn = ray->yn / (tan((ray->angle - 90) * M_PI / 180));
	finish = col_up_v2(map, player, ray);
	if (finish == 1 || finish == 2)
	{
		ray->dist = sqrt((ray->xn * ray->xn) + (ray->yn * ray->yn));
		if (ray->dist < ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov)
		{
			ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = ray->dist;
			ray->ray_angle_fov_s[ray->angle_count]->angle = ray->angle;
			if (finish == 1)
				ray->ray_angle_fov_s[ray->angle_count]->orientation = 1;
			else
				ray->ray_angle_fov_s[ray->angle_count]->orientation = 5;
			ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture
				= player->pos_x + ray->xn - ray->text_x * 100;
		}
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
	y = (player->pos_y + ray->yn) / 100;
	x = (player->pos_x - ray->xn) / 100;
	while (y >= 0 && x >= 0 && y < map->height && x < map->width)
	{
		if (map->map[y][x] == '1' || map->map[y][x] == '3'
			|| map->map[y][x] == '2')
			return (check_feature_x(map, ray, x, y));
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

void	ray_hor_down_fov(t_player *player, t_map *map, t_ray *ray)
{
	int	finish;

	ray->yn = (floor((player->pos_y / 100)) + 1) * 100 - player->pos_y;
	ray->xn = ray->yn / (tan((ray->angle - 90) * M_PI / 180));
	finish = col_down_v2(map, player, ray);
	if (finish == 1 || finish == 2)
	{
		ray->dist = sqrt((ray->xn * ray->xn) + (ray->yn * ray->yn));
		if (ray->dist < ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov)
		{
			ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = ray->dist;
			ray->ray_angle_fov_s[ray->angle_count]->angle = ray->angle;
			if (finish == 1)
				ray->ray_angle_fov_s[ray->angle_count]->orientation = 2;
			else
				ray->ray_angle_fov_s[ray->angle_count]->orientation = 5;
			ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture = 100
				- (player->pos_x - ray->xn - ray->text_x * 100);
		}
	}
}
