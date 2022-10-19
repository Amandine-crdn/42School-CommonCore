#   include "Server.hpp"

void Server::clientMessage(User &user, std::string cmd, std::string channel_name, std::string topic)
{
	std::stringstream result;
	std::string response;

    if (cmd.compare(ERR_ALREADYREGISTRED) == 0)
        result << cmd  << user.getUserName() << " :You may not reregister";
    else if (cmd.compare(ERR_NOTONCHANNEL) == 0)
        result << cmd <<  user.getNickName() << " " << channel_name << " :You're not on that channel";
    if (cmd.compare(ERR_ALREADYREGISTRED) == 0 || cmd.compare(ERR_NOTONCHANNEL) == 0) {
        result << DELIMITER; response += result.str();
        send(user.getFd(), response.c_str(), response.size(), 0); return; }


    result << cmd << user.getNickName() << " ";
    if (cmd.compare(RPL_WELCOME) == 0)
        result << ":👋 Welcome to the Internet Relay Chat Network, " << user.getNickName() << "!" << user.getUserName() << "@" << inet_ntoa(my_addr.sin_addr);
	else if (cmd.compare(ERR_NOSUCHNICK) == 0)
        result << ":No such nick";
    else if (cmd.compare(ERR_USERSDONTMATCH) == 0)
        result << ":Cant change mode for other users.";
    else if (cmd.compare(RPL_UMODEIS) == 0)
        result << "is invisible";
    else if (cmd.compare(ERR_PASSWDMISMATCH) == 0)
        result << ": ❌ Password incorrect";
    else if (cmd.compare(ERR_NICKNAMEINUSE) == 0) //channelname is nicknme not registred
        result << user.getNickName() << " :Nickname is already in use";
    else if (cmd.compare(ERR_ERRONEUSNICKNAME) == 0) //channelname is nicknme not registred
        result  << channel_name << " : Your nickname has more than 9 characters "<< DELIMITER;
    else if (cmd.compare(ERR_NEEDMOREPARAMS) == 0)
        result << ":Not enough parameters"<< DELIMITER;
    else if (cmd.compare(RPL_NOTOPIC) == 0)
        result << channel_name << " :No topic is set"; //tst avec : et #
    else if (cmd.compare(RPL_TOPIC) == 0)
        result << channel_name << " :" << topic;
    else if (cmd.compare(RPL_YOUREOPER) == 0)
        result << ":You are now an IRC operator"<< DELIMITER;
    else if (cmd.compare(RPL_NAMREPLY) == 0)
        result << "= " << channel_name  << " :" << topic; //topic = list users in channel
    else if (cmd.compare(RPL_ENDOFNAMES) == 0)
        result << channel_name << " :End of /NAMES list";
    else if (cmd.compare(ERR_UNKNOWNCOMMAND) == 0)
        result << channel_name << " :Unknown command"; //channelname = cmd unknow
    else if (cmd.compare(RPL_CHANNELMODEIS) == 0)
        result << channel_name << " is public";    
    else if (cmd.compare(ERR_NOSUCHCHANNEL) == 0)
        result << channel_name << " :No such channel";
    else if (cmd.compare(ERR_NOPRIVILEGES) == 0)
        result << ":Permission Denied- You're not an IRC operator";
    
    /*else if (cmd.compare(ERROR) == 0) //ERR_UNKNOWNERROR 400 ?
        result << ": Good bye"<< DELIMITER;  //euh*/


    else if (cmd.compare(ERR_NOORIGIN) == 0)
        result << ":No origin specified";
    else if (cmd.compare(ERR_NOSUCHSERVER) == 0)
        result << server_name << " :No such server";  
       else if (cmd.compare(ERR_USERONCHANNEL) == 0)
        result << topic << " " << channel_name << " :is already on channel"; //topic is nick
        

    else if (cmd.compare(ERR_USERNOTINCHANNEL) == 0)
        result << topic << " " << channel_name << " :They aren't on that channel";  //topic is nick
    
    else if (cmd.compare(RPL_ADMINME) == 0)
        result << server_name << " :Administrative info, Amandine Cerdan is the developer of this server"; 
    else if (cmd.compare(RPL_ADMINLOC1) == 0)
        result << ":Paris, France";  
    else if (cmd.compare(RPL_ADMINEMAIL) == 0)
        result << ":amandinecerdan91760@gmail.com"; 
    else if (cmd.compare(RPL_INVITING) == 0)
        result << topic << " " << channel_name; 

    result << DELIMITER;
    response += result.str();
    send(user.getFd(), response.c_str(), response.size(), 0); 
}
// /connect localhost 6667 coco