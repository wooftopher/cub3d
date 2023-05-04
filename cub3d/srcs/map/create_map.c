/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:51:00 by christo           #+#    #+#             */
/*   Updated: 2023/05/01 23:28:16 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./map.h"
// # include "../main/struct.h"

int ft_init_wall(int x, int y, t_map *map, t_mlx_struc *mlx_s)
{
    static int wall_count;

	map->wall_px[wall_count] = x * 100;
	map->wall_py[wall_count] = y * 100;
    // if (!mlx_s->xpm_wall)
	//     mlx_s->xpm_wall = mlx_load_xpm42("./img/0.xpm42");
	// mlx_s->img_wall
    //     = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_wall->texture);
	// mlx_image_to_window(mlx_s->mlx, mlx_s->img_wall, x * 100, y * 100);
	wall_count++;
	return (0);
}

int	ft_init_player(int x, int y, t_player *player, t_mlx_struc *mlx_s)
{
	player->pos_x = x * 100 + 50;
	player->pos_y = y * 100 + 50;
	player->angle = 0;
	player->rot_speed = 4;
	player->speed = 5;
	player->col_x = 0;
	player->col_y = 0;
	// mlx_s->xpm_player = mlx_load_xpm42("./img/eye.xpm42");
	// mlx_s->img_player = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_player->texture);
	// mlx_delete_xpm42(mlx_s->xpm_player);
	// mlx_image_to_window(mlx_s->mlx, mlx_s->img_player,
		// player->pos_x - 10, player->pos_y - 10);
	// if (!mlx_s->text_eye)
	//     mlx_s->xpm_wall = mlx_load_png("./img/wall.png");
	// mlx_s->img_wall
    //     = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_wall->texture);
	// mlx_image_to_window(mlx_s->mlx, mlx_s->img_wall, x * 50, y * 50);
	return (0);
}

void	init_minimap(int x, int y, t_map *map, t_mlx_struc *mlx_s)
{
	if (!mlx_s->text_wall)
	    mlx_s->text_wall = mlx_load_png("./img/wall.png");
	mlx_s->img_wall
        = mlx_texture_to_image(mlx_s->mlx, mlx_s->text_wall);
	mlx_image_to_window(mlx_s->mlx, mlx_s->img_wall, x * 50, y * 50);
}

void	ft_create_map(t_map *map, t_cub3d *cub3d)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	cub3d->mlx_s->xpm_wall = NULL;
	while (x < map->lenght)
	{
		while (y < map->height)
		{
			if (map->map[y][x] == '1')
			{
				ft_init_wall(x, y, cub3d->map, cub3d->mlx_s);
				init_minimap(x, y, cub3d->map, cub3d->mlx_s);
			}
			if (map->map[y][x] == 'P')
				ft_init_player(x, y, cub3d->player, cub3d->mlx_s);
			y++;
		}
		y = 0;
		x++;
	}
    // mlx_delete_xpm42(cub3d->mlx->xpm_wall);
}