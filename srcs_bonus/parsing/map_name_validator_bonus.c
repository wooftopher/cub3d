/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_validator_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:17:09 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/22 12:57:23 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

bool	map_name_validator(const char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (false);
	while (str[index])
		index++;
	if (index < 4 || ft_strcmp((str + (index - 4)), ".cub"))
		return (false);
	return (true);
}
