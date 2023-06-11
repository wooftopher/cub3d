/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:06:19 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/10 23:54:14 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "struct.h"

static void	del_text(t_cub3d *cub3d, uint8_t flag, char *message)
{
	if (flag == 1)
		mlx_delete_texture(cub3d->mlx_s->txt_wall_n);
	else if (flag == 2)
	{
		mlx_delete_texture(cub3d->mlx_s->txt_wall_n);
		mlx_delete_texture(cub3d->mlx_s->txt_wall_s);
	}
	else if (flag == 3)
	{
		mlx_delete_texture(cub3d->mlx_s->txt_wall_n);
		mlx_delete_texture(cub3d->mlx_s->txt_wall_s);
		mlx_delete_texture(cub3d->mlx_s->txt_wall_e);
	}
	else if (flag == 4)
	{
		mlx_delete_texture(cub3d->mlx_s->txt_wall_n);
		mlx_delete_texture(cub3d->mlx_s->txt_wall_s);
		mlx_delete_texture(cub3d->mlx_s->txt_wall_e);
		mlx_delete_texture(cub3d->mlx_s->txt_wall_w);
	}
	ft_putstr_fd(message, STDERR_FILENO);
}

static int8_t	init_texture(t_cub3d *cub3d, t_map *map)
{	
	cub3d->mlx_s->txt_wall_n = mlx_load_png(map->n_texture);
	if (!cub3d->mlx_s->txt_wall_n)
		return (del_text(cub3d, 0, "Couldn't load north map texture\n"), -1);
	cub3d->mlx_s->txt_wall_s = mlx_load_png(map->s_texture);
	if (!cub3d->mlx_s->txt_wall_s)
		return (del_text(cub3d, 1, "Couldn't load south map texture\n"), -1);
	cub3d->mlx_s->txt_wall_e = mlx_load_png(map->e_texture);
	if (!cub3d->mlx_s->txt_wall_e)
		return (del_text(cub3d, 2, "Couldn't load east map texture\n"), -1);
	cub3d->mlx_s->txt_wall_w = mlx_load_png(map->w_texture);
	if (!cub3d->mlx_s->txt_wall_w)
		return (del_text(cub3d, 3, "Couldn't load west map texture\n"), -1);
	cub3d->map->north = fill_int_array(cub3d->mlx_s->txt_wall_n);
	if (!cub3d->map->north)
		return (del_text(cub3d, 4, "Allocation failure\n"), -1);
	cub3d->map->south = fill_int_array(cub3d->mlx_s->txt_wall_s);
	if (!cub3d->map->south)
		return (del_text(cub3d, 4, "Allocation failure\n"), -1);
	cub3d->map->east = fill_int_array(cub3d->mlx_s->txt_wall_e);
	if (!cub3d->map->east)
		return (del_text(cub3d, 4, "Allocation failure\n"), -1);
	cub3d->map->west = fill_int_array(cub3d->mlx_s->txt_wall_w);
	if (!cub3d->map->west)
		return (del_text(cub3d, 4, "Allocation failure\n"), -1);
	return (0);
}

static void	free_ray(t_cub3d *cub3d, int index)
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
	ft_putstr_fd("Alloc failure\n", STDERR_FILENO);
}

static int8_t	init_rayz(t_cub3d *cub3d)
{
	int					i;
	t_ray_angle_fov_s	*ray_angle_fov_s[1500];
	t_ray_angle_s		*ray_angle_s;

	ray_angle_s = calloc(1, sizeof(t_ray_angle_s));
	cub3d->ray->ray_angle_s = ray_angle_s;
	if (!cub3d->ray->ray_angle_s)
		return (free_ray(cub3d, 0), FAILURE);
	i = 0;
	while (i <= 1400)
	{
		ray_angle_fov_s[i] = calloc(1, sizeof(t_ray_angle_fov_s));
		cub3d->ray->ray_angle_fov_s[i] = ray_angle_fov_s[i];
		if (!cub3d->ray->ray_angle_fov_s[i])
		{
			free_ray(cub3d, i);
			return (FAILURE);
		}
		i++;
	}
	cub3d->ray->fov_angle = 30;
	// cub3d.ray->angle_div = 0.035714f;
	cub3d->ray->angle_div = 0.042857f;
	return (0);
}

int8_t	initialization(t_cub3d *cub3d, t_map *map)
{
	cub3d->tic = 0;
	cub3d->vision = 4;
	cub3d->mlx_s->img_wall_3d = NULL;
	map_initialization(map, "./map/fuck.cub");
	if (map->map_errno)
		return (print_map_errno(map->map_errno), FAILURE);
	if (init_texture(cub3d, map))
		return (FAILURE);
	if (init_rayz(cub3d))
		return (FAILURE);
	return (SUCCESS);
}
