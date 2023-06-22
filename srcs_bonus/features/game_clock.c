/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:44 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/21 23:08:46 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"

static uint8_t	extract_digit(uint8_t number, uint8_t position)
{
	uint8_t	result;

	if (position == FIRST_DIGIT)
		result = number / 10;
	else
		result = number % 10;
	return (result);
}

static void	decrease_timer(t_cub3d *cub3d)
{
	if (cub3d->hud->duration != 0)
	{
		cub3d->hud->duration--;
		if (cub3d->hud->duration == 0)
			cub3d->player->speed = MAX_SPEED;
	}
}

static void	copy_over(t_cub3d *cub3d, uint8_t flag, uint8_t timer)
{
	if (flag == MS)
	{
		ft_memcpy(cub3d->timer->msr->pixels,
			cub3d->timer->digitaddresses[extract_digit(timer, 1)], 8448);
		ft_memcpy(cub3d->timer->msl->pixels,
			cub3d->timer->digitaddresses[extract_digit(timer, 0)], 8448);
	}
	else if (flag == SECONDS)
	{
		ft_memcpy(cub3d->timer->secondsl->pixels,
			cub3d->timer->digitaddresses[extract_digit(timer, 1)], 8448);
		ft_memcpy(cub3d->timer->secondsr->pixels,
			cub3d->timer->digitaddresses[extract_digit(timer, 0)], 8448);
	}
	else
	{
		ft_memcpy(cub3d->timer->minutesl->pixels,
			cub3d->timer->digitaddresses[extract_digit(timer, 1)], 8448);
		ft_memcpy(cub3d->timer->minutesr->pixels,
			cub3d->timer->digitaddresses[extract_digit(timer, 0)], 8448);
	}
}

inline static void	on_screen_timer(t_cub3d *cub3d, uint32_t elapsed_time)
{
	static uint8_t	ms = 0;
	static uint8_t	seconds = 0;
	static uint8_t	minutes = 0;

	ms += elapsed_time / 10;
	if (ms >= 100)
	{
		seconds += ms / 100;
		ms %= 100;
		if (seconds >= 60)
		{
			decrease_timer(cub3d);
			seconds %= 60;
			minutes++;
			copy_over(cub3d, MINUTES, minutes);
		}
		copy_over(cub3d, SECONDS, seconds);
	}
	copy_over(cub3d, MS, ms);
}

void	game_clock(t_cub3d *cub3d)
{
	static struct timeval	start_time = {0, 0};
	struct timeval			current_time;
	uint32_t				elapsed_time;

	if (start_time.tv_sec == 0)
		gettimeofday(&start_time, NULL);
	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - start_time.tv_sec) * 1000
		+ (current_time.tv_usec - start_time.tv_usec) / 1000;
	if (elapsed_time >= INTERVAL)
	{
		on_screen_timer(cub3d, elapsed_time);
		start_time = current_time;
	}
}
