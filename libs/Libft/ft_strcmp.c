/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:45:38 by ddemers           #+#    #+#             */
/*   Updated: 2023/04/11 15:13:17 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Custom strcmp for minishell, return -1 if any of the string are null.
Return 0 if s2 is found in s1, if it isn't return 1*/
int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}
