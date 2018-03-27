# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 16:59:39 by agrumbac          #+#    #+#              #
#    Updated: 2018/03/27 15:52:44 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorph

CPPFLAGS = -Wall -Wextra -Werror -g

SRC = main.cpp Sorcerer.cpp Victim.cpp Peon.cpp

HDR = Sorcerer.hpp Victim.hpp Peon.hpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ} ${HDR}
	c++ ${CPPFLAGS} -I. -o $@ ${OBJ}

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all
