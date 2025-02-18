NAME	:=	phonebook

CPP		:=	c++

CFLAGS	:=	-g -Wall -Wextra -Werror

INCS	:=	
SRCS	:=	main.cpp \
			Phonebook.cpp \
			Contact.cpp
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
