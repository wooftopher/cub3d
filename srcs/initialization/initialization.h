/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:14:01 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/14 16:36:20 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "../main/cub3d.h"

int8_t	ft_create_map(t_map *map, t_cub3d *cub3d);
int8_t	initialization(t_cub3d *cub3d, char **argv);

#endif