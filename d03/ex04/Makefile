# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 16:59:39 by agrumbac          #+#    #+#              #
#    Updated: 2018/03/26 21:09:16 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = NinjaTrap

CPPFLAGS = -Wall -Wextra -Werror -g

SRC = main.cpp NinjaTrap.cpp ClapTrap.cpp FragTrap.cpp SuperTrap.cpp ScavTrap.cpp

HDR = NinjaTrap.hpp ClapTrap.hpp FragTrap.hpp SuperTrap.hpp ScavTrap.hpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ} ${HDR}
	c++ ${CPPFLAGS} -I. -o $@ ${OBJ}

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all
