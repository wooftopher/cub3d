/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:27:21 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/21 16:09:06 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

int8_t	init_end(t_cub3d *cub3d)
{
	cub3d->mlx_s->finish = mlx_load_png("./img/racer/forward.png");
	if (!cub3d->mlx_s->finish)
		return (FAILURE);
	cub3d->map->finish = fill_int_array(cub3d->mlx_s->finish);
	if (!cub3d->map->finish)
		return (FAILURE);
	return (SUCCESS);
}
