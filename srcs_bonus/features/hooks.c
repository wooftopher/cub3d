/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 05:02:51 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/21 11:59:10 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d;

	cub3d = param;
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
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		mushroom(cub3d);
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		end_screen(cub3d);
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
	{
		if (cub3d->fps_counter)
			cub3d->fps_counter = false;
		else
			cub3d->fps_counter = true;
	}
}

void mouse_position(double xpos, double ypos, void *params)
{
    t_cub3d *cub3d;

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

void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	// if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_REPEAT)
	// {
	// 	if (cub3d->player->speed < 7)
    //         cub3d->player->speed += 1;
    //     animation_racer(cub3d, FORWARD);
	// }
	if (button == MLX_MOUSE_BUTTON_MIDDLE && action == MLX_PRESS)
		mushroom(cub3d);
	// if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
}

void	init_hooks(t_cub3d *cub3d)
{
	mlx_key_hook(cub3d->mlx_s->mlx, key_hook, cub3d);
	mlx_cursor_hook(cub3d->mlx_s->mlx, mouse_position, cub3d);
	// mlx_mouse_hook(cub3d->mlx_s->mlx, mouse_hook, cub3d);
}
