/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:40:34 by christo           #+#    #+#             */
/*   Updated: 2023/04/24 23:46:00 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object.h"

void	check_ray_col_hor_up(t_map *map, t_player *player, t_ray *ray, int j)
{
	int	i;
	int	y;
	
	i = 0;
	y = (player->pos_y) / 100 - j - 1;
	while (i < map->wall_count)
	{
		if (map->wall_py[i] != y *  100)
			i++;
		else if (player->pos_x + ray->xn > map->wall_px[i]
				&& player->pos_x + ray->xn < map->wall_px[i] + 100
				&& player->pos_y - ray->yn < map->wall_py[i] + 101
				&& player->pos_y - ray->yn >= map->wall_py[i])
				{
					ray->dist = sqrt((ray->xn * ray->xn)
						+ (ray->yn * ray->yn));
					if (ray->dist < ray->min_dist)
						ray->min_dist = ray->dist;
					i++;
				}	
		else
		 	i++;
	}
}

void	check_ray_col_hor_down(t_map *map, t_player *player, t_ray *ray, int j)
{
	int	i;
	int	y;
	
	i = 0;
	y = (player->pos_y) / 100 + j + 1;
	while (i < map->wall_count)
	{
		if (map->wall_py[i] != y *  100)
			i++;
		else
		 if (player->pos_x - ray->xn > map->wall_px[i]
				&& player->pos_x - ray->xn < map->wall_px[i] + 100
				&& player->pos_y + ray->yn >= map->wall_py[i] - 1
				&& player->pos_y + ray->yn < map->wall_py[i] + 100)
				{
					ray->dist = sqrt((ray->xn * ray->xn)
						+ (ray->yn * ray->yn));
					if (ray->dist < ray->min_dist)
						ray->min_dist = ray->dist;
					i++;
				}	
		else
		 	i++;
	}
}

void ray_hor_down(t_player *player, t_map *map, t_ray *ray, int j)
{
	int ys;
	int xs;
	int hor_inter;
	
	ys = 100;
	xs = ys / (tan((player->angle - 90) * M_PI / 180));
	ray->yn = ((player->pos_y  / 100) + 1) * 100 - player->pos_y ;
	ray->xn = ray->yn / (tan((player->angle - 90) * M_PI / 180));
	hor_inter = (map->height - player->pos_y / 100) - 1;
	while (j < hor_inter)
	{
		check_ray_col_hor_down(map, player, ray, j);
		ray->yn += ys;
		ray->xn += xs;
		j++;
	}
	
}

void ray_hor_up(t_player *player, t_map *map, t_ray *ray, int j)
{
	int ys;
	int xs;
	int hor_inter;
	
	ys = 100;
	xs = ys / (tan((player->angle - 90) * M_PI / 180));
	ray->yn = player->pos_y - (player->pos_y  / 100) * 100;
	ray->xn = ray->yn / (tan((player->angle - 90) * M_PI / 180));
	hor_inter = player->pos_y / 100;
	while (j < hor_inter)
	{
		check_ray_col_hor_up(map, player, ray, j);
		ray->yn += ys;
		ray->xn += xs;
		j++;
	}
}