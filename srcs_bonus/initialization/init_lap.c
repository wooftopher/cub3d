/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:49:49 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 00:03:17 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

int8_t	init_lap(t_cub3d *cub3d)
{
	mlx_texture_t	*png;
	int32_t			ret;

	png = mlx_load_png("./img/lap/1.png");
	if (!png)
		return (mlx_delete_texture(png), FAILURE);
	cub3d->hud->lap1 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/lap/2.png");
	if (!png)
		return (mlx_delete_texture(png), FAILURE);
	cub3d->hud->lap2 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->hud->lap1, 250, 20);
	if (ret == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
