/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:41:06 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/02 14:41:06 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

static void	put_str_error(const char *error_str)
{
	write(STDERR_FILENO, error_str, ft_strlen(error_str));
}

void	set_map_errno(t_map *map, uint8_t flag)
{
	map->map_errno = flag;
}

/* 
	I need to stop drinking, I decided to come up with a custom errno.
   	The errno is stored in t_map struct in an uint8_t, this function print
	a message according to the error stored in a file using indexing.
	Get help next time you decide to come up with such a convoluted idea
*/
void	print_map_errno(uint8_t flag)
{
	int		fd;
	int		read_ret;
	char	buffer[FILE_BUFFER_SIZE];

	if (!OS)
		fd = open("_mac_errno.txt", O_RDONLY);
	if (OS)
		fd = open("_mac_errno.txt", O_RDONLY); // FIX LATER OS
	if (fd == FAILURE)
		return (put_str_error("Couldn't locate map_errno file,"
				"undefined map error\n"));
	read_ret = read(fd, buffer, FILE_BUFFER_SIZE);
	if (read_ret == FAILURE)
		return (close(fd), put_str_error("Couldn't read map_errno file, "
				"undefined map error\n"));
	if (read_ret > FILE_SIZE)
		return (close(fd), put_str_error("Invalid map_errno file, "
				"undefined map error\n"));
	buffer[read_ret] = '\0';
	buffer[(flag * LINE_LENGTH) + LINE_LENGTH - 1] = '\0';
	put_str_error("Error\n");
	put_str_error(buffer + ((flag * LINE_LENGTH) + 3));
	close(fd);
}
