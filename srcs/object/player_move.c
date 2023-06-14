/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:35:04 by christo           #+#    #+#             */
/*   Updated: 2023/06/14 16:38:29 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object.h"

void	check_col(t_map *map, t_player *player)
{
	int	x;
	int	y;

	if (player->d_x < 0)
		x = (player->pos_x - 1 + player->d_x) / 100;
	else
		x = (player->pos_x + 1 + player->d_x) / 100;
	y = player->pos_y / 100;
	if (map->map[y][x] == '1')
		player->col_x = 1;
	if (player->d_y < 0)
		y = (player->pos_y - 1 + player->d_y) / 100;
	else
		y = (player->pos_y + 1 + player->d_y) / 100;
	x = player->pos_x / 100;
	if (map->map[y][x] == '1')
		player->col_y = 1;
}

void	calcul_new_pos(t_player *player, int dx, int dy)
{
	player->d_y = dx * player->speed * cos(player->angle * M_PI / 180)
		+ dy * player->speed * sin((player->angle) * M_PI / 180);
	player->d_x = dx * player->speed * sin(player->angle * M_PI / 180)
		- dy * player->speed * cos((player->angle) * M_PI / 180);
}

void	set_new_pos(t_player *player)
{ 
	if (player->col_x == 0)
		player->pos_x += player->d_x;
	else
		player->col_x = 0;
	if (player->col_y == 0)
		player->pos_y += player->d_y;
	else
		player->col_y = 0;
}

void	ft_move(t_cub3d *cub3d)
{
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_W))
	{
		calcul_new_pos(cub3d->player, 1, 0);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_S))
	{
		calcul_new_pos(cub3d->player, -1, 0);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_A))
	{
		calcul_new_pos(cub3d->player, 0, -1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_D))
	{
		calcul_new_pos(cub3d->player, 0, 1);
		check_col(cub3d->map, cub3d->player);
		set_new_pos(cub3d->player);
	}
}

void	ft_rotate(t_cub3d *cub3d)
{
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_RIGHT))
	{
		cub3d->player->angle -= cub3d->player->rot_speed;
		if (cub3d->player->angle > 360)
			cub3d->player->angle -= 360;
		if (cub3d->player->angle < 0)
			cub3d->player->angle += 360;
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_LEFT))
	{
		cub3d->player->angle += cub3d->player->rot_speed;
		if (cub3d->player->angle > 360)
			cub3d->player->angle -= 360;
		if (cub3d->player->angle < 0)
			cub3d->player->angle += 360;
	}
}