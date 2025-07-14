NAME	:=	polymorphism

CPP		:= c++
CFLAGS	:= -g -Wall -Wextra -Werror -std=c++98

SRCS	:=	main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp

OBJS	:= $(SRCS:.cpp=.o)

INCS	:=	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
