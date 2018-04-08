# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprivalo <pprivalo@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/26 00:44:23 by pprivalo          #+#    #+#              #
#    Updated: 2018/04/08 16:50:01 by pprivalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_retro

SRC_DIR := ./
OBJ_DIR := ./obj/

SRC := main.cpp Game.cpp Pilot.class.cpp Enemy.class.cpp Bullet.class.cpp \
		Asteroids.class.cpp Dron.class.cpp Stars.class.cpp Boss.class.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC_FLAGS := -std=c++98 -Wall -Wextra -Werror

CC := clang++

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) -lncurses 

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all

vpath %.cpp $(SRC_DIR)

.PHONY: all clean fclean re