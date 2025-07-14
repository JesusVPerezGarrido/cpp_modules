NAME	:=	violence

CPP		:=	c++

CFLAGS	:=	-g -Wall -Wextra -Werror -std=c++98

SRCS	:=	main.cpp \
			Weapon.cpp \
			HumanA.cpp \
			HumanB.cpp

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
