/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:35:04 by christo           #+#    #+#             */
/*   Updated: 2023/05/01 22:23:22 by christo          ###   ########.fr       */
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

void	set_new_pos(t_player *player, t_mlx_struc *mlx_s)
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
		calcul_new_pos(cub3d->player, 1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player, cub3d->mlx_s);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_DOWN))
	{
		calcul_new_pos(cub3d->player, -1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player, cub3d->mlx_s);
	}
}

void	ft_rotate(t_cub3d *cub3d)
{
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_RIGHT))
	{
		cub3d->player->angle += cub3d->player->rot_speed;
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_LEFT))
	{
		cub3d->player->angle -= cub3d->player->rot_speed;
	}
}