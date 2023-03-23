# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: smclacke <smclacke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/23 17:52:07 by smclacke      #+#    #+#                  #
#    Updated: 2023/03/23 17:52:09 by smclacke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 			= fractol

INC_DIR			= -Iinclude -Iinclude/MLX42/include -Iinclude/libft/src

CFLAGS 			= -Wall -Werror -Wextra
CC 				= gcc -Ofast
LFLAGS 			= -ldl -lglfw3 -pthread
FFLAGS			= -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw3

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


all : libft $(NAME)

$(NAME) : $(OBJ)
	@ $(CC) $^ $(CFLAGS) $(INC_DIR) include/libft/libft.a include/MLX42/build/libmlx42.a $(FFLAGS) $(LFLAGS) -o $(NAME)
	@ echo "Made!"

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
	@ echo "Clean!"

fclean: clean
	@ make -C include/libft fclean
	@ rm -f $(NAME)
	@ echo "fCleaned!"

re: fclean all

.PHONY: all clean fclean re open libmlx library_42