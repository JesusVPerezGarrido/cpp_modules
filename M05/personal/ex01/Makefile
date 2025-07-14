NAME	:=	bureaucracy

CPP		:=	c++
CFLAGS	:=	-Wall -Werror -Wextra -std=c++98

FILES	:=	Bureaucrat.cpp \
			Form.cpp \
			main.cpp
SRCS	:=	$(addprefix src/, $(FILES))
OBJS	:=	$(addprefix obj/, $(FILES:.cpp=.o))

INCS	:=	-Iinc

all: $(NAME)

$(NAME):  obj $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)

obj:
	mkdir -p obj

obj/%.o: src/%.cpp
	$(CPP) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	-rm -r obj

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re