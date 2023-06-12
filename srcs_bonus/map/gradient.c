/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 22:32:22 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/12 00:13:06 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/cub3d.h"

#define STEP 900 // remove later

inline static uint32_t	get_rgb(uint8_t red, uint8_t green,
	uint8_t blue, uint8_t alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

static void	t_rgb_constructor(uint32_t color, t_rgb *color_struct)
{
	color_struct->red = color >> 24;
	color_struct->green = (color >> 16) & 0xFF;
	color_struct->blue = (color >> 8) & 0xFF;
	color_struct->alpha = color & 0xFF;
}

static void	generate_gradient(t_rgb *gradient, t_rgb ceiling, t_rgb floor)
{
	uint16_t	index;

	index = 0;
	while (index < STEP)
	{
		gradient[index].red = ceiling.red
			+ (floor.red - ceiling.red) * index / STEP;
		gradient[index].green = ceiling.green
			+ (floor.green - ceiling.green) * index / STEP;
		gradient[index].blue = ceiling.blue
			+ (floor.blue - ceiling.blue) * index / STEP;
		gradient[index].alpha = ceiling.alpha
			+ (floor.alpha - ceiling.alpha) * index / STEP;
		index++;
	}
}

static void	fill_gradient(t_cub3d *cub3d, t_rgb *gradient)
{
	uint16_t	x;
	uint16_t	y;

	y = 0;
	while (y < STEP)
	{
		x = 0;
		while (x < 1900)
		{
			mlx_put_pixel(cub3d->mlx_s->img_back, x, y,
				get_rgb(gradient[y].red, gradient[y].green,
					gradient[y].blue, gradient[y].alpha));
			x++;
		}
		y++;
	}
}

int8_t	color_gradient(t_cub3d *cub3d)
{
	t_rgb	ceiling;
	t_rgb	floor;
	t_rgb	*gradient;
	int		ret;

	t_rgb_constructor(cub3d->map->ceiling_color, &ceiling);
	t_rgb_constructor(cub3d->map->floor_color, &floor);
	gradient = malloc(STEP * sizeof(t_rgb));
	if (!gradient)
		return (ft_putstr_fd("Alloc failure\n", 2), FAILURE);
	generate_gradient(gradient, ceiling, floor);
	cub3d->mlx_s->img_back = mlx_new_image(cub3d->mlx_s->mlx, 1900, 900);
	if (!cub3d->mlx_s->img_back)
		return (free (gradient), ft_putstr_fd("MLX failure\n", 2), FAILURE);
	fill_gradient(cub3d, gradient);
	free(gradient);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx,
			cub3d->mlx_s->img_back, 0, 0);
	if (ret == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
