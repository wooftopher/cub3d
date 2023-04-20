/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:14:36 by christo           #+#    #+#             */
/*   Updated: 2023/04/20 00:41:01 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./map.h"

void set_map_lenght(t_map *map, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	map->lenght = i;
}

void set_map_height(t_map *map, char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			x++;
		i++;
	}
	x++;
	map->height = x;
}

void count_wall(t_map *map, char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == '1')
			x++;
		i++;
	}
	map->wall_count = x;
	map->wall_px = calloc(x, sizeof(int));
	map->wall_py = calloc(x, sizeof(int));
}