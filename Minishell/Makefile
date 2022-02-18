# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 08:42:48 by acerdan           #+#    #+#              #
#    Updated: 2022/02/18 13:58:25 by acerdan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Minishell

CC	=	gcc 

FLAG	=	-Wall -Wextra -Werror -lreadline -g

SRC	=	ft_split.c	\
		main.c	\
		pipex_utils.c \
		strs_utils.c \

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