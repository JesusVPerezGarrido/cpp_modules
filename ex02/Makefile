NAME	:=	BankAccount

CPP		:=	c++

CFLAGS	:=	-g -Wall -Wextra -Werror

INCS	:=	Account.hpp
SRCS	:=	Account.cpp \
			tests.cpp
OBJS	:=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
