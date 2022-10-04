SRCS	= main.cpp 

OBJS	= $(SRCS:.cpp=.o)

NAME	= MutantStack

CXX	= c++

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98


all:	$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

#%.o: %.cpp
#	$(CXX) $(CXXFLAGS) -c $<  -o $(<:.cpp=.o)

.PHONY:	 all, clean, fclean, re