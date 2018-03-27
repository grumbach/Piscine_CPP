# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 16:59:39 by agrumbac          #+#    #+#              #
#    Updated: 2018/03/27 23:23:13 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miner

CPPFLAGS = -Wall -Wextra -Werror -g

SRC = main.cpp AsteroKreog.cpp KoalaSteroid.cpp StripMiner.cpp DeepCoreMiner.cpp MiningBarge.cpp

HDR = AsteroKreog.hpp DeepCoreMiner.hpp IAsteroid.hpp IMiningLaser.hpp KoalaSteroid.hpp MiningBarge.hpp StripMiner.hpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ} ${HDR}
	c++ ${CPPFLAGS} -I. -o $@ ${OBJ}

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all
