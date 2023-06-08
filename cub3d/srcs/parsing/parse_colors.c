/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:51:00 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/07 22:34:41 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

uint32_t	get_r(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

static int	get_new_index(int index, char *token)
{
	while (ft_isdigit(token[index]))
		index++;
	if (token[index] == ',')
		index++;
	return (index);
}

static int	get_number(int index, char *token, t_map *map)
{
	int	result;

	if (!token[index] || !ft_isalnum(token[index]))
		return (set_map_errno(map, INVACO), FAILURE);
	result = atoi_cube(token + index);
	if (result > 255 || result < 0)
		return (set_map_errno(map, INVACO), FAILURE);
	return (result);
}

static int	get_starting_index(int index, char *token)
{
	while (ft_isspace(token[index]))
		index++;
	return (index);
}

uint32_t	parse_colors(char *token, uint8_t *processedflags,
				uint8_t flag, t_map *map)
{
	int			red;
	int			green;
	int			blue;
	int			index;

	index = 2;
	index = get_starting_index(index, token);
	red = get_number(index, token, map);
	index = get_new_index(index, token);
	green = get_number(index, token, map);
	index = get_new_index(index, token);
	blue = get_number(index, token, map);
	if (red == FAILURE || green == FAILURE || blue == FAILURE)
		return (0);
	set_flag(processedflags, flag);
	return (get_r(red, green, blue, 255));
}
