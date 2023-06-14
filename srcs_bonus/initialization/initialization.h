/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:38:58 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/14 01:06:04 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "../main/struct.h"
# include "../main/cub3d.h"

# define STEP 900

// initialization.c
int8_t	initialization(t_cub3d *cub3d);
int8_t	print_error(const char *message);

// init_background.c
int8_t	init_background(t_cub3d *cub3d);

// init_walls.c
int8_t	init_walls(t_cub3d *cub3d);

// init_hud_player.c
int8_t	init_hud_player(t_cub3d *cub3d);

#endif