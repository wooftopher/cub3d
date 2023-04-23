/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/04/23 04:42:26 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../map/map.h"
#include "struct.h"

void	check_col(t_map *map, t_player *player)
{
	int	i;
	
	i = 0;
	while (i <= map->wall_count)
	{
		if (player->pos_x + player->d_x > map->wall_px[i] - 10
				&& player->pos_x + player->d_x < map->wall_px[i] + 110
				&& player->pos_y < map->wall_py[i] + 110
				&& player->pos_y > map->wall_py[i] - 10)
			player->col_x = 1;
		if (player->pos_y + player->d_y < map->wall_py[i] + 110
				&& player->pos_y + player->d_y > map->wall_py[i] - 10
				&& player->pos_x > map->wall_px[i] - 10
				&& player->pos_x < map->wall_px[i] + 110)
			player->col_y = 1;
		i++;
	}
}

void	calcul_new_pos(t_player *player, int d)
{
	player->d_y = d * player->speed * cos(player->angle * M_PI / 180);
	player->d_x = d * player->speed * sin(player->angle * M_PI / 180);
}

void	set_new_pos(t_player *player, t_mlx_struc *mlx)
{
	if (player->col_x == 0)
	{
		player->pos_x += player->d_x;
		mlx->img_player->instances[0].x = player->pos_x - 10;
	}
	else
		player->col_x = 0;
	if (player->col_y == 0)
	{
		player->pos_y += player->d_y;
		mlx->img_player->instances[0].y = player->pos_y - 10;
	}
	else
		player->col_y = 0;
}

void	set_direction_indicator(t_player *player, t_mlx_struc *mlx)
{
	int i;
	int	d_x;
	int	d_y;

	i = 0;
	if (mlx->img_dir_ind)
		mlx_delete_image(mlx->mlx, mlx->img_dir_ind);
	mlx->img_dir_ind = mlx_new_image(mlx->mlx, 100, 100);
	while(i < 50)
	{
		d_y = i * cos(player->angle * M_PI / 180);
		d_x = i * sin(player->angle * M_PI / 180);
		mlx_put_pixel(mlx->img_dir_ind, 50 + d_x, 50 + d_y, 226);
		i++;
	}
	mlx_image_to_window(mlx->mlx, mlx->img_dir_ind,
		player->pos_x - 50, player->pos_y - 50);
}

void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	// usleep(20000);
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_UP))
	{
		calcul_new_pos(cub3d->player, 1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player, cub3d->mlx);
		// set_direction_indicator(cub3d->player, cub3d->mlx);
	}
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_DOWN))
	{
		calcul_new_pos(cub3d->player, -1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player, cub3d->mlx);
	}
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_RIGHT))
	{
		cub3d->player->angle -= 5;
	}
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_LEFT))
	{
		cub3d->player->angle += 5;
	}
	set_direction_indicator(cub3d->player, cub3d->mlx);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(cub3d->mlx->mlx);
		free(cub3d->map->wall_px);
		free(cub3d->map->wall_py);
		free(cub3d->map->map);
		exit (0);
	}
}

int main(void)

{
    t_cub3d 	cub3d;
	t_mlx_struc mlx;
	t_map		map;
	t_player	player;
    
	cub3d.mlx = &mlx;
	cub3d.map = &map;
	cub3d.player = &player;
    ft_map_init(&cub3d);
	// cub3d.mlx = mlx_init(cub3d.map->lenght * 100, cub3d.map->height * 100, "cub3d", true);
	// if (!cub3d.mlx)
	//     perror("Error opening mlx");
	// ft_create_map(cub3d.map, &cub3d);
	// ft_pamam_init(&cub3d);
	// ft_read_map(&cub3d);
	mlx_key_hook(cub3d.mlx->mlx, key_hook, &cub3d);
	mlx_loop_hook(cub3d.mlx->mlx, ft_loop, &cub3d);
	mlx_loop(cub3d.mlx->mlx);
	return (0);
}