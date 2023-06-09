/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:14:46 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/09 11:31:45 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	register unsigned char	*ptr;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	while (len-- > 0)
		*ptr++ = c;
	return (ptr);
}
