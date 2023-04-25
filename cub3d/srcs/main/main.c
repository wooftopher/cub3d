/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/04/24 23:46:22 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//cacul the minimum distance between
//the player and a wall with the player angle
void	calcul_ray_to_wall(t_player *player, t_map *map, t_ray *ray)
{
	int	j;

	j = 0;
	ray->min_dist = INT_MAX;
	if (cos(player->angle * M_PI / 180) < 0)
		ray_hor_up(player, map, ray, j);
	else
		ray_hor_down(player, map, ray, j);
	// printf("hor :%d\n", hor_inter);
	// printf("dist minm :%d\n", ray->min_dist);
}

void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	ft_move(cub3d);
	ft_rotate(cub3d);
	if (cub3d->tic == 10)
	{
		calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
		cub3d->tic = 0;
	}
	// set_direction_indicator(cub3d->player, cub3d->mlx);
	set_direction_indicator_2(cub3d->player, cub3d->mlx, cub3d->ray);
	cub3d->tic++;
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(cub3d->mlx->mlx);
		free(cub3d->map->wall_px);
		free(cub3d->map->wall_py);
		free(cub3d->map->map);
		exit (0);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		usleep(10);
		// calcul_ray_to_object_hor(cub3d->player,cub3d->map, cub3d->ray);
	}
}

int main(void)
{
    t_cub3d 	cub3d;
	t_mlx_struc mlx;
	t_map		map;
	t_player	player;
	t_ray		ray;
    
	cub3d.mlx = &mlx;
	cub3d.map = &map;
	cub3d.player = &player;
	cub3d.ray = &ray;
	cub3d.tic = 0;
    ft_map_init(&cub3d);
	cub3d.mlx->mlx = mlx_init(cub3d.map->lenght * 100, cub3d.map->height * 100, "cub3d", true);
	if (!cub3d.mlx)
	    perror("Error opening mlx");
	ft_create_map(cub3d.map, &cub3d);
	mlx_key_hook(cub3d.mlx->mlx, key_hook, &cub3d);
	mlx_loop_hook(cub3d.mlx->mlx, ft_loop, &cub3d);
	mlx_loop(cub3d.mlx->mlx);
	return (0);
}

// void	calcul_ray_to_object_dis(t_player *player, t_map *map, t_ray *ray)
// {
// 	int j;
// 	int	i;

// 	j = 0;
// 	// calculate the x and y components of the ray direction vector
// 	ray->dir_x = sin(player->angle * M_PI / 180);
// 	ray->dir_y = cos(player->angle * M_PI / 180);

// 	ray->min_dist = INT_MAX;
// 	// loop over each wall in the map
// 	while (j < map->wall_count)
// 	{
// 		// calculate the intersection point between the ray and the current wall
// 		// ray->inter_x = (map->wall_px[j] + 50 - player->pos_x) / ray->dir_x;
// 		// ray->inter_y = (map->wall_py[j] - player->pos_y) / ray->dir_y;
		
// 		// calculate the distance between the player and the intersection point
// 		ray->dist = sqrt((ray->inter_x * ray->inter_x)
// 			+ (ray->inter_y * ray->inter_y));
		
// 		// if the intersection point is on the correct side of
// 		//the player and closer than the previous closest point,
// 		//update the minimum distance
// 		if ((ray->inter_x > 0 || ray->inter_y > 0)
// 			&& (ray->dist < ray->min_dist))
// 		// if (ray->dist < ray->min_dist)
// 		{
// 			ray->min_dist = ray->dist;
// 		}
// 		j++;
// 	}
// 	printf("dist minm :%d\n", ray->min_dist);
// 	// store the minimum distance found in the variable
// 	// rayDist = minDist;
// }