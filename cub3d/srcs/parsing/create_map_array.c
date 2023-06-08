/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:10:59 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/07 16:13:49 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

static size_t	get_true_length(const char *map)
{
	size_t	length;

	length = 0;
	while (map[length])
	{
		if (map[length] == '\n')
			break ;
		length++;
	}
	return (length);
}

static void	fill_map_array(char ***map_array, const char *map,
				uint32_t max_length, t_map *map_struct)
{
	uint32_t	array_index;
	uint32_t	map_index;
	size_t		length;

	map_index = 0;
	array_index = 0;
	while (map[map_index])
	{
		length = get_true_length(map + map_index);
		(*map_array)[array_index] = substr_cube(map,
				map_index, length, max_length);
		if (!(*map_array)[array_index])
			return (set_map_errno(map_struct, ALLOCF));
		map_index += length;
		if (map[map_index] == '\n')
			map_index++;
		array_index++;
	}
}

static uint32_t	count_number_of_array(const char *map, t_map *maps)
{
	uint32_t	nbr_of_array;
	uint32_t	index;

	index = 0;
	nbr_of_array = 0;
	while (map[index])
	{
		if (map[index] == '\n')
			nbr_of_array++;
		index++;
	}
	if (nbr_of_array + 1 > MAX_HEIGHT)
		return (set_map_errno(maps, HEIOVE), 0);
	return (nbr_of_array + 2);
}

static uint32_t	get_max_length(const char *map, t_map *maps)
{
	uint32_t	max_length;
	uint32_t	index;
	uint32_t	current_length;

	index = 0;
	max_length = 0;
	while (map[index])
	{
		current_length = 0;
		while (map[index] && map[index] != '\n')
		{
			index++;
			current_length++;
		}
		if (map[index] == '\n')
			index++;
		if (current_length > max_length)
			max_length = current_length;
	}
	if (max_length > MAX_MAP_LENGTH)
		return (set_map_errno(maps, WIDOVE), 0);
	return (max_length);
}

char	**create_map_array(const char *token, t_map *map)
{
	uint32_t	nbr_of_array;
	uint32_t	max_length;
	char		**map_array;

	nbr_of_array = count_number_of_array(token, map);
	if (map->map_errno)
		return (NULL);
	max_length = get_max_length(token, map);
	if (map->map_errno)
		return (NULL);
	map_array = ft_calloc(1, (sizeof(char *) * (nbr_of_array)));
	if (!map_array)
		return (set_map_errno(map, ALLOCF), NULL);
	fill_map_array(&map_array, token, max_length, map);
	return (map_array);
}
