/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:34:38 by cperron           #+#    #+#             */
/*   Updated: 2023/06/22 12:56:31 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray_bonus.h"
#include "../../libs/Libft/libft.h"

static void	free_ray(t_cub3d *cub3d, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(cub3d->ray->ray_angle_fov_s[i++]);
		cub3d->ray->ray_angle_fov_s[i] = NULL;
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Alloc failure\n", 2);
}

int8_t	init_rayz(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i <= 1400)
	{
		cub3d->ray->ray_angle_fov_s[i]
			= ft_calloc(1, sizeof(t_ray_angle_fov_s));
		if (!cub3d->ray->ray_angle_fov_s[i])
		{
			free_ray(cub3d, i);
			return (-1);
		}
		i++;
	}
	cub3d->ray->fov_angle = 30;
	cub3d->ray->angle_div = 0.042857f;
	return (0);
}
