/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countdown_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:42:11 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:59:03 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features_bonus.h"

static void	animation_countdown(t_cub3d *cub3d, uint8_t flag)
{
	if (flag == 0)
		ft_memcpy(cub3d->countdown->lakitu_0->pixels,
			cub3d->countdown->lakitu_1->pixels, 349440);
	if (flag == 1)
		ft_memcpy(cub3d->countdown->lakitu_0->pixels,
			cub3d->countdown->lakitu_2->pixels, 349440);
	if (flag == 2)
		ft_memcpy(cub3d->countdown->lakitu_0->pixels,
			cub3d->countdown->lakitu_3->pixels, 349440);
}

void	smooth_lakitu(t_cub3d *cub3d)
{
	static int16_t	count = 255;
	uint32_t		index;

	if (count <= 0)
		return ;
	index = 3;
	count -= 5;
	while (index <= 349440)
	{
		if (cub3d->countdown->lakitu_0->pixels[index] != 0)
			cub3d->countdown->lakitu_0->pixels[index] = count;
		index += 4;
	}
}

void	norm_countdown(t_cub3d *cub3d)
{
	if (cub3d->countdown->countdown == 0)
		ft_calcul_render(cub3d);
	else if (cub3d->countdown->countdown == 1)
		animation_countdown(cub3d, 0);
	else if (cub3d->countdown->countdown == 2)
	{
		system("afplay ./audio/sound/beep0.wav");
		animation_countdown(cub3d, 1);
	}
	else if (cub3d->countdown->countdown == 3)
	{
		animation_countdown(cub3d, 2);
		system("afplay ./audio/sound/beep1.mp3");
	}
	cub3d->countdown->countdown++;
}

void	countdown(t_cub3d *cub3d)
{
	if (cub3d->countdown->countdown < 4)
		norm_countdown(cub3d);
	else
	{
		system("afplay ./audio/sound/beep2.wav &");
		cub3d->loop_status = 1;
		system(cub3d->map->music_path);
		mlx_set_mouse_pos(cub3d->mlx_s->mlx, 700, 450);
		mlx_cursor_hook(cub3d->mlx_s->mlx, mouse_position, cub3d);
	}
}
