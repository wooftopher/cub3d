/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:22:27 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/10 00:50:14 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

static uint32_t	get_end(char *token)
{
	uint32_t	index;
	uint32_t	end;

	index = 0;
	end = index;
	while (token[index])
	{
		if (!ft_isspace(token[index]))
			end = index;
		index++;
	}
	return (end);
}

static void	fill_token(char *token, char *result)
{
	uint32_t	index;
	uint32_t	end;

	end = get_end(token);
	index = 0;
	while (index <= end)
	{
		result[index] = token[index];
		index++;
	}
	result[index] = '\0';
}

static char	*trim_texture_token(t_map *map, char *token)
{
	char	*result;
	int		index;
	size_t	length;

	index = 0;
	while (token[index] == ' ')
		index++;
	index += 3;
	while (token[index] == ' ')
		index++;
	length = ft_strlen(token + index);
	if (!length)
	{
		result = ft_calloc(1, 1);
		if (!result)
			return (set_map_errno(map, ALLOCF), NULL);
		return (result);
	}
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (set_map_errno(map, ALLOCF), NULL);
	fill_token(token + index, result);
	return (result);
}

char	*parse_texture(char *token, uint8_t *processedflags,
			uint8_t flag, t_map *map)
{
	char	*result;

	result = trim_texture_token(map, token);
	if (!result)
		return (NULL);
	set_flag(processedflags, flag);
	return (result);
}
