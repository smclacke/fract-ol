# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: smclacke <smclacke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/23 17:52:07 by smclacke      #+#    #+#                  #
#    Updated: 2024/05/14 14:37:18 by smclacke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 			= fractol

INC_DIR			= -Iinclude -Iinclude/libft/src

CC 				= gcc -Ofast -flto

MAKEFLAGS		= --no-print-directory
CFLAGS 			= -Wall -Werror -Wextra
CFLAGS			+= -g -fsanitize=address

SRCS			= 	main.c			\
					hook.c			\
					scroll_hook.c	\
					utils.c			\
					init.c			\
					mandelbrot.c	\
					julia.c			\
					burningship.c	\
					colour.c

MLX42_LIB		=	-Iinclude -ldl -lglfw -pthread -lm -Iinclude/MLX42/include/MLX42
MLX42			=	include/MLX42/build/libmlx42.a

LIBFT			=	include/libft/libft.a

SRC_DIR			= src
SRC				= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR			= obj
OBJ				= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

## Colours ##
RESET		:= \033[0m
RED			:= \033[1;91m
GREEN		:= \033[1;92m
YELLOW		:= \033[1;93m
BLUE		:= \033[1;94m
PURPLE		:= \033[1;95m
CYAN		:= \033[1;96m
WHITE		:= \033[1;97m
BLACK		:= \033[1;90m

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX42) $(OBJ)
	@ echo "${BLUE} >>> fractol compiling...${RESET}"
	@ $(CC) $^ $(CFLAGS) $(LIBFT) $(MLX42) $(MLX42_LIB) $(INC_DIR) -o $(NAME)
	@ echo "${GREEN} ---> fractol Made!${RESET}"

$(LIBFT):
	@ make $(MAKEFLAGS) -C include/libft

$(MLX42):
	@ cd include/MLX42 && cmake -B build && cmake --build build -j4

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(CFLAGS) -c -o $@ $<

open: $(NAME)
	@ ./$(NAME) 1

clean:
	@ make $(MAKEFLAGS) -C include/libft clean
	@ rm -rf include/MLX42/build
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ make $(MAKEFLAGS) -C include/libft fclean
	@ rm -rf $(OBJ_DIR)
	@ rm -f $(NAME)
	@ echo "${BLUE} // fractol fCleaned!${RESET}"

re: fclean all

.PHONY: all clean fclean re open libmlx library_42