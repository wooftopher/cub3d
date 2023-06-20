/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:18:15 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/19 15:19:24 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./object.h"
# include "../features/features.h"

void check_col(t_map *map, t_player *player)
{
 int x;
 int y;
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
void    calcul_new_pos(t_player *player, int x, int y)
{
    player->d_y = x * player->speed * cos(player->angle * M_PI / 180);
        // + y * player->speed * sin(player->angle * M_PI / 180);
    player->d_x = x * player->speed * sin(player->angle * M_PI / 180);
        // + y * player->speed * cos(player->angle * M_PI / 180);
}
void    set_new_pos(t_map *map, t_player *player, t_mlx_struc *mlx_s)
{
    if (player->col_x == 0)
    {
        player->pos_x += player->d_x;
        // mlx_s->img_player->instances[0].x = player->pos_x - 10;
    }
    else
        player->col_x = 0;
    if (player->col_y == 0)
    {
        player->pos_y += player->d_y;
        // mlx_s->img_player->instances[0].y = player->pos_y - 10;
    }
    else
        player->col_y = 0;
}
void    ft_move(t_cub3d *cub3d)
{
    if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_UP)
		|| mlx_is_mouse_down(cub3d->mlx_s->mlx, MLX_MOUSE_BUTTON_LEFT))
    {
        if (cub3d->player->speed < 7)
            cub3d->player->speed += 1;
        animation_racer(cub3d, FORWARD);
        // calcul_new_pos(cub3d->player, 1, 0);
        // check_col(cub3d->map, cub3d->player);
        // set_new_pos(cub3d->map, cub3d->player, cub3d->mlx_s);
    }
    if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_DOWN)
		|| mlx_is_mouse_down(cub3d->mlx_s->mlx, MLX_MOUSE_BUTTON_RIGHT))
    {
        if (cub3d->player->speed > -5)
        {
            animation_racer(cub3d, BACK);
            cub3d->player->speed -= 0.5;
        }
        // calcul_new_pos(cub3d->player, -1, 0);
        // check_col(cub3d->map, cub3d->player);
        // set_new_pos(cub3d->map, cub3d->player, cub3d->mlx_s);
    }
    // if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_A))
    // {
    //  calcul_new_pos(cub3d->player, 0, -1);
    //  check_col(cub3d->map, cub3d->player);
    //  set_new_pos(cub3d->map, cub3d->player, cub3d->mlx_s);
    // }
    // if (mlx_is_key_down(cub3d->mlx_s->mlx, MLX_KEY_D))
    // {
    //  calcul_new_pos(cub3d->player, 0, 1);
    //  check_col(cub3d->map, cub3d->player);
    //  set_new_pos(cub3d->map, cub3d->player, cub3d->mlx_s);
    // }
}
void    ft_rotate(t_cub3d *cub3d)
{
	int32_t	x;
	int32_t	y;

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
	// mlx_get_mouse_pos(cub3d->mlx_s->mlx, &x, &y);
    // if (x > 700)
	// {
	// 	animation_racer(cub3d, RIGHT);
    //     cub3d->player->angle -= (x - 700) * 0.25;
	// }
    // else if (x < 700)
	// {
	// 	animation_racer(cub3d, LEFT);
    //     cub3d->player->angle += (700 - x) * 0.25;
	// }
}
