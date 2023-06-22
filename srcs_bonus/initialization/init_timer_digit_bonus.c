/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_timer_digit_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:29:45 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:58:21 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization_bonus.h"

int8_t	load_digit3(t_cub3d *cub3d)
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

int8_t	load_digit2(t_cub3d *cub3d)
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

int8_t	load_digit1(t_cub3d *cub3d)
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
