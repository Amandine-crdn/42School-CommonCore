################	COMPILER		#################

CXX			=		c++ -g -Wall -Wextra -Werror -std=c++98

################	DIRECTORIES		#################

SRCS_DIR	=		srcs

OBJS_DIR	=		obj

#################	SOURCE FILES	#################

SRCS		=		main.cpp \

SOURCES		=		$(addprefix $(SRCS_DIR)/,$(SRCS))

#################	HEADER FILES	#################

HEADERS		=		includes/map.hpp \
					includes/stack.hpp \
					includes/vector.hpp \
					includes/equal.hpp \
					includes/is_integral.hpp \
					includes/pair.hpp \
					includes/make_pair.hpp \
					includes/enable_if.hpp \
					includes/iterator_traits.hpp \
					includes/reverse_iterator.hpp \




#################	OBJECT FILES	#################

OBJS		=		$(addsuffix .o, $(basename $(SRCS)))
OBJECTS		=		$(addprefix $(OBJS_DIR)/,$(OBJS))

################	BINARIES		#################

NAME		=		ft_containers

################	TARGETS			#################

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(HEADERS) $(OBJECTS)
					@echo Building...
					@$(CXX) $(OBJECTS) -o $(NAME)

$(OBJS_DIR):
					mkdir -p $@

$(OBJECTS):			$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
					@$(CXX) -c $< -o $@

clean:
					@echo Cleaning objects...
					@rm -rf $(OBJS_DIR)

fclean:				clean
					@echo Cleaning binary...
					@rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
