NAME = ft_retro

CCPP = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

FILENAMES = main.cpp \
			Engine.cpp \
			ACollection.cpp \
			Bounds.cpp \
			Object/AObject.cpp \
			Object/Star.cpp

INCLUDE = -I.
LINK = -lncurses


all: $(NAME)

test: $(NAME)
	./$(NAME)

$(NAME): $(FILENAMES)
	$(CCPP) $(CPPFLAGS) $(LINK) $(INCLUDE) $^ -o $@

clean:
	@rm -f $(NAME)
	@echo "removed $(NAME)"

fclean: clean

re: fclean all

.PHONY: all clean fclean re