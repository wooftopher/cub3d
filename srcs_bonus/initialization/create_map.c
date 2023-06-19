/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:11:20 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/18 13:08:44 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initialization.h"

int ft_init_player(int x, int y, t_player *player, t_map *map)
{
    player->pos_x = x * 100 + 50;
    player->pos_y = y * 100 + 50;
    if (map->map[y][x] == 'N')
        player->angle = 180;
    else if (map->map[y][x] == 'S')
        player->angle = 0;
    else if (map->map[y][x] == 'W')
        player->angle = 270;
    else if (map->map[y][x] == 'E')
        player->angle = 90;
    player->rot_speed = 4;
    player->speed = 10;
    player->col_x = 0;
    player->col_y = 0;
    return (0);
}

int8_t  ft_create_map(t_map *map, t_cub3d *cub3d)
{
    int     x;
    int     y;
    x = 0;
    y = 0;
    while (x < map->width)
    {
        while (y < map->height)
        {
            if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
                || map->map[y][x] == 'W' || map->map[y][x] == 'E')
                ft_init_player(x, y, cub3d->player, map);
            y++;
        }
        y = 0;
        x++;
    }
    return (SUCCESS);
}
