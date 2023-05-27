// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   colision.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/26 21:21:09 by cperron           #+#    #+#             */
// /*   Updated: 2023/05/26 21:22:29 by cperron          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "./object.h"

int	go_to_l2_a2(char *xpm, int i)
{
	while (xpm[i] != '\n')
		i++;
	while (xpm[i] != ' ')
		i++;
	i++;
	while (xpm[i] != ' ')
		i++;
	i++;
	return (i);
}

int	set_xpm_param(char *xpm, int i)
{
	int 	j;
	char 	nb[4];

	j = 0;
	while (xpm[i] != ' ')
	{
		nb[j] = xpm[i];
		i++;
		j++;
	}
	return (atoi(nb));
}

int	go_to_img()
{

}

int	pixel_color(char *xpm, int x, int y)
{
	char	color[8];
	char	code[2];
	int		nb_color;
	int		nb_char;
	int		i;

	i = go_to_l2_a2(xpm, 0);
	nb_color = set_xpm_param(xpm, i);
	while (xpm[i] != ' ')
		i++;
	i++;
	nb_char = set_xpm_param(xpm, i);
	i = go_to_img(xpm, i);
	while(nb_color + 1 > 0)
	{
		if (xpm[i] == '\n')
			nb_color--;
		i++;
	}

	return (0);
}
