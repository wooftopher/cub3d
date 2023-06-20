/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 03:30:30 by christo           #+#    #+#             */
/*   Updated: 2023/06/20 05:45:35 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

int	find_y(t_cub3d *cub3d, int i, int wall_h, uint32_t txt_height)
{
	double	normalized_position;
	int		y_pixel_pos;
	int		y;

	if (i < 0)
	{
		normalized_position = (double)i / -wall_h;
		y_pixel_pos = (int)round((normalized_position + 1.0)
				* txt_height / 2);
	}
	else
	{
		normalized_position = (double)i / wall_h;
		y_pixel_pos = txt_height / 2
			- (int)round(normalized_position * txt_height / 2.5);
	}
	y = y_pixel_pos - txt_height / 20;
	if (y >= txt_height)
		y = txt_height - 1;
	return (y);
}

void	check_orientation_1(t_cub3d *cub3d, int k, int i, int wall_height)
{
	int	x;
	int	y;

	if (cub3d->ray->ray_angle_fov_s[k]->orientation == 1)
	{
		y = find_y(cub3d, i, wall_height,
				cub3d->mlx_s->txt_wall_n->height);
		x = round((cub3d->ray->ray_angle_fov_s[k]->pos_on_texture)
				* cub3d->mlx_s->txt_wall_n->width / 100);
		if (x >= cub3d->mlx_s->txt_wall_n->width)
			x = cub3d->mlx_s->txt_wall_n->width - 1;
		mlx_put_pixel(cub3d->mlx_s->img_wall_3d, 1400 - k, 450 - i,
			cub3d->map->north[y][x]);
	}
	else if (cub3d->ray->ray_angle_fov_s[k]->orientation == 2)
	{
		y = find_y(cub3d, i, wall_height,
				cub3d->mlx_s->txt_wall_s->height);
		x = round((cub3d->ray->ray_angle_fov_s[k]->pos_on_texture)
				* cub3d->mlx_s->txt_wall_s->width / 100);
		if (x >= cub3d->mlx_s->txt_wall_s->width)
			x = cub3d->mlx_s->txt_wall_s->width - 1;
		mlx_put_pixel(cub3d->mlx_s->img_wall_3d, 1400 - k, 450 - i,
			cub3d->map->south[y][x]);
	}
}

void	check_orientation_2(t_cub3d *cub3d, int k, int i, int wall_height)
{
	int	x;
	int	y;

	if (cub3d->ray->ray_angle_fov_s[k]->orientation == 3)
	{
		y = find_y(cub3d, i, wall_height,
				cub3d->mlx_s->txt_wall_e->height);
		x = round((cub3d->ray->ray_angle_fov_s[k]->pos_on_texture)
				* cub3d->mlx_s->txt_wall_e->width / 100);
		if (x >= cub3d->mlx_s->txt_wall_e->width)
			x = cub3d->mlx_s->txt_wall_e->width - 1;
		mlx_put_pixel(cub3d->mlx_s->img_wall_3d, 1400 - k, 450 - i,
			cub3d->map->east[y][x]);
	}
	else if (cub3d->ray->ray_angle_fov_s[k]->orientation == 4)
	{
		y = find_y(cub3d, i, wall_height,
				cub3d->mlx_s->txt_wall_w->height);
		x = round((cub3d->ray->ray_angle_fov_s[k]->pos_on_texture)
				* cub3d->mlx_s->txt_wall_w->width / 100);
		if (x >= cub3d->mlx_s->txt_wall_w->width)
				x = cub3d->mlx_s->txt_wall_w->width - 1;
		mlx_put_pixel(cub3d->mlx_s->img_wall_3d, 1400 - k, 450 - i,
			cub3d->map->west[y][x]);
	}
}

int	fish_eye_correction(t_cub3d *cub3d, int k, float wall_height)
{
	float	correction_factor;

	correction_factor = (cub3d->player->angle
			- cub3d->ray->ray_angle_fov_s[k]->angle);
	wall_height = 45000 / (cub3d->ray->ray_angle_fov_s[k]->min_dist_fov
			* cos(correction_factor * M_PI / 180));
	return (wall_height);
}
