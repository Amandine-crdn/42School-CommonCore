################	COMPILER		#################

CC			=		c++ -g -Wall -Wextra -Werror -std=c++98

################	DIRECTORIES		#################

SRCS_DIR	=		srcs

OBJS_DIR	=		obj

#################	SOURCE FILES	#################

SRCS		=		main.cpp \
					Channel/Channel.cpp \
					User/User.cpp \
					User/UserUtils.cpp \
					Server/ClientMessage.cpp \
					Server/InitServer.cpp \
					Server/Server.cpp \
					Server/Actions.cpp \
					Server/ServerUtils.cpp \
					Server/commands/passCmd.cpp \
					Server/commands/timeCmd.cpp \
					Server/commands/userCmd.cpp \
					Server/commands/listCmd.cpp \
					Server/commands/nickCmd.cpp \
					Server/commands/quitCmd.cpp \
					Server/commands/namesCmd.cpp \
					Server/commands/dieCmd.cpp \
					Server/commands/kickCmd.cpp \
					Server/commands/adminCmd.cpp \
					Server/commands/inviteCmd.cpp \
					Server/commands/joinCmd.cpp \
					Server/commands/modeChannelCmd.cpp \
					Server/commands/modeUserCmd.cpp \
					Server/commands/operCmd.cpp \
					Server/commands/partCmd.cpp \
					Server/commands/pingCmd.cpp \
					Server/commands/privMsg.cpp \
					Server/commands/topicCmd.cpp \
					Server/commands/squitCmd.cpp \
					

SOURCES		=		$(addprefix $(SRCS_DIR)/,$(SRCS))

#################	HEADER FILES	#################

HEADERS		=		srcs/Channel/Channel.hpp \
					srcs/User/User.hpp \
					srcs/Server/Server.hpp \
					srcs/Server/ClientMessage.hpp \

#################	OBJECT FILES	#################

OBJS		=		$(addsuffix .o, $(basename $(SRCS)))
OBJECTS		=		$(addprefix $(OBJS_DIR)/,$(OBJS))

################	BINARIES		#################

NAME		=		ircserv

################	TARGETS			#################

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(HEADERS) $(OBJECTS)
					@echo Building...
					@$(CC) $(OBJECTS) -o $(NAME)

$(OBJS_DIR):
					mkdir -p $@/Channel
					mkdir -p $@/Server
					mkdir -p $@/User
					mkdir -p $@/Server/commands

$(OBJECTS):			$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
					@$(CC) -c $< -o $@

clean:
					@echo Cleaning objects...
					@rm -rf $(OBJS_DIR)

fclean:				clean
					@echo Cleaning binary...
					@rm -f $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
