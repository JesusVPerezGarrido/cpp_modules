NAME	:=	PMergeMe

CPP		:=	c++
CFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -fstandalone-debug -g

FILES	:=	main.cpp \
			PmergeMe.cpp
SRCS	:=	$(addprefix src/, $(FILES))
OBJS	:=	$(addprefix obj/, $(FILES:.cpp=.o))

INCS	:= -Iinc

all: $(NAME)

$(NAME): obj $(OBJS)
	$(CPP) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)

obj/%.o: src/%.cpp
	$(CPP) $(CFLAGS) $(INCS) -c $< -o $@

obj:
	mkdir -p obj

clean:
	-rm -r obj

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re