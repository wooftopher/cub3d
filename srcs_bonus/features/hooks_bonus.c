/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 05:02:51 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:58:52 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features_bonus.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub3d->mlx_s->mlx);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		mushroom(cub3d);
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
	{
		if (cub3d->fps_counter)
			cub3d->fps_counter = false;
		else
			cub3d->fps_counter = true;
	}
}

void	mouse_position(double xpos, double ypos, void *params)
{
	t_cub3d	*cub3d;

	(void)ypos;
	cub3d = params;
	if (xpos > 700)
	{
		animation_racer(cub3d, RIGHT);
		cub3d->player->angle -= (xpos - 700) * 0.25;
	}
	else
	{
		animation_racer(cub3d, LEFT);
		cub3d->player->angle += (700 - xpos) * 0.25;
	}
}

void	init_hooks(t_cub3d *cub3d)
{
	mlx_key_hook(cub3d->mlx_s->mlx, key_hook, cub3d);
}
