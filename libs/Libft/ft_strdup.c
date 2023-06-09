/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:51:25 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/03 16:33:15 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcp(char *ptr, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*ptr;

	if (!src)
		return (NULL);
	i = ft_strlen(src);
	ptr = malloc(sizeof(*ptr) * i + 1);
	if (ptr == 0)
		return (0);
	ft_strcp(ptr, src);
	return (ptr);
}
