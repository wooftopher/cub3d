/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:15:04 by cperron           #+#    #+#             */
/*   Updated: 2023/06/07 23:12:12 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ray.h"

uint32_t	get_rgba(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	return (red << 24 | green << 16 | blue << 8 | alpha);
}

int *array_witdh(uint32_t witdh, uint32_t index, mlx_texture_t *texture)
{
	int 		*array;
	uint32_t	array_index;

	array = malloc(sizeof(int) * witdh);
	if (!array)
		return (NULL);
	array_index = 0;
	while (array_index < witdh)
	{
		array[array_index] = get_rgba(texture->pixels[index], texture->pixels[index + 1], texture->pixels[index + 2], texture->pixels[index + 3]);
		index += 4;
		array_index++;
	}
	return (array);
}

int	**fill_int_array(uint32_t length, uint32_t heigth, uint32_t witdh, mlx_texture_t *texture)
{
	uint32_t	index;
	uint32_t	array_index;
	int			**array;

	array = malloc(sizeof(int *) * heigth);
	if (!array)
		return (NULL);
	index = 0;
	array_index = 0;
	while (array_index < heigth)
	{
		array[array_index] = array_witdh(witdh, index, texture);
		if (!array[array_index])
			return (NULL); // fix later
		array_index++;
		index += 4 * witdh;
	}
	return (array);
}

void	free_int_array(int **array, uint32_t heigth)
{
	uint32_t	index;

	index = 0;
	while (index < heigth)
		free(array[index++]);
	free(array);
}