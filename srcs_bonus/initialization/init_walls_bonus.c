/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:55:30 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:58:19 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization_bonus.h"

void	free_ray(t_cub3d *cub3d, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(cub3d->ray->ray_angle_fov_s[i++]);
		cub3d->ray->ray_angle_fov_s[i] = NULL;
	}
	print_error("Alloc failure\n");
}

static int8_t	init_rayz(t_cub3d *cub3d)
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

static int8_t	init_texture(t_cub3d *cub3d, t_map *map)
{
	cub3d->mlx_s->txt_wall_n = mlx_load_png(map->n_texture);
	if (!cub3d->mlx_s->txt_wall_n)
		return (print_error("Couldn't load north map texture\n"));
	cub3d->mlx_s->txt_wall_s = mlx_load_png(map->s_texture);
	if (!cub3d->mlx_s->txt_wall_s)
		return (print_error("Couldn't load south map texture\n"));
	cub3d->mlx_s->txt_wall_e = mlx_load_png(map->e_texture);
	if (!cub3d->mlx_s->txt_wall_e)
		return (print_error("Couldn't load east map texture\n"));
	cub3d->mlx_s->txt_wall_w = mlx_load_png(map->w_texture);
	if (!cub3d->mlx_s->txt_wall_w)
		return (print_error("Couldn't load west map texture\n"));
	cub3d->map->north = fill_int_array(cub3d->mlx_s->txt_wall_n);
	if (!cub3d->map->north)
		return (print_error("Alloc failure\n"));
	cub3d->map->south = fill_int_array(cub3d->mlx_s->txt_wall_s);
	if (!cub3d->map->south)
		return (print_error("Alloc failure\n"));
	cub3d->map->east = fill_int_array(cub3d->mlx_s->txt_wall_e);
	if (!cub3d->map->east)
		return (print_error("Alloc failure\n"));
	cub3d->map->west = fill_int_array(cub3d->mlx_s->txt_wall_w);
	if (!cub3d->map->west)
		return (print_error("Alloc failure\n"));
	return (SUCCESS);
}

int8_t	init_walls(t_cub3d *cub3d)
{
	if (init_texture(cub3d, cub3d->map))
		return (FAILURE);
	if (init_end(cub3d))
		return (FAILURE);
	cub3d->mlx_s->img_wall_3d = mlx_new_image(cub3d->mlx_s->mlx, 1400, 1000);
	if (!cub3d->mlx_s->img_wall_3d)
		return (print_error("Alloc failure\n"), FAILURE);
	if (mlx_image_to_window(cub3d->mlx_s->mlx,
			cub3d->mlx_s->img_wall_3d, 0, 0) == FAILURE)
		return (print_error("Alloc failure\n"), FAILURE);
	if (init_rayz(cub3d))
		return (FAILURE);
	ft_create_map(cub3d->map, cub3d);
	return (SUCCESS);
}
