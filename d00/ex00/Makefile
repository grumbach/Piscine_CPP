# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 16:59:39 by agrumbac          #+#    #+#              #
#    Updated: 2018/03/19 20:19:53 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CFLAGS = -Wall -Wextra -Werror

CC = clang++

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ}
	@${CC} ${CFLAGS} -o $@ $<

${OBJ}: ${SRC}
	@${CC} ${CFLAGS} -c -o $@ $<

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all
