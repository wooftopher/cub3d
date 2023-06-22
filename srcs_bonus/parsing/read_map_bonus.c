/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:40:13 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:57:10 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

static char	*stitch_strings(char *result, const char *buffer)
{
	size_t	length;
	int		index;
	int		j;
	char	*result_ret;

	j = 0;
	index = -1;
	if (!result)
	{
		result = malloc(sizeof(char) * 1);
		if (!result)
			return (NULL);
		result[0] = 0;
	}
	length = ft_strlen(result) + ft_strlen(buffer) + 1;
	result_ret = malloc(sizeof(char) * length);
	if (!result_ret)
		return (free(result), NULL);
	result_ret[length - 1] = 0;
	while (result[++index])
		result_ret[index] = result[index];
	while (buffer[j])
		result_ret[index++] = buffer[j++];
	return (free(result), result_ret);
}

static void	set_value_fuck_norm(int *read_ret, uint32_t *buffer_count)
{
	*read_ret = 1;
	*buffer_count = 0;
}

char	*read_fd(t_map *map, int fd)
{
	int			read_ret;
	uint32_t	buffer_count;
	char		*buffer;
	char		*result;

	buffer = malloc(sizeof(char) * (INITIAL_BUFFER + 1));
	if (!buffer)
		return (set_map_errno(map, ALLOCF), NULL);
	set_value_fuck_norm(&read_ret, &buffer_count);
	result = NULL;
	while (read_ret)
	{
		read_ret = read(fd, buffer, INITIAL_BUFFER);
		if (read_ret == FAILURE)
			return (set_map_errno(map, READFA), free(buffer), NULL);
		buffer[read_ret] = 0;
		buffer_count += read_ret;
		if (buffer_count > MAX_MAP_LENGTH)
			return (free(buffer), set_map_errno(map, BUFFOV), NULL);
		result = stitch_strings(result, buffer);
		if (!result)
			return (set_map_errno(map, ALLOCF), free(buffer), NULL);
	}
	free(buffer);
	return (result);
}
