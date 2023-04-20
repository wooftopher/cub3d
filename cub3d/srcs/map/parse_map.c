/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:54:39 by christo           #+#    #+#             */
/*   Updated: 2023/04/20 01:47:30 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./map.h"
// # include "../main/struct.h"

void fd_error(t_cub3d *cub3d, int fd)
{
     if (errno == ENOENT)
         printf("File does not exist\n");
     else if (errno == EACCES)
         printf("Permission denied\n");
     else
         printf("Failed to open file: %d\n", errno);
	if (fd > 0)
		close(fd);
	exit (0);
}

void	ft_print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->lenght)
		{
			printf("%c", map->map[y][x]);
			x++;
		}
		x = 0;
		printf("%c", '\n');
		y++;
	}
}

void	*ft_write_map(char *str, t_map *map)
{
	int		x;
	int		y;
	int		k;
	int		kmax;

	k = 0;
	x = 0;
	y = 0;
	kmax = strlen(str);  // libft
	while (k < kmax && str[k])
	{
		map->map[y][x] = str[k];
		k++;
		x++;
		if (str[k] == '\n')
		{
			y++;
			k++;
			x = 0;
		}
	}
}

char	*ft_read_map(t_cub3d *cub3d)
{
  	char 	buffer[1024];
    size_t	num_read;
    int		offset;
	int		fd;
	char 	*map; //trop variable
	
	fd = open("map/0.ber", O_RDONLY);
    if (fd == -1)
		fd_error(cub3d, fd);
	//read until EOF
    map = malloc(1024 * sizeof(char));
	offset = 0;
	num_read = 0;
    while ((num_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
        memcpy(map + offset, buffer, num_read); // libft
        offset += num_read;
	}
	close(fd);
	return (map);
}

void	malloc_map(t_map *map)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	map->map = calloc(map->lenght, sizeof(char*));
    if (map == NULL) 
        fprintf(stderr, "Error: failed to allocate memory.\n");
	while (i < map->lenght)
	{
		map->map[i] = (char*) calloc(map->height, sizeof(char));
		if (map->map[i] == NULL)
		{
            fprintf(stderr, "Error: failed to allocate memory.\n");
			while (j < i)
			{
				free(map->map[j]);
				j++;
			}
			free(map->map);
		}
		i++;
	}
}

void	ft_map_init(t_cub3d *cub3d)
{
	char	*file;
	// t_map	map;

	// cub3d->map = &map;
	file = ft_read_map(cub3d);
	set_map_lenght(cub3d->map, file);
	set_map_height(cub3d->map, file);
	count_wall(cub3d->map, file);
	malloc_map(cub3d->map);
	ft_write_map(file, cub3d->map);
	free(file);
	ft_print_map(cub3d->map);
	cub3d->mlx->mlx = mlx_init(cub3d->map->lenght * 100, cub3d->map->height * 100, "cub3d", true);
	if (!cub3d->mlx)
	    perror("Error opening mlx");
	cub3d->mlx->xpm_wall = NULL;
	ft_create_map(cub3d->map, cub3d);
}