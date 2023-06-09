/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:05:15 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/01 18:29:28 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_mem(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
	return (NULL);
}

static int	ft_length(char const *s, char c, int i)
{
	int	length;

	length = 0;
	while (s[i] != c && s[i])
	{
		length++;
		i++;
	}
	return (length);
}

static	char	**get_size(char const *s, char c)
{
	int		nb;
	char	**ptr;

	nb = 1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (*s && *s != c)
			s++;
		nb++;
	}
	ptr = (char **)malloc(sizeof(char *) * nb);
	if (!ptr)
		return (NULL);
	ptr[nb - 1] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		check_sep;
	int		nmbcount;

	if (!s)
		return (NULL);
	ptr = get_size(s, c);
	i = -1;
	nmbcount = 0;
	check_sep = 0;
	while (ptr && s[++i])
	{
		if (s[i] == c)
			check_sep = 0;
		if (s[i] != c && check_sep++ == 0)
		{
			ptr[nmbcount] = ft_substr(s, i, ft_length(s, c, i));
			if (ptr[nmbcount++] == NULL)
				return (ft_free_mem(ptr));
		}
	}
	return (ptr);
}
