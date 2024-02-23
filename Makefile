# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 19:53:49 by marvin            #+#    #+#              #
#    Updated: 2024/02/23 17:50:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
SRC_DIR_BONUS = src_bonus
OBJ_DIR = obj

SRC = \
	so_long.c \
	file_manage.c \
	map_check.c \
	init_map.c \
	path.c \
	init_game.c \
	move.c \
	clean_exit.c \
	put_img.c

SRC_BONUS = \
	file_manage_bonus.c \
	map_check_bonus.c \
	path_bonus.c \
	clean_exit_bonus.c \
	init_game_bonus.c \
	init_map_bonus.c \
	move_bonus.c \
	key_event_bonus.c \
	put_img_bonus.c \
	render_img_bonus.c \
	so_long_bonus.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))
NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIB = -Lminilibx-linux -lmlx -lXext -lX11
INC =  -Iminilibx-linux -I./headers

RM = rm -rf

all : $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) $(LIBFT) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

$(LIBFT) :
	make -C libft all

clean :
	make -C libft clean
	$(RM) $(OBJ_DIR)

fclean : clean
	make -C libft fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_DIR) $(OBJ_BONUS) $(LIBFT)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) $(INC) $(LIBFT) -o $(NAME_BONUS)
