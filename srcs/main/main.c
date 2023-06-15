/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/06/15 03:16:47 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub3d->mlx_s->mlx);
}

void	ft_loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	ft_move(cub3d);
	ft_rotate(cub3d);
	ft_calcul_render(cub3d);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
		return (write(STDERR_FILENO, "Error argc\n", 11), EXIT_FAILURE);
	if (initialization(&cub3d, argv))
		return (free_all(&cub3d), EXIT_FAILURE);
	if (!mlx_loop_hook(cub3d.mlx_s->mlx, ft_loop, &cub3d))
		return (mlx_terminate(cub3d.mlx_s->mlx),
			write(STDERR_FILENO, "Hook Error\n", 12), EXIT_FAILURE);
	mlx_key_hook(cub3d.mlx_s->mlx, key_hook, &cub3d);
	mlx_loop(cub3d.mlx_s->mlx);
	mlx_terminate(cub3d.mlx_s->mlx);
	free_all(&cub3d);
	return (EXIT_SUCCESS);
}

// texture bug
