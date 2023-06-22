/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 00:07:36 by ddemers           #+#    #+#             */
/*   Updated: 2023/05/28 00:07:36 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor_bonus.h"

int	atoi_cube(char *str)
{
	int	index;
	int	result;
	int	length;

	if (!str)
		return (-1);
	length = 0;
	while (ft_isdigit(str[length]))
		length++;
	if (length > 3 || length == 0)
		return (-1);
	if (str[length] != ',' && str[length] != '\0')
		return (-1);
	index = 0;
	result = 0;
	while (ft_isdigit(str[index]))
		result = result * 10 + (str[index++] - 48);
	return (result);
}
