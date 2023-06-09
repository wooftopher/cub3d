/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:11:55 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/05 14:11:55 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

bool	queue_is_empty(t_queue *queue)
{
	if (queue->front == queue->end)
		return (true);
	return (false);
}

void	add(t_queue *queue, uint16_t y, uint16_t x, char **map)
{
	queue->cell_queue[queue->end].y = y;
	queue->cell_queue[queue->end].x = x;
	queue->end++;
	map[y][x] = 'V';
}

t_cell	*pop(t_queue *queue)
{
	return (&queue->cell_queue[queue->front++]);
}

void	init_queue(t_queue *queue)
{
	queue->front = 0;
	queue->end = 0;
	queue->cell_queue = malloc(sizeof(t_cell) * MAX_QUEUE_SIZE);
}
