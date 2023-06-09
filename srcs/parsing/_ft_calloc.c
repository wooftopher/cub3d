/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:28:44 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/04 20:28:44 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

static void	*ft_memset(void *s, int c, size_t len)
{
	register unsigned char	*ptr;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	while (len-- > 0)
		*ptr++ = c;
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	register void	*ptr;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = malloc(nmemb * size);
	ft_memset(ptr, 0, (nmemb * size));
	return ((void *)ptr);
}
