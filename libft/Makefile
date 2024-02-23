# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 18:09:50 by marvin            #+#    #+#              #
#    Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_DIR = ft_printf
GNL_DIR = gnl
OBJ_DIR = obj

PRINTF_SRC = $(PRINTF_DIR)/ft_printf.c \
	$(PRINTF_DIR)/utils.c \
	$(PRINTF_DIR)/print_num.c

GNL_SRC = $(GNL_DIR)/get_next_line_utils.c \
	$(GNL_DIR)/get_next_line.c \

LIBFT_SRC = \
	ft_strchr.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strrchr.c \
	ft_memset.c \
	ft_strjoin.c \
	ft_split.c \
	ft_strdup.c \
	ft_itoa.c \
	ft_calloc.c \
	ft_bzero.c

SRC = $(PRINTF_SRC) $(GNL_SRC) $(LIBFT_SRC)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
INC = -I./headers
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o : $(PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)
	
fclean : clean
	$(RM) $(NAME)
	
re : fclean all
