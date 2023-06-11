/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:10:33 by christo           #+#    #+#             */
/*   Updated: 2023/05/27 02:39:52 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../main/cub3d.h"
# include "../main/struct.h"

//parse_map
void	ft_create_map(t_map *map, t_cub3d *cub3d);
void 	fd_error(t_cub3d *cub3d, int fd);

//map_utils
void set_map_lenght(t_map *map, char *str);
void set_map_height(t_map *map, char *str);
void count_wall(t_map *map, char *str);

// typedef struct map
// {
//     char    **map;
//     int     lenght;
//     int     height;
    
// }   t_map;

#endif