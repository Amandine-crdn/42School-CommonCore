# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acerdan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 07:44:31 by acerdan           #+#    #+#              #
#    Updated: 2021/07/20 07:44:37 by acerdan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC	=	gcc

FLAG	=	-Wall -Wextra -Werror 

SRC	=	srcs/ft_printf.c	srcs/other_fonctions.c	srcs/ft_choice.c	srcs/other_fonctions_2.c	srcs/other_fonction_3.c 
			
OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $@ $^
	@echo "$@ created"
	@ranlib $@
	@echo "$@ indexed"

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "OBJS deleted"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re:		fclean all

.PHONY: all, clean, fclean, re
