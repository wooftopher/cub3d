/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:51:00 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/09 11:55:34 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

uint32_t	get_r(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

static int    get_color(int *index, char *token, t_map *map)
{
    int            result;
    uint32_t    i;

    i = *index;
    if (map->map_errno)
        return (FAILURE);
    if (!token[i])
        return (set_map_errno(map, INVACO), FAILURE);
    while (ft_isspace(token[i]))
        i++;
    if (!ft_isdigit(token[i]))
        return (set_map_errno(map, INVACO), FAILURE);
    result = atoi_cube(token + i);
    if (result > 255 || result < 0)
        return (set_map_errno(map, INVACO), FAILURE);
    while (ft_isdigit(token[i]))
        i++;
    if (token[i] == ',')
        i++;
    *index = i;
    return (result);
}
uint32_t	parse_colors(char *token, uint8_t *processedflags,
				uint8_t flag, t_map *map)
{
	int			red;
	int			green;
	int			blue;
	int			index;

	index = 2;
	red = get_color(&index, token, map);
	green = get_color(&index, token, map);
	blue = get_color(&index, token, map);
	if (red == FAILURE || green == FAILURE || blue == FAILURE)
		return (0);
	set_flag(processedflags, flag);
	return (get_r(red, green, blue, 255));
}
