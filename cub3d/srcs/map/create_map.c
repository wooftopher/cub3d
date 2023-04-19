/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:51:00 by christo           #+#    #+#             */
/*   Updated: 2023/04/19 03:50:25 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./map.h"
// # include "../main/struct.h"

int ft_init_wall(int x, int y, t_cub3d *cub3d)
{
	// xpm_t	*xpm;
    static int wall_count;

	cub3d->wall_px[wall_count] = x * 100;
	cub3d->wall_py[wall_count] = y * 100;
    if (!cub3d->xpm_wall)
	    cub3d->xpm_wall = mlx_load_xpm42("./img/0.xpm42");
	cub3d->img_wall
        = mlx_texture_to_image(cub3d->mlx, &cub3d->xpm_wall->texture);
	// mlx_delete_xpm42(xpm);
	mlx_image_to_window(cub3d->mlx, cub3d->img_wall, x * 100, y * 100);
	wall_count++;
	return (0);
}

int	ft_init_player(int x, int y, t_cub3d *cub3d)
{
	
	cub3d->xpm_player = mlx_load_xpm42("./img/d2.xpm42");
	cub3d->img_player = mlx_texture_to_image(cub3d->mlx, &cub3d->xpm_player->texture);
	mlx_delete_xpm42(cub3d->xpm_player);
	mlx_image_to_window(cub3d->mlx, cub3d->img_player, x * 100, y * 100);
    cub3d->img_player->instances[0].z = 18;
	// cub3d->p_x = x;
	// cub3d->p_y = y;
	return (0);
}

void	ft_create_map(t_map *map, t_cub3d *cub3d)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while (x < map->lenght)
	{
		while (y < map->height)
		{
			if (map->map[y][x] == '1')
				ft_init_wall(x, y, cub3d);
			if (map->map[y][x] == 'P')
				ft_init_player(x, y, cub3d);
			y++;
		}
		y = 0;
		x++;
	}
    mlx_delete_xpm42(cub3d->xpm_wall);
}