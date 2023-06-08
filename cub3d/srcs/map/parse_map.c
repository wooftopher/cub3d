/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:54:39 by christo           #+#    #+#             */
/*   Updated: 2023/06/07 19:27:24 by ddemers          ###   ########.fr       */
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

// void	ft_print_map(t_map *map)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < map->height)
// 	{
// 		while (x < map->lenght)
// 		{
// 			printf("%c", map->map[y][x]);
// 			x++;
// 		}
// 		x = 0;
// 		printf("%c", '\n');
// 		y++;
// 	}
// }

// void	ft_write_map(char *str, t_map *map)
// {
// 	int		x;
// 	int		y;
// 	int		k;
// 	int		kmax;

// 	k = 0;
// 	x = 0;
// 	y = 0;
// 	kmax = strlen(str);  // libft
// 	while (k < kmax && str[k])
// 	{
// 		map->map[y][x] = str[k];
// 		k++;
// 		x++;
// 		if (str[k] == '\n')
// 		{
// 			y++;
// 			k++;
// 			x = 0;
// 		}
// 	}
// }

// char	*ft_read_map(t_cub3d *cub3d)
// {
//   	char 	buffer[10240];
//     size_t	num_read;
//     int		offset;
// 	int		fd;
// 	char 	*map; //trop variable
	
// 	fd = open("./map/0.ber", O_RDONLY);
//     if (fd == -1)
// 		fd_error(cub3d, fd);
// 	//read until EOF
//     map = malloc(10240 * sizeof(char));
// 	offset = 0;
// 	num_read = 0;
//     while ((num_read = read(fd, buffer, sizeof(buffer))) > 0)
// 	{
//         memcpy(map + offset, buffer, num_read); // libft
//         offset += num_read;
// 	}
// 	close(fd);
// 	return (map);
// }

// void	malloc_map(t_map *map)
// {
// 	int i;
// 	int j;
	
// 	i = 0;
// 	j = 0;
// 	map->map = calloc(map->lenght, sizeof(char*));
//     if (map == NULL) 
//         fprintf(stderr, "Error: failed to allocate memory.\n");
// 	while (i < map->lenght)
// 	{
// 		map->map[i] = (char*) calloc(map->height, sizeof(char));
// 		if (map->map[i] == NULL)
// 		{
//             fprintf(stderr, "Error: failed to allocate memory.\n");
// 			while (j < i)
// 			{
// 				free(map->map[j]);
// 				j++;
// 			}
// 			free(map->map);
// 		}
// 		i++;
// 	}
// }


// // void ft_map_init(t_cub3d *cub3d)
// // {
// //     cub3d->map->map = malloc(sizeof(char *) * 13);
// //     cub3d->map->map[0] = strdup("01111111111111111111111111000000000000000000000000000000000");
// //     cub3d->map->map[1] = strdup("10000000001100000000000010000000000000000000000000000000000");
// //     cub3d->map->map[2] = strdup("10110000011100000000000010000000000000000000000000000000000");
// //     cub3d->map->map[3] = strdup("10010000000000000000000010000000000000000000000000000000000");
// //     cub3d->map->map[4] = strdup("11111111101100000111000000000000100000000000000000000000000");
// //     cub3d->map->map[5] = strdup("10000000001100000111011111111111100000000000000000000000000");
// //     cub3d->map->map[6] = strdup("11110111111111011100000010001000000000000000000000000000000");
// //     cub3d->map->map[7] = strdup("11110111111111011101010010001000000000000000000000000000000");
// //     cub3d->map->map[8] = strdup("11000000110101011100000010001010000000000000001100000010001");
// //     cub3d->map->map[9] = strdup("10000000000000001101010010001000000000000000000000000000000");
// //     cub3d->map->map[10] = strdup("11000001110101011111011110N01110000000000000000000000000000");
// //     cub3d->map->map[11] = strdup("11110111011101010101111010001000000000000000000000000000000");
// //     cub3d->map->map[12] = NULL;
// // 	cub3d->map->wall_count = 100;
// // 	cub3d->map->wall_px = calloc(100, sizeof(int));
// // 	cub3d->map->wall_py = calloc(100, sizeof(int));
// // 	// for (int i = 0; cub3d->map->map[i]; i++)
// // 	// 	printf("%s\n", cub3d->map->map[i]);
// // 	// exit (0);
// //     //ft_print_map(cub3d->map);
// // }


// void	ft_map_init(t_cub3d *cub3d)
// {
// 	char	*file;

// 	file = ft_read_map(cub3d);
// 	set_map_lenght(cub3d->map, file);
// 	set_map_height(cub3d->map, file);
// 	count_wall(cub3d->map, file);
// 	malloc_map(cub3d->map);
// 	ft_write_map(file, cub3d->map);
// 	free(file);
// 	// ft_print_map(cub3d->map);
// }