# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: SarahLouise <SarahLouise@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 21:10:20 by smclacke          #+#    #+#              #
#    Updated: 2023/03/06 01:28:21 by SarahLouise      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = include/libft.h

SRCS = ft_isalpha.c \
    ft_isalnum.c    \
    ft_isascii.c    \
    ft_isdigit.c    \
    ft_isprint.c    \
    ft_strchr.c     \
    ft_strrchr.c    \
    ft_strlen.c     \
    ft_strnstr.c    \
    ft_strncmp.c    \
    ft_strlcat.c    \
    ft_strlcpy.c    \
    ft_atoi.c       \
    ft_bzero.c      \
    ft_memset.c     \
    ft_memcpy.c     \
    ft_memcmp.c     \
    ft_memmove.c    \
    ft_memchr.c     \
    ft_tolower.c    \
    ft_toupper.c    \
    ft_calloc.c     \
    ft_strdup.c     \
    ft_putchar_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c  \
    ft_putstr_fd.c  \
    ft_strjoin.c    \
    ft_substr.c     \
    ft_striteri.c   \
    ft_strtrim.c    \
    ft_strmapi.c    \
    ft_itoa.c       \
    ft_split.c      \
    ft_lstadd_back.c  \
    ft_lstadd_front.c \
    ft_lstclear.c     \
    ft_lstdelone.c    \
    ft_lstiter.c      \
    ft_lstlast.c      \
    ft_lstmap.c       \
    ft_lstnew.c       \
    ft_lstsize.c      \
	ft_atof.c         \
	ft_ishex.c        \
	ft_isspace.c      \
	ft_strcmp.c       \

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR = obj
OBJS = $(SRCS:%.c=%.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJS))


CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude/ -Iinclude/libft/
ARCHIVE = ar rcs
RM = rm -f

ALL = $(OBJS)

all: $(NAME)

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@ $(ARCHIVE) $(NAME) $(addprefix $(OBJ_DIR)/, $(ALL))
	@ echo "Made!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@ $(CC) $(CFLAGS) -c -o $@ $<

clean:
	@ $(RM) -rf $(OBJ_DIR)
	@ echo "Clean!"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "fCleaned!"

re: fclean all

.PHONY: all clean fclean re