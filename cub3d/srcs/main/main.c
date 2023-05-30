/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:57:27 by christo           #+#    #+#             */
/*   Updated: 2023/05/30 17:45:01 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// cacul the minimum distance between
// the player and a wall with the player angle
void	calcul_ray_to_wall(t_player *player, t_map *map, t_ray *ray)
{
	int	j;
	t_ray_angle_s *ray_angle_s;
	
	ray_angle_s = calloc(1, sizeof(t_ray_angle_s));
	ray->ray_angle_s = ray_angle_s;
	j = 0;
	ray->min_dist = INT_MAX;
	if (cos(player->angle * M_PI / 180) < 0 && player->angle != 270)
		ray_hor_up(player, map, ray, j);
	else if(player->angle != 90)
		ray_hor_down(player, map, ray, j);
	if (sin(player->angle * M_PI / 180) > 0)
		ray_ver_right(player, map, ray, j);
	else
		ray_ver_left(player, map, ray, j);
}

void	calcul_ray_to_wall_fov(t_player *player, t_map *map, t_ray *ray)
{
	int	j;
	int	i;
	float fov_angle;
	t_ray_angle_s *ray_angle_fov_s[1500];
	
	// ray_angle_fov_s = calloc(1500, sizeof(t_ray_angle_fov_s));
	i = 0;
	while (i <= 1400)
	{
		ray_angle_fov_s[i] = calloc(1, sizeof(t_ray_angle_fov_s)); //libtf
		i++;
	}
	j = 0;
	ray->angle_count = 0;
	fov_angle = -ray->fov_angle;
	ray->angle = player->angle - ray->fov_angle;
	while(fov_angle <= ray->fov_angle)
	{
		ray->ray_angle_fov_s[ray->angle_count] = ray_angle_fov_s[ray->angle_count];
		ray->min_dist_fov[ray->angle_count] = INT_MAX;
		if (cos(ray->angle * M_PI / 180) < 0 && ray->angle != 270)
			ray_hor_up_fov(player, map, ray, j);
		else if(ray->angle != 90)
			ray_hor_down_fov(player, map, ray, j);
		if (sin(ray->angle * M_PI / 180) > 0)
			ray_ver_right_fov(player, map, ray, j);
		else
			ray_ver_left_fov(player, map, ray, j);
		ray->angle += ray->angle_div;
		fov_angle += ray->angle_div;
		ray->angle_count++;
	}
}

void ft_render(t_ray *ray, t_mlx_struc *mlx)
{
	int	i;
	float	wall_height;
	
	wall_height = 4000 / ray->min_dist;
	if (mlx->img_wall_3d)
		mlx_delete_image(mlx->mlx, mlx->img_wall_3d);
	mlx->img_wall_3d = mlx_new_image(mlx->mlx, 1900, 900);
	i = -wall_height;
	while (i < wall_height)
	{
		mlx_put_pixel(mlx->img_wall_3d, 950, 450 + i, 0xFFFFFF);
		i++;
	}
	mlx_image_to_window(mlx->mlx, mlx->img_wall_3d, 0, 0);
}

// int	find_pixel_color()
// {
	
// }

int	find_y(int i, int wall_h)
{
	// int	y;
	// int range;
	// float	a_pos;
	// float	n_pos;
	
	// range = wall_h / 2;
	// a_pos = ((float)range / i);
	// // n_pos = a_pos + 0.5;
	// y = round(n_pos * 10);
	// return(abs(y));

    double normalized_position;
    int y_pixel_pos;

    if (i < 0) {
        normalized_position = (double)i / -wall_h;
        y_pixel_pos = (int) round((normalized_position + 1.0) * 5);
    } else {
        normalized_position = (double)i / wall_h;
        y_pixel_pos = 5 - (int) round(normalized_position * 4);
    }

    return (y_pixel_pos - 1);
}


void ft_render_fov(t_cub3d * cub3d, t_player *player, t_ray *ray, t_mlx_struc *mlx)
{
	int	i;
	float j;
	int k;
	int	wall_height;
	int	y;
	
	k = 0;
	j = -ray->fov_angle;
	// if (mlx->img_wall_3d)
	// 	mlx_delete_image(mlx->mlx, mlx->img_wall_3d);
	// mlx->img_wall_3d = mlx_new_image(mlx->mlx, 1900, 1000);
	while (j < ray->angle_count - ray->fov_angle)
	{
		// wall_height = 50000 / ray->min_dist_fov[k];
		wall_height = 50000 / ray->ray_angle_fov_s[k]->min_dist_fov;
		i = -wall_height;
		if (i < -450)
			i = -450;
		while (i < floor(wall_height) && i < 450)
		{
			y = find_y(i, wall_height);
			// mlx_put_pixel(mlx->img_wall_3d, k + 500, 450 + i,
			// 	pixel_color(cub3d->xpm_s, (cub3d->ray->ray_angle_fov_s[k]->pos_on_texture / 10) ,
			// 		y));
			mlx_put_pixel(mlx->img_wall_3d, k + 500, 450 + i, 0xFEFEFEFF);
			i++;
		}
		k++;
		j++;
	}
	// mlx_image_to_window(mlx->mlx, mlx->img_dir_ind,
	// 	player->pos_x - 500, player->pos_y - 500);
	mlx_image_to_window(mlx->mlx, mlx->img_wall_3d, 0, 0);
}

void ft_loop(void *param)
{
	t_cub3d *cub3d = param;

	ft_move(cub3d);
	ft_rotate(cub3d);
	if (cub3d->tic == 60)
	{
	// // 	calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
	// printf("cos(player->angle * M_PI / 180); %f\n", cos(cub3d->player->angle * M_PI / 180));
	// printf("pos: %d\n", cub3d->ray->ray_angle_s->pos_on_texture);
	// printf("pos: %d\n", cub3d->ray->ray_angle_fov_s[700]->pos_on_texture);
	// printf("ori: %d\n", cub3d->ray->ray_angle_fov_s[700]->orientation);
		// pixel_color(cub3d->xpm_s, 0 , 0);
		cub3d->tic = 0;
	}
	if (cub3d->vision == 1)
	{
		calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator(cub3d->player, cub3d->mlx_s);
	}
	// if (cub3d->vision == 2)
	// {
		calcul_ray_to_wall(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator_2(cub3d->player, cub3d->mlx_s, cub3d->ray);
	// }
	if (cub3d->vision == 3)
	{
		calcul_ray_to_wall_fov(cub3d->player,cub3d->map, cub3d->ray);
		set_direction_indicator_3(cub3d->player, cub3d->mlx_s, cub3d->ray);
	}
	if (cub3d->vision == 4)
	{
		calcul_ray_to_wall_fov(cub3d->player,cub3d->map, cub3d->ray);
		ft_render_fov(cub3d, cub3d->player, cub3d->ray, cub3d->mlx_s);
	}
	// ft_render(cub3d->ray, cub3d->mlx);
	cub3d->tic++;
}

void key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub3d *cub3d = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(cub3d->mlx_s->mlx);
		free(cub3d->map->wall_px);
		free(cub3d->map->wall_py);
		free(cub3d->map->map);
		// free(cub3d->xpm_s->code);
		// free(cub3d->xpm_s->color);
		exit (0);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		usleep(10);
		// calcul_ray_to_object_hor(cub3d->player,cub3d->map, cub3d->ray);
	}
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		cub3d->vision = 1;
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		cub3d->vision = 2;
	if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
		cub3d->vision = 3;
	if (keydata.key == MLX_KEY_4 && keydata.action == MLX_PRESS)
		cub3d->vision = 4;
}

// void	init_xpm(t_cub3d *cub3d)
// {
// 	cub3d->xpm_s->code = calloc(5, sizeof(char));
// 	cub3d->xpm_s->color = calloc(11, sizeof(char));
// }

int main(void)
{
    t_cub3d 	cub3d;
	t_mlx_struc mlx_s;
	t_map		map;
	t_player	player;
	t_ray		ray;

	int32_t width;
	int32_t height;
    
	cub3d.mlx_s = &mlx_s;
	cub3d.map = &map;
	cub3d.player = &player;
	cub3d.ray = &ray;
	cub3d.ray->fov_angle = 30;
	// cub3d.ray->angle_div = 0.035714f;
	cub3d.ray->angle_div = 0.042857f;
	cub3d.tic = 0;
	cub3d.vision = 4;
    ft_map_init(&cub3d);
	// cub3d.mlx->mlx = mlx_init(cub3d.map->lenght * 100, cub3d.map->height * 100, "cub3d", true);
	cub3d.mlx_s->mlx = mlx_init(1900, 900, "cub3d", true);
	
	// mlx_texture_t* texture = mlx_load_png("./img/duck.png");
	// mlx_image_t* img = mlx_texture_to_image(mlx_s.mlx, texture);
	// mlx_image_to_window(mlx_s.mlx, img, 0, 0);
       
	ft_create_map(cub3d.map, &cub3d);
	// ft_minimap_init(cub3d.map);
	mlx_key_hook(cub3d.mlx_s->mlx, key_hook, &cub3d);
	mlx_loop_hook(cub3d.mlx_s->mlx, ft_loop, &cub3d);
	mlx_loop(cub3d.mlx_s->mlx);
	return (0);
}
