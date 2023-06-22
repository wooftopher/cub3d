/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:24:17 by ddemers           #+#    #+#             */
/*   Updated: 2023/05/29 14:24:17 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

char	*substr_cube(const char *map, uint32_t start,
			size_t len, size_t max_length)
{
	size_t	index;
	char	*str;

	if (!map)
		return (NULL);
	index = 0;
	str = malloc(sizeof(char) * (max_length + 1));
	if (!str)
		return (NULL);
	str[max_length] = '\0';
	while (index < len && map[index] && map[start])
		str[index++] = map[start++];
	while (index < max_length)
		str[index++] = '#';
	return (str);
}
