NAME = ft_retro

CPPFLAGS = -Wall -Wextra -Werror

SRC = main.cpp

HDR = Background.hpp

OBJ = $(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ} ${HDR}
	clang++ ${CPPFLAGS} -I. -o $@ ${OBJ} -lncurses

clean:
	@/bin/rm -f ${OBJ}

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all
