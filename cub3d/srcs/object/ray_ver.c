/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ver.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 02:45:21 by christo           #+#    #+#             */
/*   Updated: 2023/04/25 03:58:53 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./object.h"

void	check_ray_col_ver_right(t_map *map, t_player *player, t_ray *ray, int j)
{
	int	i;
	int	y;
	
	i = 0;
	y = (player->pos_x) / 100 + j + 1;
	while (i < map->wall_count)
	{
		if (map->wall_px[i] != y *  100)
			i++;
		else if (player->pos_x + ray->xn == map->wall_px[i]
				&& player->pos_x + ray->xn <= map->wall_px[i] + 100
				&& player->pos_y - ray->yn >= map->wall_py[i] + 1
				&& player->pos_y - ray->yn <= map->wall_py[i] + 100)
				{
					ray->dist = sqrt((ray->xn * ray->xn)
						+ (ray->yn * ray->yn));
					if (ray->dist < ray->min_dist)
						ray->min_dist = ray->dist;
						// ray->min_dist_fov[ray->fov_count] = ray->dist;
					i++;
				}	
		else
		 	i++;
	}
}

void	check_ray_col_ver_left(t_map *map, t_player *player, t_ray *ray, int j)
{
	int	i;
	int	y;
	
	i = 0;
	y = (player->pos_x) / 100 - j - 1;
	while (i < map->wall_count)
	{
		if (map->wall_px[i] != y *  100)
			i++;
		else
		 if (player->pos_x - ray->xn >= map->wall_px[i]
				&& player->pos_x - ray->xn == map->wall_px[i] + 100
				&& player->pos_y + ray->yn >= map->wall_py[i] - 1
				&& player->pos_y + ray->yn <= map->wall_py[i] + 100)
				{
					ray->dist = sqrt((ray->xn * ray->xn)
						+ (ray->yn * ray->yn));
					if (ray->dist < ray->min_dist)
						ray->min_dist = ray->dist;
						// ray->min_dist_fov[ray->fov_count] = ray->dist;
					i++;
				}	
		else
		 	i++;
	}
}

void	ray_ver_left(t_player *player, t_map *map, t_ray *ray, int j)
{
	int ys;
	int xs;
	int nb_inter;
	
	xs = 100;
	ys = xs * (tan((player->angle - 90) * M_PI / 180));
	ray->xn = player->pos_x - ((player->pos_x  / 100)) * 100;
	ray->yn = ray->xn * (tan((player->angle - 90) * M_PI / 180));
	nb_inter = player->pos_x / 100;
	while (j < nb_inter)
	{
		check_ray_col_ver_left(map, player, ray, j);
		ray->yn += ys;
		ray->xn += xs;
		j++;
	}
}

void	ray_ver_right(t_player *player, t_map *map, t_ray *ray, int j)
{
	int ys;
	int xs;
	int nb_inter;
	
	xs = 100;
	ys = xs * (tan((player->angle - 90) * M_PI / 180));
	ray->xn = ((player->pos_x  / 100) + 1) * 100 - player->pos_x;
	ray->yn = ray->xn * (tan((player->angle - 90) * M_PI / 180));
	nb_inter = map->lenght - (player->pos_x / 100)- 1;
	while (j < nb_inter)
	{
		check_ray_col_ver_right(map, player, ray, j);
		ray->yn += ys;
		ray->xn += xs;
		j++;
	}
}
