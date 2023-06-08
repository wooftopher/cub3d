/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:46:34 by cperron           #+#    #+#             */
/*   Updated: 2023/06/07 23:40:54 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	init_background(t_cub3d *cub3d)
// {
	
// 	cub3d->mlx_s->txt_sky = mlx_load_png("./img/sky2.png");
// 	cub3d->mlx_s->img_sky = mlx_texture_to_image(cub3d->mlx_s->mlx, cub3d->mlx_s->txt_sky);
// 	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_sky, 500, 0);
// 	cub3d->mlx_s->txt_floor = mlx_load_png("./img/floor.png");
// 	cub3d->mlx_s->img_floor = mlx_texture_to_image(cub3d->mlx_s->mlx, cub3d->mlx_s->txt_floor);
// 	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_floor, 500, 450);
// 	cub3d->mlx_s->txt_img = mlx_load_png("./img/warluigi.png");
// 	cub3d->mlx_s->img_img = mlx_texture_to_image(cub3d->mlx_s->mlx, cub3d->mlx_s->txt_img);
// 	mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_img, 0, 500);
// 	// mlx_image_to_window(cub3d->mlx_s->mlx, cub3d->mlx_s->img_img, 0, 0);
// }

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

// int	ft_init_player(int x, int y, t_player *player, t_mlx_struc *mlx_s)
// {
// 	player->pos_x = x * 100 + 50;
// 	player->pos_y = y * 100 + 50;
// 	player->angle = 180;
// 	player->rot_speed = 4;
// 	player->speed = 5;
// 	player->col_x = 0;
// 	player->col_y = 0;
// 	mlx_s->xpm_player = mlx_load_xpm42("./img/eye.xpm42");
// 	printf ("text : %d", &mlx_s->xpm_player->texture);
// 	mlx_s->img_player = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_player->texture);
// 	mlx_delete_xpm42(mlx_s->xpm_player);
// 	mlx_image_to_window(mlx_s->mlx, mlx_s->img_player,
// 		player->pos_x - 10, player->pos_y - 10);
// 	if (!mlx_s->text_eye)
// 	    mlx_s->xpm_wall = mlx_load_png("./img/wall.png");
// 	mlx_s->img_wall
//         = mlx_texture_to_image(mlx_s->mlx, &mlx_s->xpm_wall->texture);
// 	mlx_image_to_window(mlx_s->mlx, mlx_s->img_wall, x * 50, y * 50);
// 	return (0);
// }

// void	ft_rotate(t_cub3d *cub3d)
// {
// 	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_RIGHT))
// 	{
// 		// if (cub3d->mlx_s->img_sky->instances[0].x < -6500)
// 		// 	cub3d->mlx_s->img_sky->instances[0].x = 500;
// 		// else
// 			cub3d->player->angle -= cub3d->player->rot_speed;
// 		// cub3d->mlx_s->img_sky->instances[0].x -= cub3d->player->rot_speed * 10;
// 	}
// 	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_LEFT))
// 	{
// 		// if (cub3d->mlx_s->img_sky->instances[0].x > 500)
// 		// 	cub3d->mlx_s->img_sky->instances[0].x = -6500;
// 		// else
// 			cub3d->player->angle += cub3d->player->rot_speed;
// 		// cub3d->mlx_s->img_sky->instances[0].x += cub3d->player->rot_speed * 10;
// 	}
// }

// void	move_minimap(t_map *map, t_player *player, t_mlx_struc *mlx_s, int d)
// {
// 	int i;

// 	i = 0;
// 	while (i < map->wall_count)
// 	{
// 		mlx_s->img_wall[i]->instances[0].y = mlx_s->img_wall[i]->instances[0].y 
// 			- d * floor(2 * cos((player->angle) * M_PI / 180));
// 		mlx_s->img_wall[i]->instances[0].x = mlx_s->img_wall[i]->instances[0].x
// 			- d * floor(2 * sin((player->angle) * M_PI / 180));
// 		i++;
// 	}
// }