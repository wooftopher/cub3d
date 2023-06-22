/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:36:09 by christo           #+#    #+#             */
/*   Updated: 2023/06/22 13:00:13 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_BONUS_H
# define OBJECT_BONUS_H

# include "../main/struct_bonus.h"
# include <math.h>
# include <stdlib.h>
# include <strings.h>

//player_move
void	ft_move(t_cub3d *cub3d);
void	ft_rotate(t_cub3d *cub3d);
void	check_col(t_cub3d *cub3d, t_map *map, t_player *player);
void	calcul_new_pos(t_player *player, int x);
void	set_new_pos(t_player *player);
void	spaggetji(t_cub3d *cub3d, int x, int y);

#endif