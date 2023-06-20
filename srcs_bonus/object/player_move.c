/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:18:15 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/20 15:30:08 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./object.h"
#include "../features/features.h"

void	check_col(t_map *map, t_player *player)
{
	int	x;
	int	y;

	if (player->d_x < 0)
		x = (player->pos_x - 50 + player->d_x) / 100;
	else
		x = (player->pos_x + 50 + player->d_x) / 100;
	y = player->pos_y / 100;
	if (map->map[y][x] == '1')
		player->col_x = 1;
	if (player->d_y < 0)
		y = (player->pos_y - 50 + player->d_y) / 100;
	else
		y = (player->pos_y + 50 + player->d_y) / 100;
	x = player->pos_x / 100;
	if (map->map[y][x] == '1')
		player->col_y = 1;
}
// void    check_col(t_map *map, t_player *player)
// {
//     int i;
//     i = 0;
//     while (i <= map->wall_count)
//     {
//         if (player->pos_x + player->d_x > map->wall_px[i] - 10
//                 && player->pos_x + player->d_x < map->wall_px[i] + 110
//                 && player->pos_y < map->wall_py[i] + 110
//                 && player->pos_y > map->wall_py[i] - 10)
//             player->col_x = 1;
//         if (player->pos_y + player->d_y < map->wall_py[i] + 110
//                 && player->pos_y + player->d_y > map->wall_py[i] - 10
//                 && player->pos_x > map->wall_px[i] - 10
//                 && player->pos_x < map->wall_px[i] + 110)
//             player->col_y = 1;
//         i++;
//     }
// }

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
		if (cub3d->player->speed < 7)
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

void	bonus_rotate(t_cub3d *cub3d)
{
	float	x;
	float	y;
	float	d;
	float	c;

	d = cub3d->player->rot_speed * M_PI / 180;
	c = sqrt(10000 - 10000 * cos(d));
	x = c * cos(d);
	y = x * tan(d);
	cub3d->player->d_y = y;
	cub3d->player->d_x = x;
}

void ft_rotate(t_cub3d *cub3d)
{
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_RIGHT))
	{
		// bonus_rotate(cub3d);
		// check_col(cub3d->map, cub3d->player);
		// set_new_pos(cub3d->map, cub3d->player, cub3d->mlx_s);
		cub3d->player->angle -= cub3d->player->rot_speed;
		animation_racer(cub3d, RIGHT);
	}
	if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_LEFT))
	{
		cub3d->player->angle += cub3d->player->rot_speed;
		animation_racer(cub3d, LEFT);
	}
}
