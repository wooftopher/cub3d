/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:06:48 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:58:58 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features_bonus.h"

void	fps_counter(void)
{
	static struct timeval	start_time = {0, 0};
	static uint32_t			frame_count = 0;
	struct timeval			current_time;
	uint32_t				elapsed_time;

	if (start_time.tv_sec == 0)
		gettimeofday(&start_time, NULL);
	gettimeofday(&current_time, NULL);
	elapsed_time = current_time.tv_sec - start_time.tv_sec;
	frame_count++;
	if (elapsed_time >= 1)
	{
		printf("\rFps:%d", (int)((double)frame_count - elapsed_time));
		fflush(stdout);
		frame_count = 0;
		start_time = current_time;
	}
}
