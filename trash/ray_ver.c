// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ray_ver.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/04/25 02:45:21 by christo           #+#    #+#             */
// /*   Updated: 2023/06/07 19:26:49 by ddemers          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "./ray.h"

// void	check_ray_col_ver_right(t_map *map, t_player *player, t_ray *ray, int j)
// {
// 	int	i;
// 	int	y;
	
// 	i = 0;
// 	y = (player->pos_x) / 100 + j + 1;
// 	while (i < map->wall_count)
// 	{
// 		if (map->wall_px[i] != y *  100)
// 			i++;
// 		else if (player->pos_x + ray->xn == map->wall_px[i]
// 				&& player->pos_x + ray->xn <= map->wall_px[i] + 100
// 				&& player->pos_y - ray->yn >= map->wall_py[i]  //to fix
// 				&& player->pos_y - ray->yn <= map->wall_py[i] + 100)
// 				{
// 					ray->dist = sqrt((ray->xn * ray->xn)
// 						+ (ray->yn * ray->yn));
// 					if (ray->dist < ray->min_dist)
// 					{
// 							ray->min_dist = ray->dist;
// 							ray->ray_angle_s->min_dist_fov = ray->dist;
// 							ray->ray_angle_s->orientation = 4;
// 							ray->ray_angle_s->pos_on_texture
// 								= player->pos_y - ray->yn - map->wall_py[i];
// 					}
// 					i++;
// 				}	
// 		else
// 		 	i++;
// 	}
// }

// void	check_ray_col_ver_left(t_map *map, t_player *player, t_ray *ray, int j)
// {
// 	int	i;
// 	int	y;
	
// 	i = 0;
// 	y = (player->pos_x) / 100 - j - 1;
// 	while (i < map->wall_count)
// 	{
// 		if (map->wall_px[i] != y *  100)
// 			i++;
// 		else
// 		 if (player->pos_x - ray->xn >= map->wall_px[i]
// 				&& player->pos_x - ray->xn == map->wall_px[i] + 100
// 				&& player->pos_y + ray->yn >= map->wall_py[i] - 1
// 				&& player->pos_y + ray->yn <= map->wall_py[i] + 100)
// 				{
// 					ray->dist = sqrt((ray->xn * ray->xn)
// 						+ (ray->yn * ray->yn));
// 					if (ray->dist < ray->min_dist)
// 					{
// 							ray->min_dist = ray->dist;
// 							ray->ray_angle_s->min_dist_fov = ray->dist;
// 							ray->ray_angle_s->orientation = 3;
// 							ray->ray_angle_s->pos_on_texture
// 								= player->pos_y + ray->yn - map->wall_py[i];
// 					}
// 					i++;
// 				}	
// 		else
// 		 	i++;
// 	}
// }

// void	ray_ver_left(t_player *player, t_map *map, t_ray *ray, int j)
// {
// 	int ys;
// 	int xs;
// 	int nb_inter;
	
// 	xs = 100;
// 	ys = xs * (tan((player->angle - 90) * M_PI / 180));
// 	ray->xn = player->pos_x - (floor(player->pos_x  / 100)) * 100;
// 	ray->yn = ray->xn * (tan((player->angle - 90) * M_PI / 180));
// 	nb_inter = floor(player->pos_x / 100);
// 	while (j < nb_inter)
// 	{
// 		check_ray_col_ver_left(map, player, ray, j);
// 		ray->yn += ys;
// 		ray->xn += xs;
// 		j++;
// 	}
// }

// void	ray_ver_right(t_player *player, t_map *map, t_ray *ray, int j)
// {
// 	int ys;
// 	int xs;
// 	int nb_inter;
	
// 	xs = 100;
// 	ys = xs * (tan((player->angle - 90) * M_PI / 180));
// 	ray->xn = ((floor(player->pos_x / 100)) + 1) * 100 - player->pos_x;
// 	ray->yn = ray->xn * (tan((player->angle - 90) * M_PI / 180));
// 	nb_inter = map->height - (floor(player->pos_x / 100)) - 1;
// 	while (j < nb_inter)
// 	{
// 		check_ray_col_ver_right(map, player, ray, j);
// 		ray->yn += ys;
// 		ray->xn += xs;
// 		j++;
// 	}
// }