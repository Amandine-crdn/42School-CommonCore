#   include "Server.hpp"

void Server::clientMessage(User &user, std::string cmd, std::string channel_name, std::string topic)
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
    else if (cmd.compare(ERR_ALREADYREGISTRED) == 0)
        result << cmd  << user.getUserName() << " :You may not reregister" << DELIMITER;
    else if (cmd.compare(ERR_PASSWDMISMATCH) == 0)
        result << cmd << ": ❌ Password incorrect" << DELIMITER;
    else if (cmd.compare(ERR_NICKNAMEINUSE) == 0)
        result << cmd << DELIMITER;
    else if (cmd.compare(ERR_ERRONEUSNICKNAME) == 0)
        result << cmd << ": Your nickname has more than 9 characters "<< DELIMITER;
    else if (cmd.compare(ERROR) == 0)
        result << ": Good bye"<< DELIMITER;  
    else if (cmd.compare(ERR_NEEDMOREPARAMS) == 0)
        result << cmd << " PING :Not enough parameters"<< DELIMITER; 
    else if (cmd.compare(RPL_NOTOPIC) == 0)
        result << cmd  <<  ":" << "#" << channel_name << " :No topic is set"<< DELIMITER; //tst avec : et #
    else if (cmd.compare(RPL_YOUREOPER) == 0)
        result << cmd << user.getNickName() << " :You are now an IRC operator"<< DELIMITER;
    else if (cmd.compare(RPL_TOPIC) == 0)
        result << cmd <<  ":" << channel_name << " :" << topic << DELIMITER; //test : devant
    else if (cmd.compare(ERR_NOSUCHCHANNEL) == 0)
        result << cmd << channel_name << " :We created this channel, (you're operator of this channel) cause" << DELIMITER;
    
    
    else if (cmd.compare(RPL_NAMREPLY) == 0)
        result << ":" << server_name << " " << cmd << user.getNickName() << " = " << channel_name  << " :" << topic << DELIMITER; //topic = list users in channel
    else if (cmd.compare(RPL_ENDOFNAMES) == 0)
        result  << ":" << server_name << " " << cmd << user.getNickName() <<  " " << channel_name << " :End of /NAMES list" << DELIMITER;


     else if (cmd.compare(ERR_UNKNOWNCOMMAND) == 0)
        result << cmd << channel_name << " :Unknown command" << DELIMITER; //channelname = cmd unknow

    response += result.str();
    send(user.getFd(), response.c_str(), response.size(), 0); 
}
// /connect localhost 6667 coco