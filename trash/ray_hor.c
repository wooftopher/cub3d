// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ray_hor.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/04/24 23:40:34 by christo           #+#    #+#             */
// /*   Updated: 2023/06/10 21:32:15 by cperron          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "./ray.h"

// void	check_ray_col_hor_up(t_map *map, t_player *player, t_ray *ray, int j)
// {
// 	int	i;
// 	int	y;
	
// 	i = 0;
// 	y = (player->pos_y) / 100 - j - 1;
// 	while (i < map->wall_count)
// 	{
// 		if (map->wall_py[i] != y *  100)
// 			i++;
// 		else if (player->pos_x + ray->xn >= map->wall_px[i] - 3 //to fix float?
// 				&& player->pos_x + ray->xn <= map->wall_px[i] + 100
// 				&& player->pos_y - ray->yn >= map->wall_py[i]
// 				&& player->pos_y - ray->yn <= map->wall_py[i] + 100)
// 				{
// 					ray->dist = sqrt((ray->xn * ray->xn)
// 						+ (ray->yn * ray->yn));
// 					if (ray->dist < ray->min_dist)
// 						{
// 							ray->min_dist = ray->dist;
// 							ray->ray_angle_s->min_dist_fov = ray->dist;
// 							ray->ray_angle_s->orientation = 1;
// 							ray->ray_angle_s->pos_on_texture
// 								= player->pos_x + ray->xn - map->wall_px[i];
// 						}
// 					i++;
// 				}	
// 		else
// 		 	i++;
// 	}
// }

// void	check_ray_col_hor_down(t_map *map, t_player *player, t_ray *ray, int j)
// {
// 	int	i;
// 	int	y;
	
// 	i = 0;
// 	y = (player->pos_y) / 100 + j + 1;
// 	while (i < map->wall_count)
// 	{
// 		// if (map->wall_py[i] != y *  100)
// 		// 	i++;
// 		 if (player->pos_x - ray->xn >= map->wall_px[i]
// 				&& player->pos_x - ray->xn <= map->wall_px[i] + 103 //to fix
// 				&& player->pos_y + ray->yn >= map->wall_py[i]
// 				&& player->pos_y + ray->yn <= map->wall_py[i] + 100)
// 				{
// 					ray->dist = sqrt((ray->xn * ray->xn)
// 						+ (ray->yn * ray->yn));
// 					if (ray->dist < ray->min_dist)
// 					{
// 						ray->min_dist = ray->dist;
// 						ray->ray_angle_s->min_dist_fov = ray->dist;
// 						ray->ray_angle_s->orientation = 2;
// 						ray->ray_angle_s->pos_on_texture
// 							= player->pos_x - ray->xn - map->wall_px[i];
// 					}
// 					i++;
// 				}	
// 		else
// 		 	i++;
// 	}
// }


// void ray_hor_down(t_player *player, t_map *map, t_ray *ray, int j)
// {
// 	int ys;
// 	int xs;
// 	int nb_inter;
	
// 	ys = 100;
// 	xs = ys / (tan((player->angle - 90) * M_PI / 180));
// 	ray->yn = (floor((player->pos_y  / 100)) + 1) * 100 - player->pos_y ;
// 	ray->xn = ray->yn / (tan((player->angle - 90) * M_PI / 180));
// 	nb_inter = (map->height - floor(player->pos_y / 100)) - 1;
// 	while (j < nb_inter)
// 	{
// 		check_ray_col_hor_down(map, player, ray, j);
// 		ray->yn += ys;
// 		ray->xn += xs;
// 		j++;
// 	}
	
// }

// void ray_hor_up(t_player *player, t_map *map, t_ray *ray, int j)
// {
// 	int ys;
// 	int xs;
// 	int nb_inter;
	
// 	ys = 100;
// 	xs = ys / (tan((player->angle - 90) * M_PI / 180));
// 	ray->yn =player->pos_y - (floor((player->pos_y / 100))) * 100;
// 	ray->xn = ray->yn / (tan((player->angle - 90) * M_PI / 180));
// 	nb_inter = player->pos_y / 100;
// 	while (j < nb_inter)
// 	{
// 		check_ray_col_hor_up(map, player, ray, j);
// 		ray->yn += ys;
// 		ray->xn += xs;
// 		j++;
// 	}
// }
