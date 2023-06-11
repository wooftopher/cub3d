/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:14:36 by christo           #+#    #+#             */
/*   Updated: 2023/06/07 20:23:20 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./map.h"

void set_map_lenght(t_map *map, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	map->height = i;
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
	map->wall_px = calloc(x, sizeof(float));
	map->wall_py = calloc(x, sizeof(float));
}