# Executables #
NAME = cub3d
NAME_BONUS = cub3d_bonus

# Compile stuff #
CC = @gcc
CFGLAGS = -Wall -Werror -Wextra
LINUX = -ldl -lglfw -pthread -lm
MAC = -I /include -lglfw -pthread -L "/Users/$(USER)/.brew/opt/glfw/lib/"

# REMOVE #
REMOVE = @rm -f

# RUN #
RUN = ./cub3d ./map/merio64.cub
RUNB = ./cub3d_bonus ./map/race1.cub

# OBJS #
OBJS = ${SRCS:.c=.o}

# OBJS BONUS #
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

# LIBS #
LIBFT = libs/Libft/libft.a
MLX = libs/MLX42/build/libmlx42.a
LIBS =  $(LIBFT) \
		$(MLX) \
		$(GLFW)

# OS CHECK #
OS = $(shell uname)

# Leak #
LEAK = leaks -atExit -- ./cub3d ./map/optic.cub
LEAKB = leaks -atExit -- ./cub3d_bonus ./map/bonus/merio64.cub

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
			./srcs_bonus/main/free.c

INITIALIZATIONB =	./srcs_bonus/initialization/initialization.c \
					./srcs_bonus/initialization/init_background.c \
					./srcs_bonus/initialization/init_walls.c \
					./srcs_bonus/initialization/init_hud_player.c \
					./srcs_bonus/initialization/init_timer.c \
					./srcs_bonus/initialization/create_map.c \
					./srcs_bonus/initialization/init_timer_digit.c \
					./srcs_bonus/initialization/init_end_screen.c \
					./srcs_bonus/initialization/init_countdown.c \
					./srcs_bonus/initialization/init_end.c \
					./srcs_bonus/initialization/init_lap.c

OBJECTB =	./srcs_bonus/object/player_move.c

RAYB = 		./srcs_bonus/ray/pixel_color.c \
			./srcs_bonus/ray/ray_calcul.c \
			./srcs_bonus/ray/ray_calcul_utils_1.c \
			./srcs_bonus/ray/ray_calcul_utils_2.c \
			./srcs_bonus/ray/ray_hor_fov.c \
			./srcs_bonus/ray/ray_ver_fov.c 

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

FEATURES =	./srcs_bonus/features/game_clock.c \
			./srcs_bonus/features/mushroom.c \
			./srcs_bonus/features/animation.c \
			./srcs_bonus/features/end_screen.c \
			./srcs_bonus/features/hooks.c \
			./srcs_bonus/features/fps_counter.c \
			./srcs_bonus/features/countdown.c \
			./srcs_bonus/features/music.c \
			./srcs_bonus/features/lap.c

SRCS_BONUS =  $(MAINB) \
		$(INITIALIZATIONB) \
		$(OBJECTB) \
		$(RAYB) \
		$(PARSINGB) \
		$(FEATURES)

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
else ifeq ($(OS), Darwin)
	FLAGS = $(MAC)
endif

all: submodule lib libmlx $(NAME)

bonus: submodule lib libmlx $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
		${CC} ${CFGLAGS} ${SRC} ${OBJS} ${LIBFT} $(MLX) $(FLAGS) -o ${NAME}
	@echo "$(GREEN)Mandatory Compiled$(WHITE)"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(MLX)
	${CC} ${CFGLAGS} ${OBJS_BONUS} ${LIBFT} $(MLX) $(FLAGS) -o ${NAME_BONUS}
	@echo "$(GREEN)Bonus Compiled!$(WHITE)"

submodule:
	@git submodule update --init --recursive

lib:
	@make -s -C libs/Libft

libmlx:
	@cd libs/MLX42 && cmake -B build && cmake --build build -j4

clean:
	@make clean -s -C libs/Libft
	@make clean -s -C libs/MLX42/build
	${REMOVE} ${OBJS} 
	${REMOVE} ${OBJS_BONUS}

fclean:clean
	@make fclean -s -C libs/Libft
	${REMOVE} ${NAME} ${NAME_BONUS} ${MLX}
	@echo "$(RED)Cleaning done$(WHITE)"

dependency:
	@if [ -d "$$HOME/.brew" ]; then \
		echo "\033[0;32mBrew is already installed\033[0;37m"; \
	else \
		read -p "Brew is not installed. Would you like to install it? y/n: " choice; \
		if [ "$$choice" = "y" ] || [ "$$choice" = "Y" ]; then \
			rm -rf $$HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $$HOME/.brew && echo 'export PATH=$$HOME/.brew/bin:$$PATH' >> $$HOME/.zshrc && source $$HOME/.zshrc && brew update; \
			echo "\033[0;36mBrew is now installed\033[0;37m"; \
		else \
			echo "Brew installation skipped."; \
		fi \
	fi
	@if ! command -v cmake &> /dev/null; then \
		read -p "CMake is not installed. Would you like to install it using brew? y/n: " cmake_choice; \
		if [ "$$cmake_choice" = "y" ] || [ "$$cmake_choice" = "Y" ]; then \
			brew install cmake; \
			echo "\033[0;36mCMake is now installed\033[0;37m"; \
		else \
			echo "CMake installation skipped."; \
		fi \
	else \
		echo "\033[0;32mCMake is already installed\033[0;37m"; \
	fi
	@if ! command -v glfw &> /dev/null; then \
		read -p "GLFW is not installed. Would you like to install it using brew? (y/n): " glfw_choice; \
		if [ "$$glfw_choice" = "y" ] || [ "$$glfw_choice" = "Y" ]; then \
			brew install glfw; \
			echo "\033[0;36mGLFW is now installed\033[0;37m"; \
		else \
			echo "GLFW installation skipped."; \
		fi \
	else \
		echo "\033[0;32mGLFW is already installed\033[0;37m"; \
	fi

re: fclean all

reb: fclean bonus

run: all
	${RUN}

runb: bonus
	${RUNB}

leak: all
	${LEAK}

leakb: bonus
	${LEAKB}

.PHONY: all clean fclean re lib run leak bonus reb runb leakb