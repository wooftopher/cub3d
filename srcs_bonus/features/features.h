/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:18 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/16 00:15:14 by ddemers          ###   ########.fr       */
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

void	game_clock(t_cub3d *cub3d);
/*
	 **********************************
	 ~	         Mushroom	          ~
	 **********************************
*/
# define MUSH_TIMER 10
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

#endif