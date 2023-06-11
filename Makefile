# Executable #
NAME = cub3d

# Compile stuff #
CC = @gcc
CFGLAGS = -Wall -Werror -Wextra
LINUX = -ldl -lglfw -pthread -lm
MAC = -I /include -lglfw -pthread -L "/Users/$(USER)/.brew/opt/glfw/lib/"

# REMOVE #
REMOVE = @rm -f

# RUN #
RUN = ./cub3d default.cub

# OBJS #
OBJS = ${SRCS:.c=.o}

# LIBS #
LIBFT = libs/Libft/libft.a
MLXM = libs/MLX/build/libmlx42.a
MLXL = libs/MLX42/build/libmlx42.a
GLFW = libs/GLFW/glfw.a
LIBS =  $(LIBFT) \
		$(MLX) \
		$(GLFW)

# OS CHECK #

OS = $(shell uname)

# Leak #

LEAK = leaks -atExit -- ./cub3d

# Source file mandatory #

MAIN =  	./srcs/main/main.c \
			./srcs/main/initialization.c \
			./srcs/main/free.c

MAP =		./srcs/map/create_map.c \
			./srcs/map/map_utils.c \
			./srcs/map/parse_map.c

OBJECT =	./srcs/object/player_move.c

RAY = 		./srcs/ray/dir_indicator.c \
			./srcs/ray/init_ray.c \
			./srcs/ray/pixel_color.c \
			./srcs/ray/ray_calcul.c \
			./srcs/ray/ray_calcul_utils.c \
			./srcs/ray/ray_hor_fov.c \
			./srcs/ray/ray_hor.c \
			./srcs/ray/ray_ver_fov.c \
			./srcs/ray/ray_ver.c

PARSING = 	./srcs/parsing/bit_shift_operations.c \
			./srcs/parsing/breadth_first_search.c \
			./srcs/parsing/breadth_first_search_neighbors.c \
			./srcs/parsing/breadth_first_search_queue.c \
			./srcs/parsing/breath_first_search_valid_func.c \
			./srcs/parsing/character_validation.c \
			./srcs/parsing/create_map_array.c \
			./srcs/parsing/fill_map_data.c \
			./srcs/parsing/ft_atoi_cube.c \
			./srcs/parsing/load_map_routine.c \
			./srcs/parsing/map_errno.c \
			./srcs/parsing/map_name_validator.c \
			./srcs/parsing/modify_map.c \
			./srcs/parsing/open_map.c \
			./srcs/parsing/parse_colors.c \
			./srcs/parsing/process_map_data.c \
			./srcs/parsing/read_map.c \
			./srcs/parsing/substr_cube.c \
			./srcs/parsing/texture_parsing.c \
			./srcs/parsing/tokenize_map.c \
			./srcs/parsing/validate_map_layout.c

SRCS =  $(MAIN) \
		$(MAP) \
		$(OBJECT) \
		$(RAY) \
		$(PARSING)

# Colors #

BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

#CHECK WHICH OS IS RUNNING TO GET THE CORRECT COMPILATION FLAG #

ifeq ($(OS), Linux)
	FLAGS = $(LINUX)
	MLX = libs/MLX/build/libmlx42L.a
else ifeq ($(OS), Darwin)
	FLAGS = $(MAC)
	MLX = libs/MLX/build/libmlx42.a
endif

all: lib $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		${CC} ${CFGLAGS} ${OBJS} ${LIBFT} $(MLX) $(FLAGS) -o ${NAME}
	@echo "$(GREEN)Done$(WHITE)"

lib:
	@make -s -C libs/Libft

clean:
	@make clean -s -C libs/Libft
	${REMOVE} ${OBJS}

fclean:clean
	@make fclean -s -C libs/Libft
	${REMOVE} ${NAME}
	@echo "$(RED)Cleaning done$(WHITE)"

re: fclean all

run: all
	${RUN}

leak: all
	${LEAK}

.PHONY: all clean fclean re lib run leak