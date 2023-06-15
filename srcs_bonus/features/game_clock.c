/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:44 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/15 05:33:31 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"
#include <time.h>

static void	decrease_timer(t_cub3d *cub3d)
{
	if (cub3d->hud->duration)
	{
		cub3d->hud->duration--;
		if (cub3d->hud->duration)
			cub3d->player->speed = 1;
	}
}

static void fps_counter(double elapsed_time)
{
    static uint32_t	frame_count = 0;

	frame_count++;
    if (elapsed_time >= INTERVAL)
    {
		printf("\rFps:%.0f", frame_count - elapsed_time);
		fflush(stdout);
		frame_count = 0;
    }
}

void	game_clock(t_cub3d *cub3d)
{
	static clock_t	start_time = 0;
	static clock_t	current_time = 0;
	double			elapsed_time;

	if (start_time == 0)
		start_time = clock();
	current_time = clock();
	elapsed_time = (current_time - start_time) / CLOCKS_PER_SEC;
	fps_counter(elapsed_time);
	if (elapsed_time >= INTERVAL)
	{
		decrease_timer(cub3d);
		start_time = current_time;
	}
}
