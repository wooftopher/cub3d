/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:47:57 by ddemers           #+#    #+#             */
/*   Updated: 2023/04/10 09:59:35 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_double_array(char **array)
{
	int	index;

	index = 0;
	if (!array)
		return (NULL);
	while (array[index])
		free(array[index++]);
	free (array);
	return (NULL);
}
