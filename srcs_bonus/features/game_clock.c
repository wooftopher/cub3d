/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:44 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/16 21:35:03 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"
#include <sys/time.h>

static uint8_t	*get_number(t_cub3d *cub3d, uint8_t digit)
{
	if (digit == 0)
		return (cub3d->timer->zero->pixels);
	else if (digit == 1)
		return (cub3d->timer->one->pixels);
	else if (digit == 2)
		return (cub3d->timer->two->pixels);
	else if (digit == 3)
		return (cub3d->timer->three->pixels);
	else if (digit == 4)
		return (cub3d->timer->four->pixels);
	else if (digit == 5)
		return (cub3d->timer->five->pixels);
	else if (digit == 6)
		return (cub3d->timer->six->pixels);
	else if (digit == 7)
		return (cub3d->timer->seven->pixels);
	else if (digit == 8)
		return (cub3d->timer->eight->pixels);
	else
		return (cub3d->timer->nine->pixels);
}

static uint8_t	extract_digit(uint8_t number, uint8_t position)
{
	uint8_t	result;

	if (position == FIRST_DIGIT)
		result = number / 10;
	else
		result = number % 10;
	return (result);
}

static void	on_screen_timer(t_cub3d *cub3d)
{
	static uint8_t	seconds = 0;
	static uint8_t	minutes = 0;

	seconds++;
	if (seconds == 60)
	{
		seconds = 0;
		minutes++;
	}
	ft_memcpy(cub3d->timer->secondsl->pixels, get_number(cub3d, extract_digit(seconds, FIRST_DIGIT)), (33 * 64) * 4);
	ft_memcpy(cub3d->timer->secondsr->pixels, get_number(cub3d, extract_digit(seconds, 0)), (33 * 64) * 4);
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
