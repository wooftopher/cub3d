/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:10:35 by ddemers           #+#    #+#             */
/*   Updated: 2023/04/11 15:09:42 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	index;

	if (!dest)
		return (NULL);
	index = 0;
	while (index < n && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
		dest[index++] = '\0';
	return (dest);
}
