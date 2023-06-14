/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:42:04 by ddemers           #+#    #+#             */
/*   Updated: 2023/06/14 16:32:43 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PROCESSOR_H
# define MAP_PROCESSOR_H

# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../main/struct.h"
# include "../../libs/Libft/libft.h"

/*
	 **********************************
	 ~	      Map size define         ~
	 **********************************
*/
# define MAX_WIDTH 100
# define MAX_HEIGHT 100
# define MIN_WIDTH 3
# define MIN_HEIGHT 3

/*
	 **********************************
	 ~	       Common defition        ~
	 **********************************
*/
# define INITIAL_BUFFER 1000
# define MAX_MAP_LENGTH 1000000
# define FAILURE -1
# define SUCCESS 0

/*
	 **********************************
	 ~	Enum lookup table for parsing ~
	 **********************************
	0000-0001 True if an error has occured
	0000-0010 True if map got initialize
	0000-0100 True if floor color was provided
	0000-1000 True if ceiling color was provided
	0001-0000 True if east texture was provided
	0010-0000 True if west texture was provided
	0001-0000 True if south texture was provided
	1000-0000 True if north texture was provided
*/
typedef enum e_map_flag
{
	NORTH =	0b10000000,
	SOUTH = 0b01000000,
	WEST = 0b00100000,
	EAST = 0b00010000,
	FLOOR = 0b00001000,
	CEILING = 0b00000100,
	MAP = 0b00000010,
	ERROR = 0b00000001,
	OK = 0b11111100
}	t_map_flag;

/*
	 **********************************
	 ~	  Map Parsing Errno define    ~
	 **********************************
*/
# ifdef __linux__
#  define OS 1
# endif

# ifdef __APPLE__
#  define OS 0
# endif

# ifndef OS
#  define OS 1
# endif

# define MAC 0

# define LINE_LENGTH 26 /* Line length for each error message */
# define FILE_BUFFER_SIZE 600 /* Max buffer for read */
# define FILE_SIZE 599 /* Max file size for the file */
# define VALIDM 0 /* Valid map */
# define INVAFL 1 /* Couldn't open file */
# define INVANA 2 /* Invalid map name */
# define EMPTYM 3 /* Empty map */
# define INVAMN 4 /* Invalid map name */
# define READFA 5 /* Read failure */
# define INVATE 6 /* Texture error */
# define INVASP 7 /* No starting position */
# define WIDOVE 8 /* Witdh too large */
# define WIDLOW 9 /* Witdh too small */
# define INVAMT 10 /* Multiple texture error */
# define INVACO 11 /* Invalid color */
# define INVAFC 12 /* Invalid ceiling color */
# define MAPCHA 13 /* Map invalid character */
# define MAPEMT 14 /* No map found */
# define ALLOCF 15 /* Out of memory */
# define INVALI 16 /* Invalid line */
# define HEIOVE 17 /* Height too large */
# define HEILOW 18 /* Height too low */
# define INVALM 19 /* Invalid map */
# define INVALP 20 /* Double starting pos */
# define INTOVE 21 /* Int overflow */
# define MULTIP 22 /* Multiple starting pos */
# define BUFFOV 23 /* Map buffer overflow */
# define EMPTYF 24 /* Empty file */

/*
	 **********************************
	 ~	  		BFS tools 		      ~
	 **********************************
*/

# define MAX_QUEUE_SIZE 100000
# define VISITED 3

typedef struct s_bfs_info
{
	int16_t	start_y;
	int16_t	start_x;
	int16_t	max_y;
	int16_t	max_x;
}	t_bfs_info;

typedef struct s_cell
{
	int16_t	x;
	int16_t	y;
}	t_cell;

typedef struct s_queue
{
	t_cell		*cell_queue;
	uint32_t	front;
	uint32_t	end;
}	t_queue;

/*
	 **********************************
	 ~	  	  String functions		  ~
	 **********************************
*/
int			atoi_cube(char *str);
char		*ft_strtok(char *str, const char *delim);
char		*substr_cube(const char *map, uint32_t start,
				size_t len, size_t max_length);
/*
	 **********************************
	 ~	  	   Map validation	      ~
	 **********************************
*/
bool		map_name_validator(const char *str);
char		*parse_texture(char *token, uint8_t *processedflags,
				uint8_t flag, t_map *map);
uint32_t	parse_colors(char *token, uint8_t *processedflags,
				uint8_t flag, t_map *map);
bool		map_token_validation(const char *token, t_map *map, uint32_t index);
void		validate_map_layout(t_map *map);
void		set_flag(uint8_t *processedFlags, uint8_t shift);
bool		return_flag(uint8_t *processedFlags, uint8_t shift);
/*
	 **********************************
	 ~	 Init, fill, modify and Free  ~
	 **********************************
*/
void		map_struct_destructor(t_map *map);
void		map_initialization(t_map *map, const char *file_name);
void		modify_map(t_map *map);
void		fill_map_data(t_map *map);
char		**create_map_array(const char *token, t_map *map);
/*
	 **********************************
	 ~	  	   Token n Read 	      ~
	 **********************************
*/
int			open_file(const char *str);
char		*read_fd(t_map *map, int fd);
char		*tokenize_map(char *token, t_map *map);
void		process_map_data(t_map *map, char *file_data);
/*
	 **********************************
	 ~	  	    Map errno		      ~
	 **********************************
*/
void		print_map_errno(uint8_t flag);
void		set_map_errno(t_map *map, uint8_t flag);
/*
	 **********************************
	 ~	  	   BFS functions 		  ~
	 **********************************
*/
bool		breadth_first_search(char **map, t_bfs_info bfs_info);
void		init_queue(t_queue *queue);
t_cell		*pop(t_queue *queue);
void		add(t_queue *queue, uint16_t y, uint16_t x, char **map);
bool		queue_is_empty(t_queue *queue);
bool		neighbors(t_queue *queue, t_cell *current, char **map,
				t_bfs_info bfs_info);
bool		is_on_edge(uint16_t y, uint16_t x, t_bfs_info info);
bool		is_visited(const char c);
bool		is_valid(const char c);
bool		is_forbidden(const char c);
bool		is_starting_point(char **map, t_cell *current);

#endif