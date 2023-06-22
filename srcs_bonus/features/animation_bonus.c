/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:54:27 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:59:04 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features_bonus.h"

void	animation_racer(t_cub3d *cub3d, uint8_t flag)
{
	cub3d->racer->forward->enabled = flag & FORWARD;
	cub3d->racer->back->enabled = flag & BACK;
	cub3d->racer->left->enabled = flag & LEFT;
	cub3d->racer->right->enabled = flag & RIGHT;
}
