# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 16:59:39 by agrumbac          #+#    #+#              #
#    Updated: 2018/04/02 17:11:18 by agrumbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CPPFLAGS = -Wall -Wextra -Werror -g

SRC = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp OfficeBlock.cpp CentralBureaucracy.cpp

HDR = Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp OfficeBlock.hpp CentralBureaucracy.hpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ}
	c++ ${CPPFLAGS} -I. -o $@ ${OBJ}

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}
	@/bin/rm -f *_shrubbery

re: fclean all
