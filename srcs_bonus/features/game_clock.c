/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:44 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/16 00:49:58 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"
#include <sys/time.h>

static char	*timer(uint8_t seconds, uint8_t minutes)
{
	char	*minutes_str;
	char	*seconds_str;
	char	*result;

	minutes_str = ft_itoa(minutes);
	if (!minutes_str)
		return (NULL);
	seconds_str = ft_itoa(seconds);
	if (!seconds_str)
		return (NULL);
	result = ft_strjoin(minutes_str, seconds_str);
	free(minutes_str);
	free(seconds_str);
	if (!result)
		return (NULL);
	return (result);
}

static void	on_screen_timer(t_cub3d *cub3d)
{
	static uint8_t	seconds = 0;
	static uint8_t	minutes = 0;
	static bool		first = false;
	char			*time;

	seconds++;
	if (seconds == 60)
	{
		seconds = 0;
		minutes++;
	}
	time = timer(seconds, minutes);
	if (first)
		mlx_delete_image(cub3d->mlx_s->mlx, cub3d->timer);
	else
		first = true;
	cub3d->timer = mlx_put_string(cub3d->mlx_s->mlx, time, 1000, 500);
	mlx_resize_image(cub3d->timer, 35, 35);
	free(time);
}

static void	decrease_timer(t_cub3d *cub3d)
{
	if (cub3d->hud->duration != 0)
	{
		cub3d->hud->duration--;
		if (cub3d->hud->duration == 0)
			cub3d->player->speed = 1;
	}
}

void	game_clock(t_cub3d *cub3d)
{
	static struct timeval	start_time = {0, 0};
	struct timeval			current_time;
	static uint32_t			frame_count = 0;
	uint32_t				elapsed_time;

	if (start_time.tv_sec == 0)
		gettimeofday(&start_time, NULL);
	gettimeofday(&current_time, NULL);
	elapsed_time = current_time.tv_sec - start_time.tv_sec;
	frame_count++;
	if (elapsed_time >= INTERVAL)
	{
		on_screen_timer(cub3d);
		decrease_timer(cub3d);
		printf("\rFps:%d", (int)((double)frame_count / elapsed_time));
		fflush(stdout);
		frame_count = 0;
		start_time = current_time;
	}
}
