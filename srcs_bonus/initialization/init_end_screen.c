/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_end_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 03:37:25 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/20 10:03:00 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static void	image_alpha(uint32_t height, uint32_t width, uint8_t *image)
{
	uint32_t	index;
	uint32_t	length;

	length = (width * height) * 4;
	index = 3;
	while (index < length)
	{
		image[index] = 0x00;
		index += 4;
	}
}

int8_t	init_end_screen(t_cub3d *cub3d)
{
	mlx_texture_t		*png;
	int32_t				ret;

	png = mlx_load_png("./img/end/end.png");
	if (!png)
		return (FAILURE);
	cub3d->end_screen = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->end_screen, 0, 0);
	if (ret == FAILURE)
		return (FAILURE);
	image_alpha(cub3d->end_screen->width,
		cub3d->end_screen->height, cub3d->end_screen->pixels);
	cub3d->end_screen->enabled = false;
	return (SUCCESS);
}
