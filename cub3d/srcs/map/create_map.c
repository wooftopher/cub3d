/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:51:00 by christo           #+#    #+#             */
/*   Updated: 2023/05/30 17:43:58 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./map.h"
// # include "../main/struct.h"

int ft_init_wall(int x, int y, t_map *map, t_mlx_struc *mlx_s)
{
    static int wall_count;

	map->wall_px[wall_count] = x * 100;
	map->wall_py[wall_count] = y * 100;
    if (!mlx_s->xpm_wall)
	    mlx_s->xpm_wall = mlx_load_xpm42("./img/0.xpm42");
	mlx_s->img_wall
        = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_wall->texture);
	mlx_image_to_window(mlx_s->mlx, mlx_s->img_wall, x * 100, y * 100);
	wall_count++;
	return (0);
}

int	ft_init_player(int x, int y, t_player *player, t_mlx_struc *mlx_s)
{
	player->pos_x = x * 100 + 50;
	player->pos_y = y * 100 + 50;
	player->angle = 180;
	player->rot_speed = 4;
	player->speed = 5;
	player->col_x = 0;
	player->col_y = 0;
	mlx_s->xpm_player = mlx_load_xpm42("./img/eye.xpm42");
	mlx_s->img_player = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_player->texture);
	mlx_delete_xpm42(mlx_s->xpm_player);
	mlx_image_to_window(mlx_s->mlx, mlx_s->img_player,
		player->pos_x - 10, player->pos_y - 10);
	// if (!mlx_s->text_eye)
	//     mlx_s->xpm_wall = mlx_load_png("./img/wall.png");
	// mlx_s->img_wall
    //     = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_wall->texture);
	// mlx_image_to_window(mlx_s->mlx, mlx_s->img_wall, x * 50, y * 50);
	return (0);
}

// void	init_minimap(int x, int y, t_map *map, t_mlx_struc *mlx_s)
// {
// 	static int i;

// 	// while (i < map->wall_count)
// 	// {
// 		if (!mlx_s->text_wall)
// 			mlx_s->text_wall = mlx_load_png("./img/wall.png");
// 		mlx_s->img_wall[i]
// 			= mlx_texture_to_image(mlx_s->mlx, mlx_s->text_wall);
// 		mlx_image_to_window(mlx_s->mlx, mlx_s->img_wall[i], x * 50, y * 50);
// 		i++;
// 	// }
// }

void	init_background(t_cub3d *cub3d)
{
	
	cub3d->mlx_s->txt_sky = mlx_load_png("./img/sky2.png");
	cub3d->mlx_s->img_sky = mlx_texture_to_image(cub3d->mlx_s->mlx, cub3d->mlx_s->txt_sky);
	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_sky, 500, 0);
	cub3d->mlx_s->txt_floor = mlx_load_png("./img/floor.png");
	cub3d->mlx_s->img_floor = mlx_texture_to_image(cub3d->mlx_s->mlx, cub3d->mlx_s->txt_floor);
	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_floor, 500, 450);
	cub3d->mlx_s->txt_img = mlx_load_png("./img/warluigi.png");
	cub3d->mlx_s->img_img = mlx_texture_to_image(cub3d->mlx_s->mlx, cub3d->mlx_s->txt_img);
	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_img, 0, 500);
	// mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_img, 0, 0);
}

char	*read_wall_xpm(t_cub3d *cub3d)
{
	char 	buffer[1024];
    size_t	num_read;
    int		offset;
	int		fd;
	char 	*xpm; //trop variable
	
	fd = open("img/test1.xpm42", O_RDONLY);
    if (fd == -1)
		fd_error(cub3d, fd);
	//read until EOF
    xpm = malloc(1024 * sizeof(char));
	offset = 0;
	num_read = 0;
    while ((num_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
        memcpy(xpm + offset, buffer, num_read); // libft
        offset += num_read;
	}
	close(fd);
	return (xpm);
}

void	ft_create_map(t_map *map, t_cub3d *cub3d)
{
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	cub3d->mlx_s->xpm_wall = NULL;
	init_background(cub3d);
	cub3d->xpm_s->wall_xpm = read_wall_xpm(cub3d);
	// printf("xpm : %s\n", map->wall_xpm);
	while (x < map->lenght)
	{
		while (y < map->height)
		{
			if (map->map[y][x] == '1')
			{
				ft_init_wall(x, y, cub3d->map, cub3d->mlx_s);
				// init_minimap(x, y, cub3d->map, cub3d->mlx_s);
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