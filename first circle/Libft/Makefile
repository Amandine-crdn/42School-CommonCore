# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acerdan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 11:44:48 by acerdan           #+#    #+#              #
#    Updated: 2021/05/31 08:51:00 by acerdan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc

FLAG	=	-Wall -Wextra -Werror

SRC	=	ft_atoi.c	\
		ft_bzero.c	\
		ft_calloc.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memccpy.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
	   	ft_memcpy.c \
		ft_memmove.c	\
		ft_memset.c	\
		ft_strchr.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c \
		ft_strrchr.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strdup.c	\
		ft_substr.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c	\
		ft_strmapi.c	\
		ft_putnbr_fd.c	\
		ft_putendl_fd.c	\
		ft_putstr_fd.c	\
		ft_putchar_fd.c	\
		ft_itoa.c	\

BNS	=	ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $@ $^
	@echo "$@ created"
	@ranlib $@
	@echo "$@ indexed"

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $<

OBJBONUS	=	$(BNS:.c=.o)

BONUS	:	$(OBJBONUS)
	@ar rc $@ $^
	@echo "$@ created"
	@ranlib $@
	@echo "$@ indexed"

clean:
	@rm -f $(OBJ) $(OBJBONUS)
	@echo "OBJS deleted"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re:	fclean all

.PHONY:	all, clean, fclean, re

