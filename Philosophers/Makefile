# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 15:41:05 by acerdan           #+#    #+#              #
#    Updated: 2022/03/21 14:40:57 by acerdan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

DIR_SRCS := ./SRCS
LST_SRCS := main.c			\
			monitoring.c	\
			philo.c			\
			actions.c		\
			checkers.c

DIR_OBJS := ./.OBJS
LST_OBJS := $(LST_SRCS:.c=.o)

SRCS := $(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS := $(addprefix $(DIR_OBJS)/, $(LST_OBJS))

CC := gcc -pthread
CFLAGS := -Wall -Wextra -Werror 

$(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c 
		@mkdir -p $(DIR_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
		@printf "\033[0;32mProject is ready to run !\033[0m\n"

$(NAME) : $(OBJS)
		$(CC) $(OBJS) -o $(NAME)
		@printf "\033[0;32mCompilation has succeeded !\033[0m\n"

DIR_OBJS :
		mkdir -p $(DIR_OBJS)

clean :
		@rm -rf $(DIR_OBJS)
		@printf "\033[0;33mObjects deleted\033[0m\n"

fclean : clean
		@rm -rf $(NAME)
		@printf "\033[0;33m./$(NAME) deleted\033[0m\n"

re : fclean all


.PHONY : all clean fclean re 