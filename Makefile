# Executable #
NAME = cub3d
NAME_BONUS = cub3d_bonus

# Compile stuff #
CC = @gcc
CFGLAGS = -Wall -Werror -Wextra
LINUX = -ldl -lglfw -pthread -lm
MAC = -I /include -L./libs/z/lib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# REMOVE #
REMOVE = @rm -f

# RUN #
RUN = ./cub3d ./map/fuck.cub
RUNB = ./cub3d_bonus

# OBJS #
OBJS = ${SRCS:.c=.o}

# OBJS BONUS #
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

# LIBS #
LIBFT = libs/Libft/libft.a
MLXM = libs/MLX/build/libmlx42.a
MLXL = libs/MLX42/build/libmlx42.a
GLFW = libs/GLFW/lib-x86_64/libglfw3.a
LIBS =  $(LIBFT) \
		$(MLX) \
		$(GLFW)

# OS CHECK #
OS = $(shell uname)

# Leak #
LEAK = leaks -atExit -- ./cub3d
LEAKB = leaks -atExit -- ./cub3d_bonus

# Source file mandatory #
MAIN =  	./srcs/main/main.c \
			./srcs/main/free.c

INITIALIZATION = 	./srcs/initialization/initialization.c \
					./srcs/initialization/create_map.c

OBJECT =	./srcs/object/player_move.c

RAY =		./srcs/ray/init_ray.c \
			./srcs/ray/pixel_color.c \
			./srcs/ray/ray_calcul.c \
			./srcs/ray/ray_calcul_utils.c \
			./srcs/ray/ray_hor_fov.c \
			./srcs/ray/ray_ver_fov.c

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
		$(INITIALIZATION) \
		$(OBJECT) \
		$(RAY) \
		$(PARSING)

# SRCS FILE BONUS #
MAINB =  	./srcs_bonus/main/main.c \
			./srcs_bonus/main/initialization.c \
			./srcs_bonus/main/free.c

MAPB =		./srcs_bonus/map/create_map.c \
			./srcs_bonus/map/map_utils.c \
			./srcs_bonus/map/parse_map.c \
			./srcs_bonus/map/gradient.c

OBJECTB =	./srcs_bonus/object/player_move.c

RAYB = 		./srcs_bonus/ray/dir_indicator.c \
			./srcs_bonus/ray/init_ray.c \
			./srcs_bonus/ray/pixel_color.c \
			./srcs_bonus/ray/ray_calcul.c \
			./srcs_bonus/ray/ray_calcul_utils.c \
			./srcs_bonus/ray/ray_hor_fov.c \
			./srcs_bonus/ray/ray_hor.c \
			./srcs_bonus/ray/ray_ver_fov.c \
			./srcs_bonus/ray/ray_ver.c

PARSINGB = 	./srcs_bonus/parsing/bit_shift_operations.c \
			./srcs_bonus/parsing/breadth_first_search.c \
			./srcs_bonus/parsing/breadth_first_search_neighbors.c \
			./srcs_bonus/parsing/breadth_first_search_queue.c \
			./srcs_bonus/parsing/breath_first_search_valid_func.c \
			./srcs_bonus/parsing/character_validation.c \
			./srcs_bonus/parsing/create_map_array.c \
			./srcs_bonus/parsing/fill_map_data.c \
			./srcs_bonus/parsing/ft_atoi_cube.c \
			./srcs_bonus/parsing/load_map_routine.c \
			./srcs_bonus/parsing/map_errno.c \
			./srcs_bonus/parsing/map_name_validator.c \
			./srcs_bonus/parsing/modify_map.c \
			./srcs_bonus/parsing/open_map.c \
			./srcs_bonus/parsing/parse_colors.c \
			./srcs_bonus/parsing/process_map_data.c \
			./srcs_bonus/parsing/read_map.c \
			./srcs_bonus/parsing/substr_cube.c \
			./srcs_bonus/parsing/texture_parsing.c \
			./srcs_bonus/parsing/tokenize_map.c \
			./srcs_bonus/parsing/validate_map_layout.c

SRCS_BONUS =  $(MAINB) \
		$(MAPB) \
		$(OBJECTB) \
		$(RAYB) \
		$(PARSINGB)

# Colors #
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# CHECK WHICH OS IS RUNNING TO GET THE CORRECT COMPILATION FLAG #
ifeq ($(OS), Linux)
	FLAGS = $(LINUX)
	MLX = libs/MLX/build/libmlx42L.a
else ifeq ($(OS), Darwin)
	FLAGS = $(MAC)
	MLX = libs/MLX/build/libmlx42.a
endif

all: lib $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		${CC} ${CFGLAGS} ${SRC} ${OBJS} ${LIBFT} $(MLX) $(GLFW) $(FLAGS) -o ${NAME}
	@echo "$(GREEN)Done$(WHITE)"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	${CC} ${CFGLAGS} ${OBJS_BONUS} ${LIBFT} $(MLX) $(GLFW) $(FLAGS) -o ${NAME_BONUS}
	@echo "$(GREEN)Bonus done!$(WHITE)"

lib:
	@make -s -C libs/Libft

clean:
	@make clean -s -C libs/Libft
	${REMOVE} ${OBJS} 
	${REMOVE} ${OBJS_BONUS}

fclean:clean
	@make fclean -s -C libs/Libft
	${REMOVE} ${NAME} ${NAME_BONUS}
	@echo "$(RED)Cleaning done$(WHITE)"

re: fclean all

reb: fclean lib $(NAME_BONUS)

bonus: lib $(NAME_BONUS)

run: all
	${RUN}

runb: lib $(NAME_BONUS)
	${RUNB}

leak: all
	${LEAK}

leakb: lib $(NAME_BONUS)
	${LEAKB}

.PHONY: all clean fclean re lib run leak bonus reb runb leakb