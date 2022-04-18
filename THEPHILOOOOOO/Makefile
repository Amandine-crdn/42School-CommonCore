NAME	=	philo

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
THREAD	=	-pthread -lpthread

THREAD_SANITIZER	=	-g3 -fsanitize=thread

INCLUDES	=	includes
HEADER		=	philosophers.h

SRCS_DIR		=	srcs

SRCS_LIST	=	main.c \
				checkers.c \
				init_data.c \
				next.c \
				routine.c \
				utils.c \
				error.c

SRCS		=	$(addprefix $(SRCS_DIR)/,$(SRCS_LIST))

OBJS_DIR	=	objs

OBJS		=	$(addprefix $(OBJS_DIR)/,$(SRCS_LIST:.c=.o))


all : $(OBJS_DIR) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(THREAD) -o $@ $^

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(INCLUDES)/$(HEADER) Makefile
	$(CC) $(CFLAGS) $(THREAD) -c $< -o $@

$(OBJS_DIR) :
	mkdir -p objs

check_threads : $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(THREAD) $(THREAD_SANITIZER) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re, check_threads