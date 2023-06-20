/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/06/20 15:33:19 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_cub3d *cub3d;

	cub3d = param;
	if (cub3d->loop_status == 1)
	{
		ft_move(cub3d);
		ft_race(cub3d);
		ft_rotate(cub3d);
		ft_calcul_render(cub3d);
		mlx_set_mouse_pos(cub3d->mlx_s->mlx, 700, 450);
		game_clock(cub3d);
		if (cub3d->fps_counter)
			fps_counter();
	}
	else if (!cub3d->loop_status)
		countdown(cub3d);
	else
		set_end_screen_transition(cub3d);
}

int main(void)
{
    t_cub3d 	cub3d;

	if (initialization(&cub3d))
		return (free_all(&cub3d), EXIT_FAILURE);
	mlx_loop_hook(cub3d.mlx_s->mlx, ft_loop, &cub3d); // ADD HOOKS LATER TO INIT
	// system("afplay ./music/urss.mp3 &");
	mlx_loop(cub3d.mlx_s->mlx);
	mlx_terminate(cub3d.mlx_s->mlx);
	free_all(&cub3d);
	// system("killall afplay");
	return (EXIT_SUCCESS);
}
