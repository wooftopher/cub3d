/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/06/08 21:48:28 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_map *map, t_cub3d *cub3d)
{
	uint16_t	index;

	index = 0;
	while (index <= 1400)
		free(cub3d->ray->ray_angle_fov_s[index++]);
	free_int_array(cub3d->map->north, cub3d->mlx_s->txt_wall_n->height);
	free_int_array(cub3d->map->south, cub3d->mlx_s->txt_wall_n->height);
	free_int_array(cub3d->map->west, cub3d->mlx_s->txt_wall_n->height);
	free_int_array(cub3d->map->east, cub3d->mlx_s->txt_wall_n->height);
	mlx_delete_texture(cub3d->mlx_s->txt_wall_n);
	mlx_delete_texture(cub3d->mlx_s->txt_wall_s);
	mlx_delete_texture(cub3d->mlx_s->txt_wall_e);
	mlx_delete_texture(cub3d->mlx_s->txt_wall_w);
	free(cub3d->ray->ray_angle_s);
	map_struct_destructor(map);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d = param;
	int i;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub3d->mlx_s->mlx);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		usleep(10);
	}
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		cub3d->vision = 1;
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		cub3d->vision = 2;
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
		cub3d->vision = 3;
	if (keydata.key == MLX_KEY_4 && keydata.action == MLX_PRESS)
		cub3d->vision = 4;
}

void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	ft_move(cub3d);
	ft_rotate(cub3d);
	ft_calcul_render(cub3d);
}

int main(void)
{
    t_cub3d 	cub3d;
	t_mlx_struc mlx_s;
	t_map		map;
	t_player	player;
	t_ray		ray;
 
	cub3d.mlx_s = &mlx_s;
	cub3d.map = &map;
	cub3d.player = &player;
	cub3d.ray = &ray;
	cub3d.tic = 0;
	cub3d.vision = 4;
    // ft_map_init(&cub3d);
	map_initialization(&map, "./map/fuck.cub");
	if (map.map_errno)
	{
		print_map_errno(map.map_errno);
		exit(0);
	}
	init_ray(&cub3d, &map);
	cub3d.mlx_s->mlx = mlx_init(1400, 900, "cub3d", true); 
	ft_create_map(cub3d.map, &cub3d);
	mlx_loop_hook(cub3d.mlx_s->mlx, ft_loop, &cub3d);
	mlx_key_hook(cub3d.mlx_s->mlx, key_hook, &cub3d);
	mlx_loop(cub3d.mlx_s->mlx);
	free_all(&map, &cub3d);
	mlx_terminate(cub3d.mlx_s->mlx);
	return (0);
}
