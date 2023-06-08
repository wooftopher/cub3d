/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:55:24 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/07 16:17:01 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

static void	process_token(char *token, uint8_t *processedflags, t_map *map)
{
	if (!return_flag(processedflags, NORTH) && !ft_strncmp(token, "NO ", 3))
		map->n_texture = parse_texture(token, processedflags, NORTH, map);
	else if (!return_flag(processedflags, SOUTH) && !ft_strncmp(token,
			"SO ", 3))
		map->s_texture = parse_texture(token, processedflags, SOUTH, map);
	else if (!return_flag(processedflags, WEST) && !ft_strncmp(token, "WE ", 3))
		map->w_texture = parse_texture(token, processedflags, WEST, map);
	else if (!return_flag(processedflags, EAST) && !ft_strncmp(token, "EA ", 3))
		map->e_texture = parse_texture(token, processedflags, EAST, map);
	else if (!return_flag(processedflags, FLOOR) && !ft_strncmp(token, "F ", 2))
		map->floor_color = parse_colors(token, processedflags, FLOOR, map);
	else if (!return_flag(processedflags, CEILING) && !ft_strncmp(token,
			"C ", 2))
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
