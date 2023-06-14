/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:22:32 by cperron           #+#    #+#             */
/*   Updated: 2023/06/14 17:08:46 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

void    calcul_ray_to_wall_fov(t_player *player, t_map *map, t_ray *ray)
{
    int j;
    float fov_angle;
    j = 0;
    ray->angle_count = 0;
    fov_angle = -ray->fov_angle;
    ray->angle = player->angle - ray->fov_angle;
    while(fov_angle <= ray->fov_angle)
    {
        ray->ray_angle_fov_s[ray->angle_count]->min_dist_fov = INT_MAX;
        if (cos(ray->angle * M_PI / 180) <= 0)
            ray_hor_up_fov(player, map, ray, j);
        else
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

static void	memset_image(uint32_t height, uint32_t width, uint8_t *image)
{
	uint32_t	index;
	uint32_t	length;

	length = (width * height) * 4;
	index = 3;
	while (index < length)
	{
		image[index] = 0x00;
		index += 4;
	}
}

void ft_render_fov(t_cub3d * cub3d, t_player *player, t_ray *ray, t_mlx_struc *mlx_s)
{
	int	i;
	float j;
	int k;
	int	wall_height;
	
	k = 0;
	j = -ray->fov_angle;
	memset_image(cub3d->mlx_s->img_wall_3d->width, cub3d->mlx_s->img_wall_3d->height, cub3d->mlx_s->img_wall_3d->pixels);
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
}

void	ft_calcul_render(t_cub3d *cub3d)
{
		calcul_ray_to_wall_fov(cub3d->player,cub3d->map, cub3d->ray);
		ft_render_fov(cub3d, cub3d->player, cub3d->ray, cub3d->mlx_s);
}