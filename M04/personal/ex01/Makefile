NAME	:=	polymorphism

CPP		:= c++
CFLAGS	:= -g -Wall -Wextra -Werror -std=c++98

SRCS	:=	main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			Brain.cpp

OBJS	:= $(SRCS:.cpp=.o)

INCS	:=	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			Brain.hpp \
			main.h

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

test:
	echo $(TEST)

.PHONY: all clean fclean re
