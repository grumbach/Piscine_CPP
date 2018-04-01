# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 16:59:39 by agrumbac          #+#    #+#              #
#    Updated: 2018/04/01 18:38:19 by stmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SRC_NAME = main.cpp A_spacecraft.cpp A_ufo.cpp Enemy.cpp Game.cpp Missile.cpp Player.cpp Star.cpp Menu.cpp Boss.cpp Bonus.cpp

HDR_NAME = settings.hpp

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all:
	@echo "\033[36;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	$(CC) -lcurses $(CPPFLAGS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp #$(INC_PATH)%.hpp $(HDR_NAME)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CPPFLAGS) $(INC) -o $@ -c $<

clean:
	@echo "\033[32;44m Make clean $(NAME) \033[0m"
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	@echo "\033[32;44m Make fclean $(NAME) \033[0m"
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
