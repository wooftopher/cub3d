/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:52:37 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/14 14:22:49 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static int8_t	init_player(t_cub3d *cub3d)
{
	mlx_texture_t	*png;
	mlx_image_t		*image;

	png = mlx_load_png("./img/racer/Mario.png");
	image = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_image_to_window(cub3d->mlx_s->mlx, image, 615, 650);
	mlx_delete_texture(png);
}

static int8_t	init_hud(t_cub3d *cub3d)
{
	mlx_texture_t	*png;
	mlx_image_t		*image;

	png = mlx_load_png("./img/box/3mush.png");
	if (!png)
		return (mlx_delete_texture(png), FAILURE);
	cub3d->hud->mush3 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	// png = mlx_load_png("./img/box/2mush.png");
	// if (!png)
	// 	return (mlx_delete_texture(png), FAILURE);
	// mlx_delete_texture(png);
	// cub3d->hud->mush2 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	// png = mlx_load_png("./img/box/1mush.png");
	// if (!png)
	// 	return (mlx_delete_texture(png), FAILURE);
	// cub3d->hud->mush1 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	return (SUCCESS);
}

int8_t	init_hud_player(t_cub3d *cub3d)
{
	if (init_hud(cub3d))
		return (FAILURE);
	if (mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->hud->mush3, 0, 0) == FAILURE)
		return (FAILURE);
	if (init_player(cub3d))
		return (FAILURE);
	return (SUCCESS);
}