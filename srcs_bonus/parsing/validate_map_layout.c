/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_layout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:19:52 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/05 01:19:52 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

static void	free_copy_failure(char **array, uint8_t count)
{
	uint8_t	index;

	index = 0;
	while (index < count)
		free(array[index++]);
	free(array);
}

static char	**create_map_copy(t_map *map)
{
	uint8_t		index;
	char		**map_copy;

	map_copy = malloc(sizeof(char *) * map->height);
	index = 0;
	while (index < map->height)
	{
		map_copy[index] = ft_strdup(map->map[index]);
		if (!map_copy[index])
		{
			free_copy_failure(map_copy, index);
			return (set_map_errno(map, ALLOCF), NULL);
		}
		index++;
	}
	return (map_copy);
}

static void	get_starting_position(char **map_copy, t_bfs_info *bfs_info)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (map_copy[y])
	{
		x = 0;
		while (map_copy[y][x])
		{
			if (map_copy[y][x] == 'N' || map_copy[y][x] == 'S'
				|| map_copy[y][x] == 'W' || map_copy[y][x] == 'E')
			{
				bfs_info->start_y = y;
				bfs_info->start_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	map_copy_destructor(char **map_copy, uint8_t height)
{
	uint8_t	index;

	index = 0;
	while (index < height)
		free(map_copy[index++]);
	free(map_copy);
}

void	validate_map_layout(t_map *map)
{
	t_bfs_info	bfs_info;
	char		**map_copy;
	bool		result;

	map_copy = create_map_copy(map);
	if (!map_copy)
		return ;
	get_starting_position(map_copy, &bfs_info);
	bfs_info.max_y = map->height;
	bfs_info.max_x = map->width;
	result = breadth_first_search(map_copy, bfs_info);
	map_copy_destructor(map_copy, map->height);
	if (result == false)
		set_map_errno(map, INVALM);
}
