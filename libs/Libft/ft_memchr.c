/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:31:24 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/03 16:24:10 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	ptr = (unsigned char *) s;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		i++;
		ptr++;
	}
	return (NULL);
}
