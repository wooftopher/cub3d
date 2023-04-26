/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hor_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:08:23 by cperron           #+#    #+#             */
/*   Updated: 2023/04/26 00:19:34 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object.h"

void	check_ray_col_hor_up_fov(t_map *map, t_player *player, t_ray *ray, int j)
{
	int	i;
	int	y;
	int k;
	
	i = 0;
	k = 0;
	y = (player->pos_y) / 100 - j - 1;
	while (i < map->wall_count)
	{
		if (map->wall_py[i] != y * 100)
			i++;
		else if (player->pos_x + ray->xn >= map->wall_px[i] - 1 //3
				&& player->pos_x + ray->xn <= map->wall_px[i] + 101
				&& player->pos_y - ray->yn >= map->wall_py[i] - 1
				&& player->pos_y - ray->yn <= map->wall_py[i] + 101)
				{
					ray->dist = sqrt((ray->xn * ray->xn)
						+ (ray->yn * ray->yn));
					while (k <= ray->angle_count)
					{
						if (ray->dist < ray->min_dist_fov[ray->angle_count])
							ray->min_dist_fov[ray->angle_count] = ray->dist;
						k++;
					}
					i++;
				}	
		else
		 	i++;
	}
}

void	check_ray_col_hor_down_fov(t_map *map, t_player *player, t_ray *ray, int j)
{
	int	i;
	int	y;
	int k;
	
	i = 0;
	k = 0;
	y = (player->pos_y) / 100 + j + 1;
	while (i < map->wall_count)
	{
		if (map->wall_py[i] != y * 100)
			i++;
		else if (player->pos_x - ray->xn >= map->wall_px[i] - 1
				&& player->pos_x - ray->xn <= map->wall_px[i] + 101 //3
				&& player->pos_y + ray->yn == map->wall_py[i] 
				&& player->pos_y + ray->yn <= map->wall_py[i] + 101)
				{
					ray->dist = sqrt((ray->xn * ray->xn)
						+ (ray->yn * ray->yn));
					while (k <= ray->angle_count)
					{
						if (ray->dist < ray->min_dist_fov[ray->angle_count])
							ray->min_dist_fov[ray->angle_count] = ray->dist;
							k++;
					}
					i++;
				}	
		else
		 	i++;
	}
}

void ray_hor_up_fov(t_player *player, t_map *map, t_ray *ray, int j)
{
	int ys;
	int xs;
	int nb_inter;
	
	ys = 100;
	xs = ys / (tan((ray->angle - 90) * M_PI / 180));
	ray->yn =player->pos_y - (floor((player->pos_y / 100))) * 100;
	ray->xn = ray->yn / (tan((ray->angle - 90) * M_PI / 180));
	nb_inter = player->pos_y / 100;
	while (j < nb_inter)
	{
		check_ray_col_hor_up_fov(map, player, ray, j);
		ray->yn += ys;
		ray->xn += xs;
		j++;
	}
}

void ray_hor_down_fov(t_player *player, t_map *map, t_ray *ray, int j)
{
	int ys;
	int xs;
	int nb_inter;
	
	ys = 100;
	xs = ys / (tan((ray->angle - 90) * M_PI / 180));
	ray->yn = (floor((player->pos_y  / 100)) + 1) * 100 - player->pos_y ;
	ray->xn = ray->yn / (tan((ray->angle - 90) * M_PI / 180));
	nb_inter = (map->height - floor(player->pos_y / 100)) - 1;
	while (j < nb_inter)
	{
		check_ray_col_hor_down_fov(map, player, ray, j);
		ray->yn += ys;
		ray->xn += xs;
		j++;
	}
}
