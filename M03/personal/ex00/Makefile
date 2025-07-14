NAME	:=	claptrap

CPP		:=	c++
CFLAGS	:= -g -Wall -Werror -Wextra -std=c++98

SRCS	:=	main.cpp \
			ClapTrap.cpp
OBJS	:=	$(SRCS:.cpp=.o)

INCS	:=	ClapTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

