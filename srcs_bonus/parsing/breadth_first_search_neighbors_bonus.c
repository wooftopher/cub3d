/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search_neighbors.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:59:34 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/05 15:59:34 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

//y -1 y + 1 x - 1 x + 1
bool	neighbors(t_queue *queue, t_cell *current, char **map,
			t_bfs_info bfs_info)
{
	uint16_t	y;
	uint16_t	x;

	y = current->y;
	x = current->x;
	if (is_on_edge(y, x, bfs_info))
		return (false);
	if (is_forbidden(map[y - 1][x]) || is_forbidden(map[y + 1][x])
		|| is_forbidden(map[y][x - 1]) || is_forbidden(map[y][x + 1]))
		return (false);
	if (is_valid(map[y - 1][x]) && !is_visited(map[y - 1][x]))
		add(queue, y - 1, x, map);
	if (is_valid(map[y + 1][x]) && !is_visited(map[y + 1][x]))
		add(queue, y + 1, x, map);
	if (is_valid(map[y][x - 1]) && !is_visited(map[y][x - 1]))
		add(queue, y, x - 1, map);
	if (is_valid(map[y][x + 1]) && !is_visited(map[y][x + 1]))
		add(queue, y, x + 1, map);
	return (true);
}
