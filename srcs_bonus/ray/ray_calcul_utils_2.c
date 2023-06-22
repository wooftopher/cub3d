/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:44:01 by cperron           #+#    #+#             */
/*   Updated: 2023/06/22 00:42:27 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"
#include "../features/features.h"

void	spaggetji(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->player->d_y < 0)
		y = (cub3d->player->pos_y - 65 + cub3d->player->d_y) / 100;
	else
		y = (cub3d->player->pos_y + 65 + cub3d->player->d_y) / 100;
	x = cub3d->player->pos_x / 100;
	if (cub3d->map->map[y][x] == '1')
		cub3d->player->col_y = 1;
	else if (cub3d->map->map[y][x] == '2'
		&& cub3d->player->laps < cub3d->player->checkpoint)
	{
		if (cub3d->player->laps < 1)
			lap(cub3d);
		else
			end_screen(cub3d);
	}
	else if (cub3d->map->map[y][x] == 'C'
		&& cub3d->player->checkpoint == cub3d->player->laps)
	{
		cub3d->player->checkpoint++;
		return ;
	}
}

int	check_feature_x(t_map *map, t_ray *ray, int x, int y)
{
	if (map->map[y][x] == '1' || map->map[y][x] == '3')
	{
		ray->text_x = x;
		return (1);
	}
	else
	{
		ray->text_x = x;
		return (2);
	}
}

int	check_feature_y(t_map *map, t_ray *ray, int x, int y)
{
	if (map->map[y][x] == '1' || map->map[y][x] == '3')
	{
		ray->text_y = y;
		return (1);
	}
	else
	{
		ray->text_y = y;
		return (2);
	}
}
