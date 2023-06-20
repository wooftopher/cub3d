/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:44 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/20 08:10:38 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"
#include <sys/time.h>

static uint8_t	extract_digit(uint8_t number, uint8_t position)
{
	uint8_t	result;

	if (position == FIRST_DIGIT)
		result = number / 10;
	else
		result = number % 10;
	return (result);
}

// static void	on_screen_timer(t_cub3d *cub3d)
// {
// 	static uint8_t	ms = 0;
// 	static uint8_t	seconds = 0;
// 	static uint8_t	minutes = 0;

// 	ms++;
// 	if (ms == 60)
// 	{
// 		seconds++;
// 		ms = 0;
// 		if (seconds == 60)
// 		{
// 			seconds = 0;
// 			minutes++;
// 			ft_memcpy(cub3d->timer->minutesl->pixels, get_number(cub3d, extract_digit(minutes, FIRST_DIGIT)), 8448);
// 			ft_memcpy(cub3d->timer->minutesr->pixels, get_number(cub3d, extract_digit(minutes, 0)), 8448);
// 		}
// 		ft_memcpy(cub3d->timer->secondsl->pixels, get_number(cub3d, extract_digit(seconds, FIRST_DIGIT)), 8448);
// 		ft_memcpy(cub3d->timer->secondsr->pixels, get_number(cub3d, extract_digit(seconds, 0)), 8448);
// 	}
// 	ft_memcpy(cub3d->timer->msr->pixels, get_number(cub3d, extract_digit(ms, FIRST_DIGIT)), 8448);
// 	ft_memcpy(cub3d->timer->msl->pixels, get_number(cub3d, extract_digit(ms, 0)), 8448);
// }

static void	on_screen_timer(t_cub3d *cub3d)
{
	static uint8_t	ms = 0;
	static uint8_t	seconds = 0;
	static uint8_t	minutes = 0;

	ms++;
	if (ms == 60)
	{
		seconds++;
		ms = 0;
		if (seconds == 60)
		{
			seconds = 0;
			minutes++;
			ft_memcpy(cub3d->timer->minutesl->pixels, cub3d->timer->digitAddresses[extract_digit(minutes, FIRST_DIGIT)], 8448);
			ft_memcpy(cub3d->timer->minutesr->pixels, cub3d->timer->digitAddresses[extract_digit(minutes, 0)], 8448);
		}
		ft_memcpy(cub3d->timer->secondsl->pixels, cub3d->timer->digitAddresses[extract_digit(seconds, FIRST_DIGIT)], 8448);
		ft_memcpy(cub3d->timer->secondsr->pixels, cub3d->timer->digitAddresses[extract_digit(seconds, 0)], 8448);
	}
	ft_memcpy(cub3d->timer->msr->pixels, cub3d->timer->digitAddresses[extract_digit(ms, FIRST_DIGIT)], 8448);
	ft_memcpy(cub3d->timer->msl->pixels, cub3d->timer->digitAddresses[extract_digit(ms, 0)], 8448);
}

static void	decrease_timer(t_cub3d *cub3d)
{
	if (cub3d->hud->duration != 0)
	{
		cub3d->hud->duration--;
		if (cub3d->hud->duration == 0)
			cub3d->player->speed = 10;
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
	elapsed_time = current_time.tv_usec - start_time.tv_usec;
	frame_count++;
	if (elapsed_time >= INTERVAL)
	{
		on_screen_timer(cub3d);
		decrease_timer(cub3d);
		// printf("\rFps:%d", (int)((double)frame_count / elapsed_time));
		// fflush(stdout);
		frame_count = 0;
		start_time = current_time;
	}
}
