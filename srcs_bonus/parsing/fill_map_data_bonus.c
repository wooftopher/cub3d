/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:33:01 by ddemers           #+#    #+#             */
/*   Updated: 2023/05/29 15:33:01 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

static void	allocate_wall_ptr(t_map *map)
{
	map->wall_px = malloc(sizeof(float) * map->wall_count);
	if (!map->wall_px)
		return (set_map_errno(map, ALLOCF));
	map->wall_py = malloc(sizeof(float) * map->wall_count);
	if (!map->wall_px)
		return (set_map_errno(map, ALLOCF));
}

static void	check_dimension(t_map *map)
{
	if (map->width > MAX_WIDTH)
		return (set_map_errno(map, WIDOVE));
	if (map->width < MIN_WIDTH)
		return (set_map_errno(map, WIDLOW));
	if (map->height > MAX_HEIGHT)
		return (set_map_errno(map, HEIOVE));
	if (map->height < MIN_HEIGHT)
		return (set_map_errno(map, HEILOW));
}

static int	fill_dimension(t_map *map)
{
	uint32_t	width;
	uint32_t	height;
	uint16_t	wall_count;

	width = 0;
	height = 0;
	wall_count = 0;
	while (map->map[height])
	{
		width = 0;
		while (map->map[height][width])
		{
			if (map->map[height][width] == '1')
				wall_count++;
			width++;
		}
		height++;
	}
	map->width = width;
	map->height = height;
	map->wall_count = wall_count;
	return (SUCCESS);
}

void	fill_map_data(t_map *map)
{
	if (map->map_errno)
		return ;
	fill_dimension(map);
	check_dimension(map);
	if (map->map_errno)
		return ;
	allocate_wall_ptr(map);
	if (map->map_errno)
		return ;
}
