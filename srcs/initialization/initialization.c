/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:06:19 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/14 17:08:20 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static int8_t	print_error(const char *message)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, message, ft_strlen(message));
	return (FAILURE);
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

static void	init_cub3d_struct(t_cub3d *cub3d)
{
	cub3d->ray = NULL;
	cub3d->map = NULL;
	cub3d->player = NULL;
	cub3d->mlx_s = NULL;
}

static int8_t	alloc_struct(t_cub3d *cub3d)
{
	cub3d->map = ft_calloc(1, sizeof(t_map));
	if (!cub3d->map)
		return (FAILURE);
	cub3d->player = ft_calloc(1, sizeof(t_player));
	if (!cub3d->player)
		return (FAILURE);
	cub3d->ray = ft_calloc(1, sizeof(t_ray));
	if (!cub3d->ray)
		return (FAILURE);
	cub3d->mlx_s = ft_calloc(1, sizeof(t_mlx_struc));
	if (!cub3d->mlx_s)
		return (FAILURE);
	return (SUCCESS);
}

int8_t	initialization(t_cub3d *cub3d, char **argv)
{
	init_cub3d_struct(cub3d);
	if (alloc_struct(cub3d))
		return (print_error("Alloc failure\n"));
	map_initialization(cub3d->map, argv[1]);
	if (cub3d->map->map_errno)
		return (print_map_errno(cub3d->map->map_errno),
			FAILURE);
	if (init_texture(cub3d, cub3d->map))
		return (FAILURE);
	if (init_rayz(cub3d))
		return (FAILURE);
	cub3d->mlx_s->mlx = mlx_init(1400, 900, "cub3d", true);
	if (!cub3d->mlx_s->mlx)
		return (print_error("MLX INIT FAILURE\n"));
	if (ft_create_map(cub3d->map, cub3d))
		return (mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	cub3d->mlx_s->img_wall_3d = mlx_new_image(cub3d->mlx_s->mlx, 1400, 1000);
	if (!cub3d->mlx_s->img_wall_3d)
		return (print_error("MLX"), mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	if (mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_wall_3d,
			0, 0) == FAILURE)
		return (print_error("MLX"), mlx_terminate(cub3d->mlx_s->mlx), FAILURE);
	return (SUCCESS);
}
