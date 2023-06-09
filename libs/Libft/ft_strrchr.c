/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:13:49 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/03 16:35:22 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	ch;

	if (!str)
		return (NULL);
	i = 0;
	ch = c;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	while (i + 1 > 0)
	{
		if (*str == ch)
			return ((char *) str);
		str--;
		i--;
	}
	return (NULL);
}
