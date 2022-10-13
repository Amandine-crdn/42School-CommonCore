#include "Server.hpp"

void Server::clientMessage(User &user, std::string cmd)
{
	std::stringstream result; 
	std::string response;

    if (cmd.compare(RPL_WELCOME) == 0)
        result << cmd << user.getNickName() << " :👏 Welcome to the Internet Relay Chat Network." << DELIMITER;
	else if (cmd.compare(ERR_NOSUCHNICK) == 0)
        result << cmd << user.getNickName() << " :No such nick." << DELIMITER;
    else if (cmd.compare(ERR_USERSDONTMATCH) == 0)
        result << cmd << user.getNickName() << " :Cant change mode for other users." << DELIMITER;
    else if (cmd.compare(RPL_UMODEIS) == 0)
        result << cmd << "is invisible" << DELIMITER;

    response += result.str();
    send(user.getFd(), response.c_str(), response.size(), 0); 
    
}
