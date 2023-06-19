/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:18 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/19 00:33:13 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FEATURES_H
# define FEATURES_H

# include "../main/cub3d.h"

/*
	 **********************************
	 ~	      Game clock/timer        ~
	 **********************************
*/
# define INTERVAL 1
# define FIRST_DIGIT 1

void	game_clock(t_cub3d *cub3d);
/*
	 **********************************
	 ~	         Mushroom	          ~
	 **********************************
*/
# define MUSH_TIMER 3
# define SPEED_BOOST 20

void	mushroom(t_cub3d *cub3d);
/*
	 **********************************
	 ~	         Animation	          ~
	 **********************************
*/
# define FORWARD 0b00000001
# define BACK 0b00000010
# define LEFT 0b00000100
# define RIGHT 0b00001000

void	animation_racer(t_cub3d *cub3d, uint8_t flag);
/*
	 **********************************
	 ~	         End_screen	          ~
	 **********************************
*/
void	end_screen(t_cub3d *cub3d);
void	set_end_screen_transition(t_cub3d *cub3d);
/*
	 **********************************
	 ~	           Hooks  	          ~
	 **********************************
*/
void	init_hooks(t_cub3d *cub3d);
void 	key_hook(mlx_key_data_t keydata, void *param);
void	mouse_position(double xpos, double ypos, void *params);

#endif