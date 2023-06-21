/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcul_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:44:01 by cperron           #+#    #+#             */
/*   Updated: 2023/06/21 15:53:38 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

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
