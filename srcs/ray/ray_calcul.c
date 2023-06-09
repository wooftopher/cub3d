/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:22:32 by cperron           #+#    #+#             */
/*   Updated: 2023/06/07 03:46:13 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

void	calcul_ray_to_wall(t_player *player, t_map *map, t_ray *ray)
{
	int	j;
	t_ray_angle_s *ray_angle_s;
	
	ray_angle_s = calloc(1, sizeof(t_ray_angle_s));
	ray->ray_angle_s = ray_angle_s;
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
		ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = INT_MAX;
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

void ft_render_fov(t_cub3d * cub3d, t_player *player, t_ray *ray, t_mlx_struc *mlx_s)
{
	int	i;
	float j;
	int k;
	int	wall_height;
	
	k = 0;
	j = -ray->fov_angle;
	create_pixel_image(cub3d);
	while (j < ray->angle_count - ray->fov_angle)
	{
		wall_height = fish_eye_correction(cub3d, k, wall_height);;
		i = -wall_height;
		if (i < -450)
			i = -450;
		while (i < floor(wall_height) && i < 450)
		{
			check_orientation_1(cub3d, k, i, wall_height);
			check_orientation_2(cub3d, k, i, wall_height);
			i++;
		}
		k++;
		j++;
	}
	// set_direction_indicator_2(cub3d->player, cub3d->mlx_s, cub3d->ray);
	mlx_image_to_window(mlx_s->mlx, mlx_s->img_wall_3d, 0, 0);
}

void	ft_calcul_render(t_cub3d *cub3d)
{
	if (cub3d->tic == 60)
	{
		// printf("%f ", cub3d->ray->ray_angle_fov_s[650]->pos_on_texture);	
		cub3d->tic = 0;
	}
	if (cub3d->vision == 1)
	{
		calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator(cub3d->player, cub3d->mlx_s);
	}
	if (cub3d->vision == 3)
	{
		calcul_ray_to_wall_fov(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator_3(cub3d->player, cub3d->mlx_s, cub3d->ray);
	}
	if (cub3d->vision == 4)
	{
		calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
		calcul_ray_to_wall_fov(cub3d->player,cub3d->map, cub3d->ray);
		ft_render_fov(cub3d, cub3d->player, cub3d->ray, cub3d->mlx_s);
	}
	cub3d->tic++;
}