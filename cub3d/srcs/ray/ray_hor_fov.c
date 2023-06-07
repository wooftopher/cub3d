/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hor_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:08:23 by cperron           #+#    #+#             */
/*   Updated: 2023/06/06 19:31:31 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

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
		else if (player->pos_x + ray->xn >= map->wall_px[i] //3
				&& player->pos_x + ray->xn <= map->wall_px[i] + 100
				&& player->pos_y - ray->yn >= map->wall_py[i]
				&& player->pos_y - ray->yn <= map->wall_py[i] + 100)
				{
					// remove_fish_eye(ray);
					ray->dist = sqrt((ray->xn * ray->xn)
						+ (ray->yn * ray->yn));
					// while (k <= ray->angle_count)
					// {
						if (ray->dist < ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov)
						{
							ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = ray->dist;
							ray->ray_angle_fov_s[ray->angle_count]->orientation = 1;
							ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture
								= player->pos_x + ray->xn - map->wall_px[i];
						}
					// 	k++;
					// }
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
		else if (player->pos_x - ray->xn >= map->wall_px[i]
				&& player->pos_x - ray->xn <= map->wall_px[i] + 100 //3
				&& player->pos_y + ray->yn == map->wall_py[i] 
				&& player->pos_y + ray->yn <= map->wall_py[i] + 100)
				{
					// remove_fish_eye(ray);
					ray->dist = sqrt((ray->xn * ray->xn)
						+ (ray->yn * ray->yn));
					// while (k <= ray->angle_count)
					// {
						if (ray->dist < ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov)
						{
							ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = ray->dist;
							ray->ray_angle_fov_s[ray->angle_count]->orientation = 2;
							ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture
								=  100 - (player->pos_x - ray->xn - map->wall_px[i]);
						}
					// 	k++;
					// }
					i++;
				}	
		else
		 	i++;
	}
}

void ray_hor_up_fov(t_player *player, t_map *map, t_ray *ray, int j)
{
	float ys;
	float xs;
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
	float ys;
	float xs;
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
