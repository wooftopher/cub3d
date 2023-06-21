/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:20:43 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/21 15:08:41 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

void	free_null(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	map_struct_destructor(t_map *map)
{
	uint32_t	index;

	index = 0;
	if (map->n_texture)
		free(map->n_texture);
	if (map->s_texture)
		free(map->s_texture);
	if (map->w_texture)
		free(map->w_texture);
	if (map->e_texture)
		free(map->e_texture);
	if (map->wall_px)
		free(map->wall_px);
	if (map->wall_py)
		free(map->wall_py);
	if (map->music_path)
		free(map->music_path);
	if (map->map)
	{
		while (map->map[index])
			free(map->map[index++]);
		free(map->map);
	}
}

static void	map_struct_constructor(t_map *map)
{
	map->map = NULL;
	map->n_texture = NULL;
	map->s_texture = NULL;
	map->w_texture = NULL;
	map->e_texture = NULL;
	map->ceiling_color = 0;
	map->floor_color = 0;
	map->width = 0;
	map->height = 0;
	map->wall_count = 0;
	map->wall_px = NULL;
	map->wall_py = NULL;
	map->map_errno = 0;
}

void	map_initialization(t_map *map, const char *file_name)
{
	int		fd;
	char	*file_data;

	map_struct_constructor(map);
	if (!map_name_validator(file_name))
		return (set_map_errno(map, INVANA));
	fd = open_file(file_name);
	if (fd == FAILURE)
		return (set_map_errno(map, INVAFL));
	file_data = read_fd(map, fd);
	close(fd);
	if (!file_data)
		return ;
	process_map_data(map, file_data);
	if (map->map_errno)
		return (free(file_data));
	free(file_data);
	validate_map_layout(map);
	if (map->map_errno)
		return ;
	modify_map(map);
}
