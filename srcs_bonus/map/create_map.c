/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:51:00 by christo           #+#    #+#             */
/*   Updated: 2023/06/10 20:28:47 by cperron          ###   ########.fr       */
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
	player->speed = 5;
	player->col_x = 0;
	player->col_y = 0;
	// mlx_s->xpm_player = mlx_load_xpm42("./img/eye.xpm42");
	// printf ("text : %d", &mlx_s->xpm_player->texture);
	// mlx_s->img_player = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_player->texture);
	// mlx_delete_xpm42(mlx_s->xpm_player);
	// mlx_image_to_window(mlx_s->mlx, mlx_s->img_player,
	// 	player->pos_x - 10, player->pos_y - 10);
	// if (!mlx_s->text_eye)
	//     mlx_s->xpm_wall = mlx_load_png("./img/wall.png");
	// mlx_s->img_wall
    //     = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_wall->texture);
	// mlx_image_to_window(mlx_s->mlx, mlx_s->img_wall, x * 50, y * 50);
	return (0);
}

// void	init_background(t_cub3d *cub3d)
// {
// 	int			x;
// 	int			y;
// 	uint32_t 	color;

// 	y = 0;
// 	color = cub3d->map->ceiling_color;
// 	cub3d->mlx_s->img_back =  mlx_new_image(cub3d->mlx_s->mlx, 1900, 900);
// 	while (y <= 450)
// 	{
// 		x = 0;
// 		while (x <= 1900)
// 		{
// 			mlx_put_pixel(cub3d->mlx_s->img_back, x, y , color);
// 			x++;
// 		}
// 		y++;
// 	}
// 	color = cub3d->map->floor_color;
// 	while (y < 900)
// 	{
// 		x = 0;
// 		while (x <= 1900)
// 		{
// 			mlx_put_pixel(cub3d->mlx_s->img_back, x, y , color);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_back, 0, 0);
// }

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
	cub3d->mlx_s->xpm_wall = NULL;
	init_background(cub3d);
	while (x < map->width)
	{
		while (y < map->height)
		{
			if (map->map[y][x] == '1')
				ft_init_wall(x, y, cub3d->map, cub3d->mlx_s);
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
				|| map->map[y][x] == 'W' || map->map[y][x] == 'E')
				ft_init_player(x, y, cub3d->player, map);
			y++;
		}
		y = 0;
		x++;
	}
}