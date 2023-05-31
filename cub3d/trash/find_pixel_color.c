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
	bzero(nb, 4); //libft
	while (xpm[i] != ' ')
	{
		nb[j] = xpm[i];
		i++;
		j++;
	}
	return (atoi(nb));
}

int	go_to_img(char *xpm, int nb_color, int i)
{
	while(nb_color + 1 > 0)
	{
		if (xpm[i] == '\n')
			nb_color--;
		i++;
	}
	return (i);
}


int	go_to_code(char *xpm, int x, int y, int i)
{
	while (y > 0)
	{
		if (xpm[i] == '\n')
			y--;
		i++;
	}
	while (x > 0)
	{
		x--;
		i++;
	}
	return (i);
}

char *get_code(char *xpm, int i, int nb_char, char *code)
{
	int j;
	
	j = 0;
	while(nb_char > 0)
	{
		code[j] = xpm[i];
		nb_char--;
		j++;
		i++;
	}
	return (code);
}

char	*get_color(char *xpm, char *code, char *color, int nb_char)
{
	int i;
	int j;

	j = 2;
	i = go_to_l2_a2(xpm, 0);
	color[0] = '0';
	color[1] = 'x';
	while (xpm[i] != '\n')
		i++;
	i++;
	while (xpm[i])
	{
		if (strncmp(code, &xpm[i], nb_char) == 0) //libft
		{
			i += nb_char + 2;
			while (xpm[i] != '\n')
			{
				color[j] = xpm[i];
				i++;
				j++;
			}
			return (color);
		}
		else
		{
			while (xpm[i] != '\n')
				i++;
			i++;
		}
	}
	return (color);
}

uint32_t	pixel_color(t_xpm *xpm_s, int x, int y)
{
	int		nb_color;
	int		nb_char;
	int		i;
	char	code[2];
	char	color[10];

	i = go_to_l2_a2(xpm_s->wall_xpm, 0);
	nb_color = set_xpm_param(xpm_s->wall_xpm, i);
	while (xpm_s->wall_xpm[i] != ' ')
		i++;
	i++;
	nb_char = set_xpm_param(xpm_s->wall_xpm, i);
	i = go_to_img(xpm_s->wall_xpm, nb_color, i);
	i = go_to_code(xpm_s->wall_xpm, x, y, i);
	*code = *get_code(xpm_s->wall_xpm, i, nb_char, code);
	*color = *get_color(xpm_s->wall_xpm, code, color, nb_char);
	// printf("color : %s\n", xpm_cu->color);
	// printf("color  int: %lu\n", strtoul(xpm_cu->color, NULL, 16));
	return (strtoul(color, NULL, 16));
}
