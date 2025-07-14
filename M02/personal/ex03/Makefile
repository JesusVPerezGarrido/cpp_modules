NAME	:=	bsp

CFLAGS	:= -g -Wall -Wextra -Werror -std=c++98

SRCS	:=	Fixed.cpp \
			Point.cpp \
			bsp.cpp \
			main.cpp
OBJS	:=	$(SRCS:.cpp=.o)
INCS	:=	Fixed.hpp \
			Point.hpp \
			bsp.h

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test ksdjhf
