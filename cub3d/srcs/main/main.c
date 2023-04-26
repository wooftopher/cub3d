/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/04/26 16:26:46 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// cacul the minimum distance between
// the player and a wall with the player angle
void	calcul_ray_to_wall(t_player *player, t_map *map, t_ray *ray)
{
	int	j;

	j = 0;
	ray->min_dist = INT_MAX;
	if (cos(player->angle * M_PI / 180) < 0 && player->angle != 270)
		ray_hor_up(player, map, ray, j);
	else if(player->angle != 90)
		ray_hor_down(player, map, ray, j);
	if (sin(player->angle * M_PI / 180) > 0)
		ray_ver_right(player, map, ray, j);
	else
		ray_ver_left(player, map, ray, j);
}

void	calcul_ray_to_wall_fov(t_player *player, t_map *map, t_ray *ray)
{
	int	j;
	float fov_angle;

	j = 0;
	ray->angle_count = 0;
	fov_angle = -ray->fov_angle;
	ray->angle = player->angle - ray->fov_angle;
	while(fov_angle <= ray->fov_angle)
	{
		ray->min_dist_fov[ray->angle_count] = INT_MAX;
		if (cos(ray->angle * M_PI / 180) < 0 && ray->angle != 270)
			ray_hor_up_fov(player, map, ray, j);
		else if(ray->angle != 90)
			ray_hor_down_fov(player, map, ray, j);
		if (sin(ray->angle * M_PI / 180) > 0)
			ray_ver_right_fov(player, map, ray, j);
		else
			ray_ver_left_fov(player, map, ray, j);
		ray->angle += ray->angle_div;
		fov_angle += ray->angle_div;
		ray->angle_count++;
	}
}

void ft_render(t_ray *ray, t_mlx_struc *mlx)
{
	int	i;
	float	wall_height;
	
	// i = 0;
	wall_height = 4000 / ray->min_dist;
	if (mlx->img_wall_3d)
		mlx_delete_image(mlx->mlx, mlx->img_wall_3d);
	mlx->img_wall_3d = mlx_new_image(mlx->mlx, 1900, 900);
	i = -wall_height;
	while (i < wall_height)
	{
		mlx_put_pixel(mlx->img_wall_3d, 950, 450 + i, 0xFFFFFF);
		i++;
	}
	mlx_image_to_window(mlx->mlx, mlx->img_wall_3d, 0, 0);
}

void ft_render_fov(t_ray *ray, t_mlx_struc *mlx)
{
	int	i;
	float j;
	int k;
	int	wall_height;
	
	// i = 0;
	k = 0;
	j = -ray->fov_angle;
	if (mlx->img_wall_3d)
		mlx_delete_image(mlx->mlx, mlx->img_wall_3d);
	mlx->img_wall_3d = mlx_new_image(mlx->mlx, 1900, 900);
	while (j < ray->angle_count - ray->fov_angle)
	{
		wall_height = 50000 / ray->min_dist_fov[k];
		i = -wall_height;
		if (i < -450)
			i = -450;
		while (i < floor(wall_height) && i < 450)
		{
			mlx_put_pixel(mlx->img_wall_3d, 950 + j * 4, 450 + i, 0xFFFFFF);
			i++;
		}
		k++;
		j++;
	}
	mlx_image_to_window(mlx->mlx, mlx->img_wall_3d, 0, 0);
}

void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	ft_move(cub3d);
	ft_rotate(cub3d);
	// if (cub3d->tic == 10)
	// {
	// // // 	calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
	// printf("cos(player->angle * M_PI / 180); %f\n", cos(cub3d->player->angle * M_PI / 180));
	// 	cub3d->tic = 0;
	// }
	if (cub3d->vision == 1)
	{
		calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator(cub3d->player, cub3d->mlx);
	}
	if (cub3d->vision == 2)
	{
		calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator_2(cub3d->player, cub3d->mlx, cub3d->ray);
	}
	if (cub3d->vision == 3)
	{
		calcul_ray_to_wall_fov(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator_3(cub3d->player, cub3d->mlx, cub3d->ray);
	}
	if (cub3d->vision == 4)
	{
		calcul_ray_to_wall_fov(cub3d->player,cub3d->map, cub3d->ray);
		ft_render_fov(cub3d->ray, cub3d->mlx);
	}
	// ft_render(cub3d->ray, cub3d->mlx);
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
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		cub3d->vision = 1;
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		cub3d->vision = 2;
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
		cub3d->vision = 3;
	if (keydata.key == MLX_KEY_4 && keydata.action == MLX_PRESS)
		cub3d->vision = 4;
}

int main(void)
{
    t_cub3d 	cub3d;
	t_mlx_struc mlx;
	t_map		map;
	t_player	player;
	t_ray		ray;

	int32_t width;
	int32_t height;
    
	cub3d.mlx = &mlx;
	cub3d.map = &map;
	cub3d.player = &player;
	cub3d.ray = &ray;
	cub3d.ray->fov_angle = 25;
	cub3d.ray->angle_div = 0.2f;
	cub3d.tic = 0;
	cub3d.vision = 4;
    ft_map_init(&cub3d);
	// mlx_get_monitor_size(0, &width, &height);
	// cub3d.mlx->mlx->width = width;
	// cub3d.mlx->mlx->height = height;
	// cub3d.mlx->mlx = mlx_init(width,
	// 	height, "cub3d", true);
	// cub3d.mlx->mlx = mlx_init(cub3d.map->lenght * 100, cub3d.map->height * 100, "cub3d", true);
	cub3d.mlx->mlx = mlx_init(1900, 900, "cub3d", true);
	if (!cub3d.mlx)
	    perror("Error opening mlx");
	ft_create_map(cub3d.map, &cub3d);
	mlx_key_hook(cub3d.mlx->mlx, key_hook, &cub3d);
	mlx_loop_hook(cub3d.mlx->mlx, ft_loop, &cub3d);
	mlx_loop(cub3d.mlx->mlx);
	return (0);
}
