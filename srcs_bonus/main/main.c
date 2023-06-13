/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/06/12 22:10:14 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub3d->mlx_s->mlx);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		usleep(10);
	}
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		cub3d->vision = 1;
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		cub3d->vision = 2;
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
		cub3d->vision = 3;
	if (keydata.key == MLX_KEY_4 && keydata.action == MLX_PRESS)
		cub3d->vision = 4;
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		cub3d->focus = true;
}

#include <time.h>

void fps_counter(t_cub3d *cub3d)
{
    static clock_t	start_time = 0;
    static uint32_t	frame_count = 0;
	clock_t			current_time;
	double			elapsed_time;

	frame_count++;
	current_time = clock();
	elapsed_time = (current_time - start_time) / CLOCKS_PER_SEC;
    if (elapsed_time >= 1.0)
    {
		printf("\rFps:%.0f", frame_count - elapsed_time);
		fflush(stdout);
		frame_count = 0;
		start_time = current_time;
    }
}

void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	ft_move(cub3d);
	ft_rotate(cub3d);
	ft_calcul_render(cub3d);
	mlx_set_mouse_pos(cub3d->mlx_s->mlx, 700, 450);
	fps_counter(cub3d);
}

void mouse_position(double xpos, double ypos, void *params)
{
    t_cub3d *cub3d;

    cub3d = params;
    if (xpos > 500)
        cub3d->player->angle -= (xpos - 700) * 0.25;
    else
        cub3d->player->angle += (700 - xpos) * 0.25;;
}


int main(void)
{
    t_cub3d 	cub3d;

	if (initialization(&cub3d))
		return (free_all(&cub3d), EXIT_FAILURE);
	ft_create_map(cub3d.map, &cub3d);
	mlx_set_cursor_mode(cub3d.mlx_s->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(cub3d.mlx_s->mlx, ft_loop, &cub3d);
	mlx_key_hook(cub3d.mlx_s->mlx, key_hook, &cub3d);
	mlx_cursor_hook(cub3d.mlx_s->mlx, &mouse_position, &cub3d);
	mlx_loop(cub3d.mlx_s->mlx);
	mlx_terminate(cub3d.mlx_s->mlx);
	free_all(&cub3d);
	return (EXIT_SUCCESS);
}

// big fat map
// texture bug