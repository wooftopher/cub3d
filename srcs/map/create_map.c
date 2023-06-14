/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:51:00 by christo           #+#    #+#             */
/*   Updated: 2023/06/14 15:35:24 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./map.h"

int	ft_init_player(int x, int y, t_player *player, t_map *map)
{
	player->pos_x = x * 100 + 50;
	player->pos_y = y * 100 + 50;
	if (map->map[y][x] == 'N')
		player->angle = 180;
	else if(map->map[y][x] == 'S')
		player->angle = 0;
	else if(map->map[y][x] == 'W')
		player->angle = 270;
	else if(map->map[y][x] == 'E')
		player->angle = 90;
	player->rot_speed = 4;
	player->speed = 10;
	player->col_x = 0;
	player->col_y = 0;
	return (0);
}

void	init_background(t_cub3d *cub3d) // HAVE A RETURN VALUE FOR LATER ERROR HANDLING
{
	int			x;
	int			y;
	int32_t		ret;

	y = 0;
	cub3d->mlx_s->img_back = mlx_new_image(cub3d->mlx_s->mlx, 1900, 900);
	if (!cub3d->mlx_s->img_back)
		return ;
	while (y < 450)
	{
		x = 0;
		while (x < 1900)
		{
			mlx_put_pixel(cub3d->mlx_s->img_back, x,
				y, cub3d->map->ceiling_color);
			mlx_put_pixel(cub3d->mlx_s->img_back, x,
				y + 450, cub3d->map->floor_color);
			x++;
		}
		y++;
	}
	ret = mlx_image_to_window(cub3d->mlx_s->mlx,
			cub3d->mlx_s->img_back, 0, 0);
	if (ret == FAILURE)
		return ;
}

void	ft_create_map(t_map *map, t_cub3d *cub3d)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	init_background(cub3d);
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
}