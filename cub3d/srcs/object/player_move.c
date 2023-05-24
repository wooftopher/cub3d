/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:35:04 by christo           #+#    #+#             */
/*   Updated: 2023/05/24 05:38:01 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./object.h"

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

void	set_new_pos(t_map *map, t_player *player, t_mlx_struc *mlx_s)
{ 
	if (player->col_x == 0)
	{
		player->pos_x += player->d_x;
		mlx_s->img_player->instances[0].x = player->pos_x - 10;
	}
	else
		player->col_x = 0;
	if (player->col_y == 0)
	{
		player->pos_y += player->d_y;
		mlx_s->img_player->instances[0].y = player->pos_y - 10;
	}
	else
		player->col_y = 0;
}

void	ft_move(t_cub3d *cub3d)
{
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_UP))
	{
		// move_minimap(cub3d->map, cub3d->player, cub3d->mlx_s, 1);
		calcul_new_pos(cub3d->player, 1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->map, cub3d->player, cub3d->mlx_s);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_DOWN))
	{
		// move_minimap(cub3d->map, cub3d->player, cub3d->mlx_s, -1);
		calcul_new_pos(cub3d->player, -1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->map, cub3d->player, cub3d->mlx_s);
	}
}

void	ft_rotate(t_cub3d *cub3d)
{
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_RIGHT))
	{
		if (cub3d->mlx_s->img_sky->instances[0].x < -6500)
			cub3d->mlx_s->img_sky->instances[0].x = 500;
		else
		cub3d->player->angle += cub3d->player->rot_speed;
			cub3d->mlx_s->img_sky->instances[0].x -= cub3d->player->rot_speed * 10;
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_LEFT))
	{
		if (cub3d->mlx_s->img_sky->instances[0].x > 500)
			cub3d->mlx_s->img_sky->instances[0].x = -6500;
		else
			cub3d->player->angle -= cub3d->player->rot_speed;
		cub3d->mlx_s->img_sky->instances[0].x += cub3d->player->rot_speed * 10;
	}
}