/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mushroom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 05:04:38 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/21 14:26:39 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"

static void	play_sound_effect(void)
{
	int	random;

	random = rand() % 3;
	if (random == 1)
		system("afplay ./audio/sound/r1.wav &");
	else if (random == 2)
		system("afplay ./audio/sound/r2.wav &");
	else if (random == 3)
		system("afplay ./audio/sound/r3.wav &");
	else
		system("afplay ./audio/sound/r4.wav &");
}

static void	update_hud(t_cub3d *cub3d, mlx_image_t *to_delete,
		mlx_image_t *new_image)
{
	int32_t	ret;

	mlx_delete_image(cub3d->mlx_s->mlx, to_delete);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, new_image, 0, 0);
	if (ret == FAILURE)
	{
		write(STDERR_FILENO, "Something bad happened image to window\n", 40);
		mlx_close_window(cub3d->mlx_s->mlx);
	}
}

static void	use_mushroom(t_cub3d *cub3d)
{
	if (cub3d->hud->counter == 0)
		update_hud(cub3d, cub3d->hud->mush3, cub3d->hud->mush2);
	else if (cub3d->hud->counter == 1)
		update_hud(cub3d, cub3d->hud->mush2, cub3d->hud->mush1);
	else if (cub3d->hud->counter == 2)
		update_hud(cub3d, cub3d->hud->mush1, cub3d->hud->empty);
	else if (cub3d->hud->counter == 3)
	{
		update_hud(cub3d, cub3d->hud->empty, cub3d->hud->tig);
		cub3d->hud->counter++;
		return ;
	}
	cub3d->hud->counter++;
	cub3d->hud->duration = MUSH_TIMER;
	cub3d->player->speed = SPEED_BOOST;
	play_sound_effect();
}

void	mushroom(t_cub3d *cub3d)
{
	if (cub3d->hud->counter <= 3)
		use_mushroom(cub3d);
	else
		return ;
}
