/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:18:15 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 13:39:52 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object_bonus.h"
#include "../features/features_bonus.h"

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
			lap(cub3d);
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

void	calcul_new_pos(t_player *player, int x)
{
	player->d_y = x * player->speed * cos(player->angle * M_PI / 180);
	player->d_x = x * player->speed * sin(player->angle * M_PI / 180);
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
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_W))
	{
		if (cub3d->player->speed < MAX_SPEED)
			cub3d->player->speed += 1;
		animation_racer(cub3d, FORWARD);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_S))
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
	int	d;

	d = cub3d->tig;
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_D))
	{
		cub3d->player->angle -= d * cub3d->player->rot_speed;
		animation_racer(cub3d, RIGHT);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_A))
	{
		cub3d->player->angle += d * cub3d->player->rot_speed;
		animation_racer(cub3d, LEFT);
	}
}
