/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 03:30:30 by christo           #+#    #+#             */
/*   Updated: 2023/06/10 14:54:33 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

int	find_y(t_cub3d *cub3d, int i, int wall_h)
{
    
	double normalized_position;
    int y_pixel_pos;

    if (i < 0) {
        normalized_position = (double)i / -wall_h;
        y_pixel_pos = (int) round((normalized_position + 1.0)
			* cub3d->mlx_s->txt_wall_n->height / 2);
    } else {
        normalized_position = (double)i / wall_h;
        y_pixel_pos = cub3d->mlx_s->txt_wall_n->height / 2
			- (int) round(normalized_position
				* cub3d->mlx_s->txt_wall_n->height / 2.5);
    }

    return (y_pixel_pos - cub3d->mlx_s->txt_wall_n->height / 20);
}

void	check_orientation_1(t_cub3d *cub3d, int k, int i, int wall_height)
{
	int x;
	int y;

	y = find_y(cub3d, i, wall_height);
	if(cub3d->ray->ray_angle_fov_s[k]->orientation == 1)
	{
		x = round((cub3d->ray->ray_angle_fov_s[k]->pos_on_texture)
			* cub3d->mlx_s->txt_wall_n->width / 100) ;
		if (x >= cub3d->mlx_s->txt_wall_n->width) //feature to fix
			x = cub3d->mlx_s->txt_wall_n->width - 1;
		mlx_put_pixel(cub3d->mlx_s->img_wall_3d, 1400 - k, 450 - i,
			cub3d->map->north[y][x]);
	}
	else if(cub3d->ray->ray_angle_fov_s[k]->orientation == 2)
	{
		x = round((cub3d->ray->ray_angle_fov_s[k]->pos_on_texture)
			* cub3d->mlx_s->txt_wall_s->width / 100);
		if (x >= cub3d->mlx_s->txt_wall_s->width) //feature to fix
			x = cub3d->mlx_s->txt_wall_s->width - 1;
		mlx_put_pixel(cub3d->mlx_s->img_wall_3d, 1400 - k, 450 - i,
			cub3d->map->south[y][x]);
	}
}

void	check_orientation_2(t_cub3d *cub3d, int k, int i, int wall_height)
{
	int x;
	int y;

	y = find_y(cub3d, i, wall_height);
	if(cub3d->ray->ray_angle_fov_s[k]->orientation == 3)
	{
		x = round((cub3d->ray->ray_angle_fov_s[k]->pos_on_texture)
			* cub3d->mlx_s->txt_wall_e->width / 100);
		if (x >= cub3d->mlx_s->txt_wall_e->width) //feature to fix
			x = cub3d->mlx_s->txt_wall_e->width - 1;
		mlx_put_pixel(cub3d->mlx_s->img_wall_3d, 1400 - k, 450 - i,
					cub3d->map->east[y][x]);
	}
	else if(cub3d->ray->ray_angle_fov_s[k]->orientation == 4)
	{
		x = round((cub3d->ray->ray_angle_fov_s[k]->pos_on_texture)
			* cub3d->mlx_s->txt_wall_w->width / 100);
		if (x >= cub3d->mlx_s->txt_wall_w->width) //feature to fix
			x = cub3d->mlx_s->txt_wall_w->width - 1;
		mlx_put_pixel(cub3d->mlx_s->img_wall_3d, 1400 - k, 450 - i,
			cub3d->map->west[y][x]);
	}
}

int fish_eye_correction(t_cub3d *cub3d, int k, float wall_height)
{
	float correction_factor;

	correction_factor = (cub3d->player->angle - cub3d->ray->ray_angle_fov_s[k]->angle);
	wall_height = 45000 / (cub3d->ray->ray_angle_fov_s[k]->min_dist_fov * cos(correction_factor * M_PI / 180));
	return (wall_height);
}

void	create_pixel_image(t_cub3d *cub3d)
{
	if (cub3d->mlx_s->img_wall_3d)
		mlx_delete_image(cub3d->mlx_s->mlx, cub3d->mlx_s->img_wall_3d);
	cub3d->mlx_s->img_wall_3d = mlx_new_image(cub3d->mlx_s->mlx, 1400, 1000);
}