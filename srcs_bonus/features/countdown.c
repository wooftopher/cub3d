/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countdown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:42:11 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/20 15:31:15 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"

// static void	animation_countdown(t_cub3d *cub3d, uint8_t flag)
// {
// 	if (flag == 0)
// 	ft_memcpy(cub3d->countdown->lakitu_0->pixels,
// 			cub3d->timecountr->digitAddresses[extract_digit(timer, 1)], 8448);
// }

void	countdown(t_cub3d *cub3d)
{
	// static uint8_t countdown = 0;

	// if (countdown == 0)
	// 	countdown++;
	// else if (countdown == 1)
	// {
	// 	countdown++;
	// 	system("afplay ./music/beep1.mp3 &");
	// }
	// else if (countdown < 5)
	// {
	// 	usleep(10000);
	// 	countdown++;
	// }
	// else
		cub3d->loop_status = 1;
}