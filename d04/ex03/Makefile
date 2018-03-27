# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 16:59:39 by agrumbac          #+#    #+#              #
#    Updated: 2018/03/27 17:13:26 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bocal

CPPFLAGS = -Wall -Wextra -Werror -g

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp

HDR = AMateria.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ} ${HDR}
	c++ ${CPPFLAGS} -I. -o $@ ${OBJ}

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all
