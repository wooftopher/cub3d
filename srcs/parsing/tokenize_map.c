/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:16:51 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/04 18:16:51 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"
#include <limits.h>

inline static bool	is_starting_position(const char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

inline static bool	is_map_character(const char c)
{
	if (c == '1' || c == '0' || is_starting_position(c))
		return (true);
	return (false);
}

static uint32_t	get_end_index(const char *map, t_map *maps, uint32_t index)
{
	uint32_t	end_index;
	bool		is_map;

	is_map = true;
	while (map[index] && map[index] != '\n')
		index++;
	end_index = index;
	while (map[index])
	{
		if (index == UINT_MAX)
			return (set_map_errno(maps, INTOVE), 0);
		if (is_map == true)
			end_index = index;
		is_map = false;
		index++;
		while (map[index] && map[index] != '\n')
		{
			if (is_map_character(map[index++]))
				is_map = true;
		}
	}
	if (is_map == true)
		return (index);
	return (end_index);
}

static char	*get_starting_position(char *map, t_map *maps)
{
	uint32_t	index;
	uint32_t	begin_index;

	index = 0;
	while (map[index])
	{
		if (index == UINT_MAX)
			return (set_map_errno(maps, INTOVE), NULL);
		begin_index = index;
		while (map[index] && map[index] != '\n' && ft_isspace(map[index]))
			index++;
		if (map[index] == '\n')
		{
			index++;
			continue ;
		}
		if (map[index])
			break ;
	}
	if (!map[index])
		return (set_map_errno(maps, MAPEMT), NULL);
	return (map + begin_index);
}

char	*tokenize_map(char *token, t_map *map)
{
	char		*map_token;
	uint32_t	end_index;
	uint32_t	index;

	index = 0;
	if (!token)
		return (NULL);
	map_token = get_starting_position(token, map);
	if (!map_token)
		return (set_map_errno(map, MAPEMT), NULL);
	end_index = get_end_index(map_token, map, index);
	map_token[end_index] = '\0';
	return (map_token);
}
