/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:52:37 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/15 16:52:12 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static int8_t	init_player2(t_cub3d *cub3d)
{
	int8_t	ret;

	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->racer->forward,
			615, 650);
	if (ret == FAILURE)
		return (print_error("Forward window\n"), FAILURE);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->racer->left, 615, 650);
	if (ret == FAILURE)
		return (print_error("left window\n"), FAILURE);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->racer->right, 615, 650);
	if (ret == FAILURE)
		return (print_error("right window\n"), FAILURE);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->racer->back, 615, 650);
	if (ret == FAILURE)
		return (print_error("back window\n"), FAILURE);
	cub3d->racer->left->enabled = false;
	cub3d->racer->right->enabled = false;
	cub3d->racer->back->enabled = false;
	return (SUCCESS);
}

static int8_t	init_player(t_cub3d *cub3d)
{
	mlx_texture_t	*png;
	mlx_image_t		*image;

	png = mlx_load_png("./img/racer/forward.png");
	if (!png)
		return (FAILURE);
	cub3d->racer->forward = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/racer/left.png");
	if (!png)
		return (FAILURE);
	cub3d->racer->left = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/racer/right.png");
	if (!png)
		return (FAILURE);
	cub3d->racer->right = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/racer/back.png");
	if (!png)
		return (FAILURE);
	cub3d->racer->back = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	return (SUCCESS);
}

static int8_t	init_hud2(t_cub3d *cub3d)
{
	mlx_texture_t	*png;
	mlx_image_t		*image;

	png = mlx_load_png("./img/box/empty.png");
	if (!png)
		return (FAILURE);
	cub3d->hud->empty = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/box/TIG.png");
	if (!png)
		return (FAILURE);
	cub3d->hud->tig = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	if (!cub3d->hud->empty || !cub3d->hud->tig)
		return (FAILURE);
	if (mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->hud->mush3, 0, 0)
		== FAILURE)
		return (FAILURE);
	return (SUCCESS);
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
	png = mlx_load_png("./img/box/2mush.png");
	if (!png)
		return (mlx_delete_texture(png), FAILURE);
	cub3d->hud->mush2 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/box/1mush.png");
	if (!png)
		return (mlx_delete_texture(png), FAILURE);
	cub3d->hud->mush1 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	if (!cub3d->hud->mush3 || !cub3d->hud->mush2 || !cub3d->hud->mush1)
		return (FAILURE);
	return (SUCCESS);
}

int8_t	init_hud_player(t_cub3d *cub3d)
{
	if (init_hud(cub3d))
		return (print_error("Hud texture\n"), FAILURE);
	if (init_hud2(cub3d))
		return (print_error("Hud texture\n"), FAILURE);
	if (init_player(cub3d))
		return (print_error("Racer texture\n"), FAILURE);
	if (init_player2(cub3d))
		return (FAILURE);
	return (SUCCESS);
}
