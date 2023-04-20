/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/04/20 02:44:31 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../map/map.h"
#include "struct.h"

int	check_col_top(t_map *map, t_player *player)
{
	int	i;
	
	i = 0;
	while (i <= map->wall_count)
	{
		if ( player->pos_x + player->speed_x > map->wall_px[i] - 10
				&& player->pos_x + player->speed_x < map->wall_px[i] + 110
				&& player->pos_y + player->speed_y < map->wall_py[i] + 110
				&& player->pos_y + player->speed_y > map->wall_py[i] - 10)
	
			return (1);
		i++;
	}
	return (0);
}

void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_UP))
	{
		cub3d->player->speed_y = -5;
		if (!check_col_top(cub3d->map, cub3d->player))
			cub3d->mlx->img_player->instances[0].y += cub3d->player->speed_y;
		cub3d->player->pos_y = cub3d->mlx->img_player->instances[0].y + 10;
		cub3d->player->speed_y = 0;
	}
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_DOWN))
	{
		cub3d->player->speed_y = 5;
		if (!check_col_top(cub3d->map, cub3d->player))
			cub3d->mlx->img_player->instances[0].y += cub3d->player->speed_y;
		cub3d->player->pos_y = cub3d->mlx->img_player->instances[0].y + 10;
		cub3d->player->speed_y = 0;
	}
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_RIGHT))
	{
		cub3d->player->speed_x = 5;
		if (!check_col_top(cub3d->map, cub3d->player))
			cub3d->mlx->img_player->instances[0].x += 5;
		cub3d->player->pos_x = cub3d->mlx->img_player->instances[0].x + 10;
		cub3d->player->speed_x = 0;
	}
	if (mlx_is_key_down(cub3d->mlx->mlx, MLX_KEY_LEFT))
	{
		cub3d->player->speed_x = -5;
		if (!check_col_top(cub3d->map, cub3d->player))
			cub3d->mlx->img_player->instances[0].x -= 5;
		cub3d->player->pos_x = cub3d->mlx->img_player->instances[0].x + 10;
		cub3d->player->speed_x = 0;
	}
	// ft_set_p_hitbox(cub3d);


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