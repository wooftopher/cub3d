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

#include "map_processor.h"

static bool	replace_map_character_check(const char c)
{
	if (c == ' ' || c == '#')
		return (true);
	return (false);
}

void	modify_map(t_map *map)
{
	uint32_t	map_index;
	uint32_t	array_index;

	map_index = 0;
	while (map->map[map_index])
	{
		array_index = 0;
		while (map->map[map_index][array_index])
		{
			if (replace_map_character_check(map->map[map_index][array_index]))
				map->map[map_index][array_index] = '0';
			array_index++;
		}
		map_index++;
	}
}
