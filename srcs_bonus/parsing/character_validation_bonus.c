/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:25:33 by ddemers           #+#    #+#             */
/*   Updated: 2023/05/29 01:25:33 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"
#include <limits.h>

inline static bool	is_starting_position(const char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

inline static bool	is_map_character(const char c)
{
	if (c == '1' || c == '0' || c == '\n' || c == '2' || c == '3' || c == ' '
		|| c == 'C')
		return (true);
	return (false);
}

static void	print_found_character(const char c)
{
	write(STDIN_FILENO, "Found: ", 7);
	write(STDIN_FILENO, &c, 1);
	write(STDIN_FILENO, "\n", 1);
}

bool	map_token_validation(const char *token, t_map *map, uint32_t index)
{
	bool		starting_position;

	starting_position = false;
	while (token[index])
	{
		if (index == UINT_MAX)
			return (set_map_errno(map, INTOVE), false);
		if (!is_map_character(token[index]))
		{
			if (!starting_position && is_starting_position(token[index]))
			{
				starting_position = true;
				index++;
				continue ;
			}
			print_found_character(token[index]);
			if (starting_position == true)
				return (set_map_errno(map, MULTIP), false);
			return (set_map_errno(map, MAPCHA), false);
		}
		index++;
	}
	if (starting_position == false)
		return (set_map_errno(map, INVASP), false);
	return (true);
}
