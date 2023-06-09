/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:18:25 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/07 10:39:28 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

int	open_file(const char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == FAILURE)
		return (FAILURE);
	return (fd);
}
