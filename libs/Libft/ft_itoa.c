/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 01:20:27 by ddemers           #+#    #+#             */
/*   Updated: 2022/10/27 01:20:27 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_conversion(char *ptr, int n, int divider)
{
	unsigned int	number;
	int				index;

	index = 0;
	if (n < 0)
	{
		number = (n * -1);
		ptr[index++] = '-';
	}
	else
		number = n;
	while (divider != 0)
	{
		ptr[index++] = (number / divider) + 48;
		number = number - (number / divider * divider);
		divider /= 10;
	}
	ptr[index] = '\0';
	return (ptr);
}

static int	ft_check_neg(int n)
{
	if (n < 0)
		return (2);
	else
		return (1);
}

static int	ft_get_divider(int digit_length)
{
	int	i;
	int	divider;

	i = (digit_length - 1);
	divider = 1;
	while (i--)
		divider *= 10;
	return (divider);
}

static int	ft_digit_length(int number)
{
	unsigned int	conversion;

	if (number < 0)
		conversion = (number * -1);
	else
		conversion = number;
	if (conversion >= 1000000000)
		return (10);
	if (conversion >= 100000000)
		return (9);
	if (conversion >= 10000000)
		return (8);
	if (conversion >= 1000000)
		return (7);
	if (conversion >= 100000)
		return (6);
	if (conversion >= 10000)
		return (5);
	if (conversion >= 1000)
		return (4);
	if (conversion >= 100)
		return (3);
	if (conversion >= 10)
		return (2);
	return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit_length;
	int		divider;

	digit_length = ft_digit_length(n);
	divider = ft_get_divider(digit_length);
	str = malloc(sizeof(char) * digit_length + ft_check_neg(n));
	if (!str)
		return (NULL);
	return (ft_conversion(str, n, divider));
}
