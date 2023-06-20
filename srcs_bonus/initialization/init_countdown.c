/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_countdown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:44:43 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/20 15:32:09 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

int8_t	init_lakitu2(t_cub3d *cub3d)
{
	mlx_texture_t	*png;
	mlx_image_t		*image;

	png = mlx_load_png("./img/lakitu/lakitu2.png");
	if (!png)
		return (FAILURE);
	cub3d->countdown->lakitu_2 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/lakitu/lakitu3.png");
	if (!png)
		return (FAILURE);
	cub3d->countdown->lakitu_3 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	return (SUCCESS);
}

int8_t	init_lakitu1(t_cub3d *cub3d)
{
	mlx_texture_t	*png;
	mlx_image_t		*image;

	png = mlx_load_png("./img/lakitu/lakitu0.png");
	if (!png)
		return (FAILURE);
	cub3d->countdown->lakitu_0 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/lakitu/lakitu1.png");
	if (!png)
		return (FAILURE);
	cub3d->countdown->lakitu_1 = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	return (SUCCESS);
}

int8_t	init_countdown(t_cub3d *cub3d)
{
	int32_t	ret;

	if (init_lakitu1(cub3d))
		return (FAILURE);
	if (init_lakitu2(cub3d))
		return (FAILURE);
	//ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->countdown->lakitu_0, 250, 250);
	if (ret == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
