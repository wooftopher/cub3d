/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:56:20 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:58:44 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "features_bonus.h"

int8_t	set_music_path(t_cub3d *cub3d)
{
	char	*afplay;

	afplay = ft_strjoin("afplay ", cub3d->map->music_path);
	if (!afplay)
		return (FAILURE);
	free(cub3d->map->music_path);
	cub3d->map->music_path = ft_strjoin(afplay, " &");
	free(afplay);
	if (!cub3d->map->music_path)
		return (FAILURE);
	return (SUCCESS);
}
