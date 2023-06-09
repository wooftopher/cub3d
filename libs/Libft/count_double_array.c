/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_double_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:21:30 by ddemers           #+#    #+#             */
/*   Updated: 2023/04/11 15:10:57 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Function that count the number of char string into the char**
Return -1 if the double pointer is NULL, else return the count*/
size_t	count_double_array(char **array)
{
	size_t	count;

	count = 0;
	if (!array)
		return (-1);
	while (array[count])
		count++;
	return (count);
}
