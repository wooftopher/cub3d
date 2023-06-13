/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:34:38 by cperron           #+#    #+#             */
/*   Updated: 2023/06/11 14:20:22 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"
#include "../../libs/Libft/libft.h"

void	free_ray(t_cub3d *cub3d, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(cub3d->ray->ray_angle_fov_s[i++]);
		cub3d->ray->ray_angle_fov_s[i] = NULL;
	}
	free(cub3d->ray->ray_angle_s);
	cub3d->ray->ray_angle_s = NULL;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Alloc failure\n", 2);
}

int8_t	init_rayz(t_cub3d *cub3d)
{
	int					i;
	t_ray_angle_fov_s	*ray_angle_fov_s[1500];
	t_ray_angle_s		*ray_angle_s;

	ray_angle_s = calloc(1, sizeof(t_ray_angle_s));
	cub3d->ray->ray_angle_s = ray_angle_s;
	if (!cub3d->ray->ray_angle_s)
		return (free_ray(cub3d, 0), -1);
	i = 0;
	while (i <= 1400)
	{
		ray_angle_fov_s[i] = calloc(1, sizeof(t_ray_angle_fov_s));
		cub3d->ray->ray_angle_fov_s[i] = ray_angle_fov_s[i];
		if (!cub3d->ray->ray_angle_fov_s[i])
		{
			free_ray(cub3d, i);
			return (-1);
		}
		i++;
	}
	cub3d->ray->fov_angle = 30;
	// cub3d.ray->angle_div = 0.035714f;
	cub3d->ray->angle_div = 0.042857f;
	return (0);
}
