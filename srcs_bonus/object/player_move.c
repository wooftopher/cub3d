/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:18:15 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/21 18:59:28 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object.h"
#include "../features/features.h"

void	check_col(t_cub3d *cub3d, t_map *map, t_player *player)
{
	int	x;
	int	y;

	if (player->d_x < 0)
		x = (player->pos_x - 65 + player->d_x) / 100;
	else
		x = (player->pos_x + 65 + player->d_x) / 100;
	y = player->pos_y / 100;
	if (map->map[y][x] == '1')
		player->col_x = 1;
	else if (map->map[y][x] == '2' && player->laps < player->checkpoint)
	{
		if (player->laps < 1)
			player->laps++;
		else
			end_screen(cub3d);
	}
	else if (map->map[y][x] == 'C' && player->checkpoint == player->laps)
	{
		player->checkpoint++;
		return ;
	}
	spaggetji(cub3d, x, y);
}

void	calcul_new_pos(t_player *player, int x, int y)
{
	player->d_y = x * player->speed * cos(player->angle * M_PI / 180);
	player->d_x = x * player->speed * sin(player->angle * M_PI / 180);
}

void	set_new_pos(t_map *map, t_player *player, t_mlx_struc *mlx_s)
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
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_UP))
	{
		if (cub3d->player->speed < MAX_SPEED)
			cub3d->player->speed += 1;
		animation_racer(cub3d, FORWARD);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_DOWN))
	{
		if (cub3d->player->speed > -5)
		{
			animation_racer(cub3d, BACK);
			cub3d->player->speed -= 0.5;
		}
	}
}

void	ft_rotate(t_cub3d *cub3d)
{
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_RIGHT))
	{
		cub3d->player->angle -= cub3d->player->rot_speed;
		animation_racer(cub3d, RIGHT);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_LEFT))
	{
		cub3d->player->angle += cub3d->player->rot_speed;
		animation_racer(cub3d, LEFT);
	}
}
