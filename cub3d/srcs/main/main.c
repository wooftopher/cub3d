/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/04/19 16:05:19 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../map/map.h"
#include "struct.h"

void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_UP))
		cub3d->img_player->instances[0].y -= 5;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_DOWN))
		cub3d->img_player->instances[0].y += 5;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_RIGHT))
		cub3d->img_player->instances[0].x += 5;
	if (mlx_is_key_down(cub3d->mlx, MLX_KEY_LEFT))
		cub3d->img_player->instances[0].x -= 5;
	// ft_set_p_hitbox(game);


}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(cub3d->mlx);
		exit (0);
	}
}

int main(void)
{
    t_cub3d cub3d;
    
    ft_map_init(&cub3d);
	// cub3d.mlx = mlx_init(cub3d.map->lenght * 100, cub3d.map->height * 100, "cub3d", true);
	// if (!cub3d.mlx)
	//     perror("Error opening mlx");
	// ft_create_map(cub3d.map, &cub3d);
	// ft_pamam_init(&game);
	// ft_read_map(&game);
	mlx_key_hook(cub3d.mlx, key_hook, &cub3d);
	mlx_loop_hook(cub3d.mlx, ft_loop, &cub3d);
	mlx_loop(cub3d.mlx);
	return (0);
}