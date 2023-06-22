/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_data_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:55:24 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:57:12 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

static bool	str_find(const char *token, const char *to_find)
{
	uint32_t	index;
	uint32_t	to_find_index;

	index = 0;
	while (token[index])
	{
		to_find_index = 0;
		while (token[index] == to_find[to_find_index])
		{
			index++;
			to_find_index++;
			if (to_find[to_find_index] == '\0')
				return (true);
		}
		if (token[index] != ' ')
			return (false);
		index++;
	}
	return (false);
}

static void	process_token(char *token, uint8_t *processedflags, t_map *map)
{
	if (!return_flag(processedflags, NORTH) && str_find(token, "NO "))
		map->n_texture = parse_texture(token, processedflags, NORTH, map);
	else if (!return_flag(processedflags, SOUTH) && str_find(token, "SO "))
		map->s_texture = parse_texture(token, processedflags, SOUTH, map);
	else if (!return_flag(processedflags, WEST) && str_find(token, "WE "))
		map->w_texture = parse_texture(token, processedflags, WEST, map);
	else if (!return_flag(processedflags, EAST) && str_find(token, "EA "))
		map->e_texture = parse_texture(token, processedflags, EAST, map);
	else if (!return_flag(processedflags, MUSIC) && str_find(token, "MU "))
		map->music_path = parse_texture(token, processedflags, MUSIC, map);
	else if (!return_flag(processedflags, FLOOR) && str_find(token, "F "))
		map->floor_color = parse_colors(token, processedflags, FLOOR, map);
	else if (!return_flag(processedflags, CEILING) && str_find(token, "C "))
		map->ceiling_color = parse_colors(token, processedflags, CEILING, map);
	else
		set_map_errno(map, INVALI);
}

void	process_map_data(t_map *map, char *file_data)
{
	char	*token;
	uint8_t	processedflags;

	processedflags = 0;
	token = ft_strtok(file_data, "\n");
	if (!token)
		return (set_map_errno(map, EMPTYF));
	while (token)
	{
		process_token(token, &processedflags, map);
		if (processedflags == OK)
			break ;
		if (map->map_errno)
			return ;
		token = ft_strtok(NULL, "\n");
	}
	token = ft_strtok(NULL, "\0");
	if (!token)
		return ;
	if (!map_token_validation(token, map, 0))
		return ;
	token = tokenize_map(token, map);
	map->map = create_map_array(token, map);
	fill_map_data(map);
}
