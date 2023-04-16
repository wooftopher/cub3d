/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/04/16 17:01:54 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../map/map.h"
#include "struct.h"

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
	cub3d.mlx = mlx_init(cub3d.map->lenght * 100, cub3d.map->height * 100, "cub3d", true);
	if (!cub3d.mlx)
	    perror("Error opening mlx");
	// ft_pamam_init(&game);
	// ft_read_map(&game);
	mlx_key_hook(cub3d.mlx, key_hook, &cub3d);
	// mlx_loop_hook(game.mlx, ft_loop, &game);
	mlx_loop(cub3d.mlx);
	return (0);
}