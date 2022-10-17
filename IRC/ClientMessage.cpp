#   include "Server.hpp"

void Server::clientMessage(User &user, std::string cmd, std::string channel_name, std::string topic)
{
	std::stringstream result;
	std::string response;

    if (cmd.compare(RPL_WELCOME) == 0)
        result << cmd << user.getNickName() << " :👋 Welcome to the Internet Relay Chat Network, " << user.getNickName() << "!" << user.getUserName() << "@" << inet_ntoa(my_addr.sin_addr) << DELIMITER;
	else if (cmd.compare(ERR_NOSUCHNICK) == 0)
        result << cmd << user.getNickName() << " :No such nick" << DELIMITER;
    else if (cmd.compare(ERR_USERSDONTMATCH) == 0)
        result << cmd << user.getNickName() << " :Cant change mode for other users." << DELIMITER;
    else if (cmd.compare(RPL_UMODEIS) == 0)
        result << cmd << user.getNickName() << " is invisible" << DELIMITER;
    else if (cmd.compare(ERR_ALREADYREGISTRED) == 0)
        result << cmd  << user.getUserName() << " :You may not reregister" << DELIMITER;
    else if (cmd.compare(ERR_PASSWDMISMATCH) == 0)
        result << cmd << user.getNickName() << " : ❌ Password incorrect" << DELIMITER;
    else if (cmd.compare(ERR_NICKNAMEINUSE) == 0) //channelname is nicknme not registred
        result << cmd << user.getNickName() << " " << user.getNickName() << " :Nickname is already in use" << DELIMITER;
    else if (cmd.compare(ERR_ERRONEUSNICKNAME) == 0) //channelname is nicknme not registred
        result << cmd << user.getNickName() << " " << channel_name << " : Your nickname has more than 9 characters "<< DELIMITER;
    else if (cmd.compare(ERR_NEEDMOREPARAMS) == 0)
        result << cmd << user.getNickName() << " :Not enough parameters"<< DELIMITER;
    else if (cmd.compare(RPL_NOTOPIC) == 0)
        result << cmd << user.getNickName() << " " << channel_name << " :No topic is set" << DELIMITER; //tst avec : et #
    else if (cmd.compare(RPL_TOPIC) == 0)
        result << cmd << user.getNickName() << " " << channel_name << " :" << topic << DELIMITER;
    else if (cmd.compare(RPL_YOUREOPER) == 0)
        result << cmd << user.getNickName() << " :You are now an IRC operator"<< DELIMITER;
    else if (cmd.compare(RPL_NAMREPLY) == 0)
        result << cmd << user.getNickName() << " = " << channel_name  << " :" << topic << DELIMITER; //topic = list users in channel
    else if (cmd.compare(RPL_ENDOFNAMES) == 0)
        result << cmd << user.getNickName() << " " << channel_name << " :End of /NAMES list" << DELIMITER;
    else if (cmd.compare(ERR_NOTONCHANNEL) == 0)
        result << cmd <<  user.getNickName() << " " << channel_name << " :You're not on that channel" << DELIMITER;
    else if (cmd.compare(ERR_UNKNOWNCOMMAND) == 0)
        result << cmd << user.getNickName() << " " << channel_name << " :Unknown command" << DELIMITER; //channelname = cmd unknow
    else if (cmd.compare(RPL_CHANNELMODEIS) == 0)
        result << cmd << user.getNickName() << " " << channel_name << " is public" << DELIMITER;    
    else if (cmd.compare(ERR_NOSUCHCHANNEL) == 0)
        result << cmd << user.getNickName() << " " << channel_name << " :No such channel" << DELIMITER;
    else if (cmd.compare(ERR_NOPRIVILEGES) == 0)
        result << cmd << user.getNickName() << " :Permission Denied- You're not an IRC operator" << DELIMITER;
    
    else if (cmd.compare(ERROR) == 0) //ERR_UNKNOWNERROR 400 ?
        result << ": Good bye"<< DELIMITER;  //euh


    else if (cmd.compare(ERR_NOORIGIN) == 0)
        result << cmd << user.getNickName() << " :No origin specified" << DELIMITER;
    else if (cmd.compare(ERR_NOSUCHSERVER) == 0)
        result << cmd << user.getNickName() << " " << server_name << " :No such server" << DELIMITER;  
       else if (cmd.compare(ERR_USERONCHANNEL) == 0)
        result << cmd << user.getNickName() << " " << topic << " " << channel_name << " :is already on channel" << DELIMITER; //topic is nick
        

    else if (cmd.compare(ERR_USERNOTINCHANNEL) == 0)
        result << cmd << user.getNickName() << " " << topic << " " << channel_name << " :They aren't on that channel" << DELIMITER;  //topic is nick
    
    else if (cmd.compare(RPL_ADMINME) == 0)
        result << cmd << user.getNickName() <<  " " << server_name << " :Administrative info, Amandine Cerdan is the developer of this server" << DELIMITER; 
    else if (cmd.compare(RPL_ADMINLOC1) == 0)
        result << cmd << user.getNickName() << " :Paris, France" << DELIMITER;  
    else if (cmd.compare(RPL_ADMINEMAIL) == 0)
        result << cmd << user.getNickName() << " :amandinecerdan91760@gmail.com" << DELIMITER; 
    else if (cmd.compare(RPL_INVITING) == 0)
        result << cmd << user.getNickName() << " " << topic << " " << channel_name << DELIMITER; 

    response += result.str();
    send(user.getFd(), response.c_str(), response.size(), 0); 
}
// /connect localhost 6667 coco