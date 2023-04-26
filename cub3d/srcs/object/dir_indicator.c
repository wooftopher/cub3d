/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_indicator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:45:18 by christo           #+#    #+#             */
/*   Updated: 2023/04/25 21:18:55 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object.h"

void	set_direction_indicator_3(t_player *player, t_mlx_struc *mlx, t_ray *ray)
{
	int i;
	int	d_x;
	int	d_y;
	float fov_angle;
	float angle_div;
	int k;

	i = 0;
	k = 0;
	
	fov_angle = -ray->fov_angle;

	ray->angle = player->angle - ray->fov_angle;
	angle_div = 5;

	
	if (mlx->img_dir_ind)
		mlx_delete_image(mlx->mlx, mlx->img_dir_ind);
	mlx->img_dir_ind = mlx_new_image(mlx->mlx, 1000, 1000);
	while(k <= ray->angle_count)
	{
		while(i < ray->min_dist_fov[k] && i < 500)
		{
			d_y = i * cos((ray->angle) * M_PI / 180);
			d_x = i * sin((ray->angle) * M_PI / 180);
			mlx_put_pixel(mlx->img_dir_ind, 500 + d_x, 500 + d_y, 0xFFFFFF);
			i++;
		}
		i = 0;
		k++;
		ray->angle += angle_div;
		fov_angle += 5;
	}
	mlx_image_to_window(mlx->mlx, mlx->img_dir_ind,
		player->pos_x - 500, player->pos_y - 500);
}

void	set_direction_indicator_2(t_player *player, t_mlx_struc *mlx, t_ray *ray)
{
	int i;
	int	d_x;
	int	d_y;

	i = 0;
	if (mlx->img_dir_ind)
		mlx_delete_image(mlx->mlx, mlx->img_dir_ind);
	mlx->img_dir_ind = mlx_new_image(mlx->mlx, 1000, 1000);
	while(i < ray->min_dist && i < 500)
	{
		d_y = i * cos(player->angle * M_PI / 180);
		d_x = i * sin(player->angle * M_PI / 180);
		mlx_put_pixel(mlx->img_dir_ind, 500 + d_x, 500 + d_y, 0xFFFFFF);
		i++;
	}
	mlx_image_to_window(mlx->mlx, mlx->img_dir_ind,
		player->pos_x - 500, player->pos_y - 500);
}

void	set_direction_indicator(t_player *player, t_mlx_struc *mlx)
{
	int 	i;
	float	d_x;
	float	d_y;

	i = 0;
	if (mlx->img_dir_ind)
		mlx_delete_image(mlx->mlx, mlx->img_dir_ind);
	mlx->img_dir_ind = mlx_new_image(mlx->mlx, 100, 100);
	while(i < 50)
	{
		d_y = i * cos(player->angle * M_PI / 180);
		d_x = i * sin(player->angle * M_PI / 180);
		mlx_put_pixel(mlx->img_dir_ind, 50 + d_x, 50 + d_y, 0xFFFFFF);
		i++;
	}
	mlx_image_to_window(mlx->mlx, mlx->img_dir_ind,
		player->pos_x - 50, player->pos_y - 50);
}