/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 03:50:30 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:59:01 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features_bonus.h"

inline static void	smooth(uint32_t height, uint32_t width,
	uint8_t *image, uint8_t value)
{
	uint32_t	index;
	uint32_t	length;

	length = (width * height) * 4;
	index = 3;
	while (index < length)
	{
		image[index] = value;
		index += 4;
	}
}

void	set_end_screen_transition(t_cub3d *cub3d)
{
	static uint8_t	index = 0;

	if (index < 255)
	{
		index += 5;
		smooth(cub3d->end_screen->height, cub3d->end_screen->width,
			cub3d->end_screen->pixels, index);
	}
}

void	end_screen(t_cub3d *cub3d)
{
	cub3d->end_screen->enabled = true;
	cub3d->loop_status = 2;
	cub3d->hud->mush3->enabled = false;
	cub3d->hud->mush2->enabled = false;
	cub3d->hud->mush1->enabled = false;
	cub3d->hud->empty->enabled = false;
	cub3d->hud->tig->enabled = false;
	system("killall afplay && afplay ./audio/music/end.mp3 &");
}
