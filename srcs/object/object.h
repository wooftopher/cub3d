/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:36:09 by christo           #+#    #+#             */
/*   Updated: 2023/06/20 05:36:19 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

// # include "../main/cub3d.h"
# include "../main/struct.h"
# include <math.h>
# include <stdlib.h>
# include <strings.h>

//player_move
void	ft_move(t_cub3d *cub3d);
void	ft_rotate(t_cub3d *cub3d);

#endif