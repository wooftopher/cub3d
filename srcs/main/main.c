/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/06/12 22:53:44 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d = param;


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

		// calcul_new_pos(cub3d->player, 1, 0);
		// check_col(cub3d->map, cub3d->player);
		// set_new_pos(cub3d->map, cub3d->player, cub3d->mlx_s);
	ft_move(cub3d);
	ft_rotate(cub3d);
	ft_calcul_render(cub3d);
}

int main(void)
{
    t_cub3d 	cub3d;

	if (initialization(&cub3d))
		return (free_all(&cub3d), EXIT_FAILURE);
	mlx_loop_hook(cub3d.mlx_s->mlx, ft_loop, &cub3d);
	mlx_key_hook(cub3d.mlx_s->mlx, key_hook, &cub3d);
	mlx_loop(cub3d.mlx_s->mlx);
	free_all(&cub3d);
	mlx_terminate(cub3d.mlx_s->mlx);
	return (EXIT_SUCCESS);
}

// big fat map
// texture bug