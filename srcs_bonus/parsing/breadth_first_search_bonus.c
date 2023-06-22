/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:02:39 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/05 01:02:39 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

/*
	https://www.youtube.com/watch?v=xlVX7dXLS64
*/
		// usleep(1000);
		// for (int i = 0; i < bfs_info.max_y; i++)
		// 	printf("%s\n", map[i]);
		// printf("\n");
bool	breadth_first_search(char **map, t_bfs_info bfs_info)
{
	t_queue	queue;
	t_cell	*current;

	if (bfs_info.start_y == 0 || bfs_info.start_y == bfs_info.max_y - 1
		|| bfs_info.start_x == 0 || bfs_info.start_x == bfs_info.max_x - 1)
		return (false);
	init_queue(&queue);
	if (!queue.cell_queue)
		return (false);
	add(&queue, bfs_info.start_y, bfs_info.start_x, map);
	while (!queue_is_empty(&queue))
	{
		current = pop(&queue);
		if (!neighbors(&queue, current, map, bfs_info))
			return (free(queue.cell_queue), false);
	}
	return (free(queue.cell_queue), true);
}
