#include "Server.hpp"

void Server::userCmd(User &user, std::string msg, bool first)
{
	std::string username;
	
	username = msg.substr(5, msg.size() - 5);

	if (!username.size())
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS); 
		if (first == true)
			this->disconnected(user);
		return;
	}
	if (first == false)
	{
		this->clientMessage(user, ERR_ALREADYREGISTRED);
		return ;
	}
	user.setUserName(username);
	user.setFirstConnexion(false);
	clientMessage(user, RPL_WELCOME);
}