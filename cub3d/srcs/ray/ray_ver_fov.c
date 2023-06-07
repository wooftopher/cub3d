/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ver_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:32:47 by cperron           #+#    #+#             */
/*   Updated: 2023/06/07 02:30:43 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

void	check_ray_col_ver_right_fov(t_map *map, t_player *player, t_ray *ray, int j)
{
	int	i;
	int	y;
	int k;
	
	i = 0;
	k = 0;
	y = (player->pos_x) / 100 + j + 1;
	while (i < map->wall_count)
	{
		if (map->wall_px[i] != y *  100)
			i++;
		else if (player->pos_x + ray->xn == map->wall_px[i]
				&& player->pos_x + ray->xn <= map->wall_px[i] + 100
				&& player->pos_y - ray->yn >= map->wall_py[i]
				&& player->pos_y - ray->yn <= map->wall_py[i] + 100) //3
				{
					// remove_fish_eye(ray);
					ray->dist = sqrt((ray->xn * ray->xn)
						+ (ray->yn * ray->yn));
					// while (k <= ray->angle_count)
					// {
						if (ray->dist < ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov)
						{
							ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = ray->dist;
							ray->ray_angle_fov_s[ray->angle_count]->angle = ray->angle;
							ray->ray_angle_fov_s[ray->angle_count]->orientation = 4;
							ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture
								= player->pos_y - ray->yn - map->wall_py[i];
						}
						// k++;
					// }
					i++;
				}	
		else
		 	i++;
	}
}

void	check_ray_col_ver_left_fov(t_map *map, t_player *player, t_ray *ray, int j)
{
	int	i;
	int	y; //float?
	int k;
	
	i = 0;
	k = 0;
	y = (player->pos_x) / 100 - j - 1;
	while (i < map->wall_count)
	{
		if (map->wall_px[i] != y *  100)
			i++;
		else
		 if (player->pos_x - ray->xn >= map->wall_px[i]
				&& player->pos_x - ray->xn == map->wall_px[i] + 100
				&& player->pos_y + ray->yn >= map->wall_py[i]
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
							ray->ray_angle_fov_s[ray->angle_count]->angle = ray->angle;
							ray->ray_angle_fov_s[ray->angle_count]->orientation = 3;
							ray->ray_angle_fov_s[ray->angle_count]->pos_on_texture
								= 100 - (player->pos_y + ray->yn - map->wall_py[i]);
						}
					// 	k++;
					// }
					i++;
				}	
		else
		 	i++;
	}
}

void	ray_ver_left_fov(t_player *player, t_map *map, t_ray *ray, int j)
{
	float ys;
	float xs;
	int nb_inter;
	
	xs = 100;
	ys = xs * (tan((ray->angle - 90) * M_PI / 180));
	ray->xn = player->pos_x - (floor(player->pos_x  / 100)) * 100;
	ray->yn = ray->xn * (tan((ray->angle - 90) * M_PI / 180));
	nb_inter = floor(player->pos_x / 100);
	while (j < nb_inter)
	{
		check_ray_col_ver_left_fov(map, player, ray, j);
		ray->yn += ys;
		ray->xn += xs;
		j++;
	}
}

void	ray_ver_right_fov(t_player *player, t_map *map, t_ray *ray, int j)
{
	float ys;
	float xs;
	int nb_inter;
	
	xs = 100;
	ys = xs * (tan((ray->angle - 90) * M_PI / 180));
	ray->xn = ((floor(player->pos_x / 100)) + 1) * 100 - player->pos_x;
	ray->yn = ray->xn * (tan((ray->angle - 90) * M_PI / 180));
	nb_inter = map->lenght - (floor(player->pos_x / 100)) - 1;
	while (j < nb_inter)
	{
		check_ray_col_ver_right_fov(map, player, ray, j);
		ray->yn += ys;
		ray->xn += xs;
		j++;
	}
}
