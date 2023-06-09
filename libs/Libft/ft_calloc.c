/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:31:47 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/09 11:31:31 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
