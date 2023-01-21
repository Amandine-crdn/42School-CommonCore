################	COMPILER		#################

CXX			=		c++ -g -Wall -Wextra -Werror -std=c++98

################	DIRECTORIES		#################

SRCS_DIR	=		srcs

OBJS_DIR	=		obj

#################	SOURCE FILES	#################

SRCS		=		main.cpp \
					Channel/Channel.cpp \
					Channel/ChannelUtils.cpp \
					User/User.cpp \
					User/UserUtils.cpp \
					Server/ClientMessage.cpp \
					Server/InitServer.cpp \
					Server/Server.cpp \
					Server/Actions.cpp \
					Server/ServerUtils.cpp \
					Commands/passCmd.cpp \
					Commands/timeCmd.cpp \
					Commands/userCmd.cpp \
					Commands/listCmd.cpp \
					Commands/nickCmd.cpp \
					Commands/quitCmd.cpp \
					Commands/namesCmd.cpp \
					Commands/dieCmd.cpp \
					Commands/kickCmd.cpp \
					Commands/adminCmd.cpp \
					Commands/inviteCmd.cpp \
					Commands/joinCmd.cpp \
					Commands/modeChannelCmd.cpp \
					Commands/modeUserCmd.cpp \
					Commands/operCmd.cpp \
					Commands/partCmd.cpp \
					Commands/pingCmd.cpp \
					Commands/privMsg.cpp \
					Commands/topicCmd.cpp \
					Commands/squitCmd.cpp \
					Commands/whoCmd.cpp \
					Commands/whoisCmd.cpp \
					Server/signal.cpp \


SOURCES		=		$(addprefix $(SRCS_DIR)/,$(SRCS))

#################	HEADER FILES	#################

HEADERS		=		srcs/Channel/Channel.hpp \
					srcs/User/User.hpp \
					srcs/Server/Server.hpp \
					srcs/Server/ClientMessage.hpp \
					srcs/color.hpp \

#################	OBJECT FILES	#################

OBJS		=		$(addsuffix .o, $(basename $(SRCS)))
OBJECTS		=		$(addprefix $(OBJS_DIR)/,$(OBJS))

################	BINARIES		#################

NAME		=		ircserv

################	TARGETS			#################

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(HEADERS) $(OBJECTS)
					@echo Building...
					@$(CXX) $(OBJECTS) -o $(NAME)

$(OBJS_DIR):
					mkdir -p $@/Channel
					mkdir -p $@/Server
					mkdir -p $@/User
					mkdir -p $@/Commands

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
