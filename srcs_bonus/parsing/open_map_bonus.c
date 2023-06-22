/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:18:25 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:57:17 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

int	open_file(const char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == FAILURE)
		return (FAILURE);
	return (fd);
}
