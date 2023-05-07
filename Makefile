# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: smclacke <smclacke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/23 17:52:07 by smclacke      #+#    #+#                  #
#    Updated: 2023/05/07 12:56:12 by SarahLouise   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 			= fractol

INC_DIR			= -Iinclude -Iinclude/MLX42/include -Iinclude/libft/src

CFLAGS 			= -Wall -Werror -Wextra
CC 				= gcc -Ofast -o3
LFLAGS 			= -ldl -lglfw -pthread
FFLAGS			= -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw

SRCS			= 	main.c			\
					hook.c			\
					scroll_hook.c	\
					utils.c			\
					init.c			\
					mandelbrot.c	\
					julia.c			\
					burningship.c	\
					colour.c

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

all : libft $(NAME)

$(NAME) : $(OBJ)
	@ echo "${BLUE} >>> fractol compiling...${RESET}"
	@ $(CC) $^ $(CFLAGS) $(INC_DIR) include/libft/libft.a include/MLX42/build/libmlx42.a $(FFLAGS) $(LFLAGS) -o $(NAME)
	@ echo "${GREEN} ---> fractol Made!${RESET}"

libft:
	@ make -C include/libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

open: $(NAME)
	@ ./$(NAME) 1

clean:
	@ make -C include/libft clean
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ make -C include/libft fclean
	@ rm -f $(NAME)
	@ echo "${BLUE} // fractol fCleaned!${RESET}"

re: fclean all

.PHONY: all clean fclean re open libmlx library_42