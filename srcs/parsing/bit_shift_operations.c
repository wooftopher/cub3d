/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shift_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:10:37 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/01 03:11:03 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

bool	return_flag(uint8_t *processedFlags, uint8_t shift)
{
	return (*processedFlags & shift);
}

void	set_flag(uint8_t *processedFlags, uint8_t flag)
{
	*processedFlags |= flag;
}
