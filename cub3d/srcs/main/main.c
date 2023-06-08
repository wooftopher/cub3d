/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/06/07 22:58:30 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_stuff(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while ( i < 1400)
	{
		free(cub3d->ray->ray_angle_fov_s[i]);
		i++;
	}
	free(cub3d->map->wall_px);
	free(cub3d->map->wall_py);
	free(cub3d->map->map);
	free(cub3d->ray->ray_angle_s);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d = param;
	int i;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(cub3d->mlx_s->mlx);
		free_stuff(cub3d);
		return ;
	}
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
	map_initialization(&map, "./map/wrong.cub");
	for (int i = 0; map.map[i]; i++)
		printf("%s\n", map.map[i]);
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
	map_struct_destructor(&map);
	return (0);
}
