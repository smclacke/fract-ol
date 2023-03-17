# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: smclacke <smclacke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/11 22:28:12 by smclacke      #+#    #+#                  #
#    Updated: 2023/03/17 16:33:09 by smclacke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 			= fractol

INC_DIR			= -Iinclude -Iinclude/MLX42/include -Iinclude/library_42/include

CFLAGS 			= -Wall -Werror -Wextra -o3
CC 				= gcc
LFLAGS 			= -ldl -lglfw3 -pthread
FFLAGS			= -framework Cocoa -framework OpenGL -framework IOKit -lm -Iinclude -lglfw3

SRCS			= 	main.c			\
					hook.c			\
					zoom.c			\
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


all : $(NAME) 

$(NAME) : $(OBJ)
	@ $(CC) $^ $(CFLAGS) include/library_42/libft.a include/MLX42/build/libmlx42.a $(FFLAGS) $(LFLAGS) -o $(NAME)
	@ echo "Made!"

$(OBJ_DIR):
	@ mkdir -p obj
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@ $(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

open: $(NAME)
	@ ./$(NAME) 1

clean:
	@ rm -rf $(OBJ_DIR)
	@ echo "Clean!"

fclean: clean
	@ rm -f $(NAME)
	@ echo "fCleaned!"

re: fclean all

.PHONY: all clean fclean re open libmlx library_42