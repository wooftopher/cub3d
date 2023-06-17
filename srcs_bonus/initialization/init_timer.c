/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_timer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:14:06 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/17 12:40:59 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

static int8_t	to_window_timer(t_cub3d *cub3d)
{
	int32_t	ret;

	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->timer->msl, 1285, 20);
	if (ret == FAILURE)
		return (FAILURE);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->timer->msr, 1245, 20);
	if (ret == FAILURE)
		return (FAILURE);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->timer->secondsl,
			1145, 20);
	if (ret == FAILURE)
		return (FAILURE);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->timer->secondsr,
			1185, 20);
	if (ret == FAILURE)
		return (FAILURE);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->timer->minutesl,
			1045, 20);
	if (ret == FAILURE)
		return (FAILURE);
	ret = mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->timer->minutesr,
			1085, 20);
	if (ret == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static void	assign_array(t_cub3d *cub3d)
{
	cub3d->timer->digitAddresses[0] = cub3d->timer->zero->pixels;
	cub3d->timer->digitAddresses[1] = cub3d->timer->one->pixels;
	cub3d->timer->digitAddresses[2] = cub3d->timer->two->pixels;
	cub3d->timer->digitAddresses[3] = cub3d->timer->three->pixels;
	cub3d->timer->digitAddresses[4] = cub3d->timer->four->pixels;
	cub3d->timer->digitAddresses[5] = cub3d->timer->five->pixels;
	cub3d->timer->digitAddresses[6] = cub3d->timer->six->pixels;
	cub3d->timer->digitAddresses[7] = cub3d->timer->seven->pixels;
	cub3d->timer->digitAddresses[8] = cub3d->timer->eight->pixels;
	cub3d->timer->digitAddresses[9] = cub3d->timer->nine->pixels;
}

static int8_t	set_timer_image(t_cub3d *cub3d)
{
	cub3d->timer->secondsl = mlx_new_image(cub3d->mlx_s->mlx, 33, 64);
	if (!cub3d->timer->secondsl)
		return (FAILURE);
	cub3d->timer->secondsr = mlx_new_image(cub3d->mlx_s->mlx, 33, 64);
	if (!cub3d->timer->secondsr)
		return (FAILURE);
	cub3d->timer->minutesl = mlx_new_image(cub3d->mlx_s->mlx, 33, 64);
	if (!cub3d->timer->minutesl)
		return (FAILURE);
	cub3d->timer->minutesr = mlx_new_image(cub3d->mlx_s->mlx, 33, 64);
	if (!cub3d->timer->minutesr)
		return (FAILURE);
	cub3d->timer->msr = mlx_new_image(cub3d->mlx_s->mlx, 33, 64);
	if (!cub3d->timer->msr)
		return (FAILURE);
	cub3d->timer->msl = mlx_new_image(cub3d->mlx_s->mlx, 33, 64);
	if (!cub3d->timer->msl)
		return (FAILURE);
	ft_memcpy(cub3d->timer->secondsl->pixels, cub3d->timer->zero->pixels, MATH);
	ft_memcpy(cub3d->timer->secondsr->pixels, cub3d->timer->zero->pixels, MATH);
	ft_memcpy(cub3d->timer->minutesr->pixels, cub3d->timer->zero->pixels, MATH);
	ft_memcpy(cub3d->timer->minutesl->pixels, cub3d->timer->zero->pixels, MATH);
	ft_memcpy(cub3d->timer->msl->pixels, cub3d->timer->zero->pixels, MATH);
	ft_memcpy(cub3d->timer->msr->pixels, cub3d->timer->zero->pixels, MATH);
	return (SUCCESS);
}

static int8_t	load_timer_text(t_cub3d *cub3d)
{
	mlx_texture_t	*png;

	png = mlx_load_png("./img/timer/timedd.png");
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
	if (set_timer_image(cub3d))
		return (FAILURE);
	if (to_window_timer(cub3d))
		return (FAILURE);
	assign_array(cub3d);
	return (SUCCESS);
}
