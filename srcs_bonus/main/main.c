/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/06/16 22:58:35 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
}

void	ft_race(t_cub3d *cub3d)
{
	if (cub3d->player->speed > 0)
	{
		cub3d->player->speed -= 0.1;
		if (cub3d->player->speed < 0)
			cub3d->player->speed = 0;
	}
	calcul_new_pos(cub3d->player, 1, 0);
	check_col(cub3d->map, cub3d->player);
	set_new_pos(cub3d->map, cub3d->player, cub3d->mlx_s);
}

void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	ft_move(cub3d);
	ft_race(cub3d);
	ft_rotate(cub3d);
	ft_calcul_render(cub3d);
	mlx_set_mouse_pos(cub3d->mlx_s->mlx, 700, 450);
	game_clock(cub3d);
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
        cub3d->player->angle += (700 - xpos) * 0.25;;
	}
}

void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	return ;
}


int main(void)
{
    t_cub3d 	cub3d;

	if (initialization(&cub3d))
		return (free_all(&cub3d), EXIT_FAILURE);
	mlx_set_cursor_mode(cub3d.mlx_s->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(cub3d.mlx_s->mlx, ft_loop, &cub3d); // ADD HOOKS LATER TO INIT
	mlx_key_hook(cub3d.mlx_s->mlx, key_hook, &cub3d);
	mlx_cursor_hook(cub3d.mlx_s->mlx, &mouse_position, &cub3d);
	mlx_mouse_hook(cub3d.mlx_s->mlx, &mouse_hook, &cub3d);
	mlx_loop(cub3d.mlx_s->mlx);
	mlx_terminate(cub3d.mlx_s->mlx);
	free_all(&cub3d);
	return (EXIT_SUCCESS);
}

// big fat map
// texture bug