NAME	=	push_swap

CC	=	gcc

FLAG	=	-Wall -Wextra -Werror

SRC	=	ft_sort.c	\
		push_swap2.c	\
		ft_action.c \
		ft_error.c \
		start.c

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
