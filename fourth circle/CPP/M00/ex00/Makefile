SRCS	= megaphone.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= megaphone

CLANG	= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

$(NAME): $(OBJS)
	$(CLANG) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	$(CLANG) $(FLAGS) -c $<  -o $(<:.cpp=.o)