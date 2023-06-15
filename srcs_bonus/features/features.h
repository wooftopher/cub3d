/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:39:18 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/15 05:27:26 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FEATURE_H
# define FEATURE_H

# include "../main/cub3d.h"

/*
	 **********************************
	 ~	      Game clock/timer        ~
	 **********************************
*/
# define INTERVAL 1.0
void	game_clock(t_cub3d *cub3d);
/*
	 **********************************
	 ~	         Mushroom	          ~
	 **********************************
*/
# define MUSH_TIMER 15
# define SPEED_BOOST 20
void	mushroom(t_cub3d *cub3d);

#endif