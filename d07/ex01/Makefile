# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 16:59:39 by agrumbac          #+#    #+#              #
#    Updated: 2018/04/04 13:17:40 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = templar

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = iter.cpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ} ${HDR}
	c++ ${CPPFLAGS} -I. -o $@ ${OBJ}

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all
