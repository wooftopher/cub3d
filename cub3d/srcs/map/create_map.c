/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:51:00 by christo           #+#    #+#             */
/*   Updated: 2023/04/25 14:44:48 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./map.h"
// # include "../main/struct.h"

int ft_init_wall(int x, int y, t_map *map, t_mlx_struc *mlx)
{
    static int wall_count;

	map->wall_px[wall_count] = x * 100;
	map->wall_py[wall_count] = y * 100;
    if (!mlx->xpm_wall)
	    mlx->xpm_wall = mlx_load_xpm42("./img/0.xpm42");
	mlx->img_wall
        = mlx_texture_to_image(mlx->mlx, &mlx->xpm_wall->texture);
	mlx_image_to_window(mlx->mlx, mlx->img_wall, x * 100, y * 100);
	wall_count++;
	return (0);
}

int	ft_init_player(int x, int y, t_player *player, t_mlx_struc *mlx)
{
	player->pos_x = x * 100 + 50;
	player->pos_y = y * 100 + 50;
	player->angle = 300;
	player->rot_speed = 3;
	player->speed = 5;
	player->col_x = 0;
	player->col_y = 0;
	mlx->xpm_player = mlx_load_xpm42("./img/eye.xpm42");
	mlx->img_player = mlx_texture_to_image(mlx->mlx, &mlx->xpm_player->texture);
	mlx_delete_xpm42(mlx->xpm_player);
	mlx_image_to_window(mlx->mlx, mlx->img_player,
		player->pos_x - 10, player->pos_y - 10);
	return (0);
}

void	ft_create_map(t_map *map, t_cub3d *cub3d)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	cub3d->mlx->xpm_wall = NULL;
	while (x < map->lenght)
	{
		while (y < map->height)
		{
			if (map->map[y][x] == '1')
				ft_init_wall(x, y, cub3d->map, cub3d->mlx);
			if (map->map[y][x] == 'P')
				ft_init_player(x, y, cub3d->player, cub3d->mlx);
			y++;
		}
		y = 0;
		x++;
	}
    mlx_delete_xpm42(cub3d->mlx->xpm_wall);
}