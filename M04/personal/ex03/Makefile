NAME	:=	interface

CPP		:=	c++
CFLAGS	:= -g -Wall -Wextra -Werror -std=c++98

SRCS	:=	main.cpp \
			AMateria.cpp \
			Cure.cpp \
			Ice.cpp \
			ICharacter.cpp \
			Character.cpp \
			IMateriaSource.cpp \
			MateriaSource.cpp
OBJS	:=	$(SRCS:.cpp=.o)

INCLS	:=	main.h \
			ICharacter.hpp \
			Character.hpp \
			AMateria.hpp \
			Ice.hpp \
			Cure.hpp \
			IMateriaSource.hpp \
			MateriaSource.hpp

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CPP) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	-rm $(OBJS)

fclean: clean
	-rm $(NAME)

re: fclean all

test: all
	@valgrind ./$(NAME)

.PHONY: all clean fclean re
