/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:05:07 by ddemers           #+#    #+#             */
/*   Updated: 2023/05/27 16:05:07 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_processor.h"

static void	any_errors(uint8_t result, uint8_t flag)
{
	if (return_flag(&result, flag))
		printf("❗ Error ❗\n");
	else
		printf("No errors ✅ (valid)\n");
}

static void	generate_log(uint8_t result, uint8_t flag, char *message)
{
	if (return_flag(&result, flag))
		printf("%s ✅ (valid)\n", message);
	else
		printf("%s ❌\n", message);
}

void	log_handler(uint8_t result)
{
	generate_log(result, NORTH, "North texture");
	generate_log(result, SOUTH, "South texture");
	generate_log(result, WEST, "West texture");
	generate_log(result, EAST, "East texture");
	generate_log(result, FLOOR, "Floor color");
	generate_log(result, CEILING, "Ceiling color");
	generate_log(result, MAP, "Map ");
	any_errors(result, ERROR);
}
