/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:27:21 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/21 15:51:14 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

int8_t	init_end(t_cub3d *cub3d)
{
	mlx_texture_t	*png;

	png = mlx_load_png("./img/racer/forward.png");
	if (!png)
		return (FAILURE);
	cub3d->map->finish = fill_int_array(png);
	mlx_delete_texture(png);
	if (!cub3d->map->finish)
		return (FAILURE);
	return (SUCCESS);
}
