/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lap.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:18:22 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 00:32:16 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features.h"

void	lap(t_cub3d *cub3d)
{
	cub3d->player->laps++;
	ft_memcpy(cub3d->hud->lap1->pixels,
		cub3d->hud->lap2->pixels,
		(cub3d->hud->lap1->width * cub3d->hud->lap1->height) * 4);
	system("afplay ./audio/sound/lap.mp3 &");
}
