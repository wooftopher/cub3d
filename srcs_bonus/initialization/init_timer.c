/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_timer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:14:06 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/16 20:19:46 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static int8_t	load_digit3(t_cub3d *cub3d)
{
	mlx_texture_t	*png;

	png = mlx_load_png("./img/timer/8.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->eight = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/timer/9.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->nine = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	return (SUCCESS);
}

static int8_t	load_digit2(t_cub3d *cub3d)
{
	mlx_texture_t	*png;

	png = mlx_load_png("./img/timer/4.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->four = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/timer/5.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->five = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/timer/6.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->six = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/timer/7.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->seven = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	return (SUCCESS);
}

static int8_t	load_digit1(t_cub3d *cub3d)
{
	mlx_texture_t	*png;

	png = mlx_load_png("./img/timer/0.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->zero = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/timer/1.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->one = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/timer/2.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->two = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	png = mlx_load_png("./img/timer/3.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->three = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	return (SUCCESS);
}

static int8_t	load_timer_text(t_cub3d *cub3d)
{
	mlx_texture_t	*png;

	png = mlx_load_png("./img/timer/small_timer.png");
	if (!png)
		return (FAILURE);
	cub3d->timer->timer_text = mlx_texture_to_image(cub3d->mlx_s->mlx, png);
	mlx_delete_texture(png);
	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->timer->timer_text, 900, 20);
	return (SUCCESS);
}


int8_t	init_timer(t_cub3d *cub3d)
{
	if (load_timer_text(cub3d))
		return (FAILURE);
	if (load_digit1(cub3d))
		return (FAILURE);
	if (load_digit2(cub3d))
		return (FAILURE);
	if (load_digit3(cub3d))
		return (FAILURE);
	cub3d->timer->secondsl = mlx_new_image(cub3d->mlx_s->mlx, 33, 64);
	cub3d->timer->secondsr = mlx_new_image(cub3d->mlx_s->mlx, 33, 64);
	ft_memcpy(cub3d->timer->secondsl->pixels, cub3d->timer->zero->pixels, (33 * 64) * 4);
	ft_memcpy(cub3d->timer->secondsr->pixels, cub3d->timer->zero->pixels, (33 * 64) * 4);
	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->timer->secondsl, 500, 500);
	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->timer->secondsr, 600, 500);
	return (SUCCESS);
}
