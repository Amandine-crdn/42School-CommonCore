# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acerdan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 08:12:52 by acerdan           #+#    #+#              #
#    Updated: 2021/09/24 08:20:38 by acerdan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC	=	gcc

FLAG	=	-Wall -Wextra -Werror

SRC	=	ft_sort.c \
		push_swap.c	\
		action_a.c \
		action_b.c \
		action_3.c \
		ft_error.c \
		create_chunk.c \
		sort_max.c \
		sort_min.c \
		principal.c \
		choice_action.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "OBJS deleted"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re:	fclean all

.PHONY:	all, clean, fclean, re
