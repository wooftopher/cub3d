/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strktok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:56:44 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/09 11:32:38 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (true);
		delim++;
	}
	return (false);
}

static char	*str_begining(char *str, const char *delim)
{
	if (!str || !delim)
		return (NULL);
	while (true)
	{
		if (is_delim(*str, delim))
		{
			str++;
			continue ;
		}
		if (!*str)
			return (NULL);
		break ;
	}
	return (str);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last_ptr;
	char		*token;

	if (str == NULL)
		str = last_ptr;
	str = str_begining(str, delim);
	if (!str)
		return (NULL);
	token = str;
	while (true)
	{
		if (!*str)
		{
			last_ptr = str;
			return (token);
		}
		if (is_delim(*str, delim))
		{
			*str = 0;
			last_ptr = str + 1;
			return (token);
		}
		str++;
	}
	return (token);
}
