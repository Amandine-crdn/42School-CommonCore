#   include "Server.hpp"

void Server::littleMessage(User &user, std::string params)
{
    std::stringstream result;
	std::string response;
    std::cout << params << std::endl;

    result << params << DELIMITER;
	response += result.str();
   	if (send(user.getFd(), response.c_str(), response.size(), 0) == -1)
        this->error("send()");
}

void Server::clientMessage(User &user, std::string cmd, std::string channel_name, std::string topic)
{
//for timeCmd
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo); // a add aux resul
    std::string str(buffer);

//for all
	std::stringstream result;
	std::string response;


    result << cmd << user.getNickName() << " ";
    
    /*---- BEGIN PROCEDURE WLC -----*/
    if (cmd.compare(RPL_WELCOME) == 0)
        result << ":👋 Welcome to the Internet Relay Chat Network, " << user.getNickName() << "!" << user.getUserName() /* masque d'hote : << "@" << inet_ntoa(_sin.sin_addr)*/;
    
    /*---- NICKNAME-----*/
    else if (cmd.compare(ERR_NICKNAMEINUSE) == 0) //channelname is nicknme not registred
        result << channel_name << " :Nickname is already in use";
    else if (cmd.compare(ERR_ERRONEUSNICKNAME) == 0) //channelname is nicknme not registred
        result  << channel_name << " :Erroneous nickname"<< DELIMITER;
    else if (cmd.compare(ERR_NOSUCHNICK) == 0)
        result << ":No such nick";
    else if (cmd.compare(ERR_USERSDONTMATCH) == 0)
        result << ":Cant change mode for other users.";

    /*----- CHANNEL ----*/
    else if (cmd.compare(RPL_CHANNELMODEIS) == 0) 
        result << channel_name << " "<< topic;
    else if (cmd.compare(ERR_NOSUCHCHANNEL) == 0)
        result << channel_name << " :No such channel";
    else if (cmd.compare(ERR_NOTONCHANNEL) == 0)
        result << channel_name << " :You're not on that channel";
    else if (cmd.compare(ERR_USERONCHANNEL) == 0)
        result << topic << " " << channel_name << " :is already on channel"; //topic is nick
    else if (cmd.compare(ERR_USERNOTINCHANNEL) == 0)
        result << topic << " " << channel_name << " :They aren't on that channel";  //topic is nick
    

    /*----- TOPIC ----*/
    
    else if (cmd.compare(RPL_NOTOPIC) == 0)
        result << channel_name << " :No topic is set";
    else if (cmd.compare(RPL_TOPIC) == 0)
        result << channel_name << " :" << topic;
    

    /*--- LIST ----*/
    else if (cmd.compare(RPL_NAMREPLY) == 0)
        result << "= " << channel_name  << " :" << topic;
    else if (cmd.compare(RPL_ENDOFNAMES) == 0)
        result << channel_name << " :End of /NAMES list";
    else if (cmd.compare(RPL_LISTSTART) == 0)
        result << "Channel, Nb of user: Topic";
    else if (cmd.compare(RPL_LIST) == 0)
    {
        result << channel_name << ",  " << this->getNbUser(channel_name);
        if (getTopic(channel_name) == "")
            result << ":  No topic";
        else
            result << ":  " + getTopic(channel_name);
    }
    else if (cmd.compare(RPL_LISTEND) == 0)
        result << " :End of LIST";
    else if (cmd.compare(ERR_BADCHANMASK) == 0)
        result << channel_name << " :Bad Channel Mask";


    /*----- MODE -----*/
     else if (cmd.compare(ERR_NOCHANMODES) == 0)
        result << channel_name << " :Channel doesn't support modes";
    else if (cmd.compare(RPL_UMODEIS) == 0)
        result << channel_name; //channelname = mode envoyé
    else if (cmd.compare(ERR_UNKNOWNMODE) == 0)
        result << channel_name << " :is unknown mode char to me for <channel>";
    else if (cmd.compare(ERR_UMODEUNKNOWNFLAG) == 0)
        result << " :Unknown MODE flag";

   
    /*----- PRIVMSG -----*/
    else if (cmd.compare(ERR_NORECIPIENT) == 0)
        result << " :No recipient given (" << channel_name << ")"; //channel name = commande
    else if (cmd.compare(ERR_CANNOTSENDTOCHAN) == 0)
        result << channel_name << " :Cannot send to channel";
    else if (cmd.compare(ERR_NOTEXTTOSEND) == 0)
        result << " :No text to send";

    /*----- WHOIS -----*/
    else if (cmd.compare(RPL_WHOISUSER) == 0)
        result << user.getNickName() << " " << user.getUserName() << " localhost 127.0.0.1*" << " :" << user.getRealName();
    else if (cmd.compare(RPL_WHOISOPERATOR) == 0)
        result << user.getNickName() << " :is an IRC operator";
    else if (cmd.compare(RPL_WHOISREGNICK) == 0)
        result << user.getNickName() << " :has identified for this nick";
    else if (cmd.compare(RPL_WHOISHOST) == 0)
        result << user.getNickName() << " :is connecting from *@localhost 127.0.0.1";
    else if (cmd.compare(RPL_WHOISMODES) == 0)
        result << user.getNickName() << " :is using modes +i";
    else if (cmd.compare(RPL_ENDOFWHOIS) == 0)
        result << user.getNickName() << " :End of /WHOIS list";


    /*----- WHO -----*/
    else if (cmd.compare(RPL_WHOREPLY) == 0)
        result << channel_name << " " << user.getUserName() << " " << this->host << " " << this->server_name << " " << user.getNickName() << " H :1 " << user.getRealName();
    //<client> <channel> <username> <host> <server> <nick> <flags> :<hopcount> <realname>
    else if (cmd.compare(RPL_ENDOFWHOIS) == 0)
        result << channel_name << " :End of WHO list";


    /*----- OPERATOR -----*/
    else if (cmd.compare(ERR_CHANOPRIVSNEEDED) == 0)
        result << channel_name << " :You're not a " << topic;
    else if (cmd.compare(RPL_YOUREOPER) == 0)
        result << ":You are now an IRC operator"<< DELIMITER;
    else if (cmd.compare(ERR_NOPRIVILEGES) == 0)
        result << ":Permission Denied- You're not an IRC operator";
    
    else if (cmd.compare(ERR_NOPRIVS) == 0)
        result << ":Insufficient oper privileges.";
  //"<client> <priv> :Insufficient oper privileges."//


    /*----- RPL -----*/

    else if (cmd.compare(RPL_AWAY) == 0)
        result << channel_name << " :" << topic; //channel name is nick // topic is message
    else if (cmd.compare(RPL_TIME) == 0)
        result << server_name << " " << str << " :it's time in France";


    /*----- ERR -----*/
    else if (cmd.compare(ERR_ALREADYREGISTRED) == 0)
        result << ":You may not reregister";
    else if (cmd.compare(ERR_PASSWDMISMATCH) == 0)
        result << ": ❌ Password incorrect";
    else if (cmd.compare(ERR_NEEDMOREPARAMS) == 0) //channel_name is command name
        result << channel_name << " :Not enough parameters" << DELIMITER;
    else if (cmd.compare(ERR_UNKNOWNCOMMAND) == 0)
        result << channel_name << " :Unknown command"; //channelname = cmd unknow
    else if (cmd.compare(ERR_NOORIGIN) == 0)
        result << ":No origin specified";
    else if (cmd.compare(ERR_NOSUCHSERVER) == 0)
        result << server_name << " :No such server";  
    

    /*----- ADMIN  -----*/
    else if (cmd.compare(RPL_ADMINME) == 0)
        result << server_name << " :Administrative info, Amandine Cerdan and Claire Nicolas De Lamballerie are the developers of this server"; 
    else if (cmd.compare(RPL_ADMINLOC1) == 0)
        result << ":Paris, France";  
    else if (cmd.compare(RPL_ADMINLOC2) == 0)
        result << ":42 school - 96 bd Bessieres-75017 PARIS";
    else if (cmd.compare(RPL_ADMINEMAIL) == 0)
        result << ":amandinecerdan91760@gmail.com"; 

    /*---- INVITE ---*/
    else if (cmd.compare(RPL_INVITING) == 0)
        result << topic << " " << channel_name; //topic is nick


    /*------ END ------*/

    result << DELIMITER; //check delimiter  des autres inutiles
    response += result.str();
    if (send(user.getFd(), response.c_str(), response.size(), 0) == -1)
        this->error("send()");
}
// /connect localhost 6667 coco