NAME	:=	easyfind

CPP		:=	c++
CFLAGS	:=	-Wall -Wextra -Werror -std=c++98

FILES	:=	main.cpp
SRCS	:=	$(addprefix src/, $(FILES))
OBJS	:=	$(addprefix obj/, $(FILES:.cpp=.o))

INCS	:=	-Iinc

all: $(NAME)

$(NAME): obj $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

obj:
	-mkdir obj

obj/%.o: src/%.cpp
	$(CPP) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	-rm -r obj

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re