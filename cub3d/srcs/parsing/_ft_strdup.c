/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:47:37 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/05 01:47:37 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

char	*ft_strdup(char *src)
{
	size_t	length;
	int		index;
	char	*ptr;

	if (!src)
		return (NULL);
	index = 0;
	length = ft_strlen(src);
	ptr = malloc((sizeof(char) * length) + 1);
	if (!ptr)
		return (NULL);
	while (src[index])
	{
		ptr[index] = src[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
