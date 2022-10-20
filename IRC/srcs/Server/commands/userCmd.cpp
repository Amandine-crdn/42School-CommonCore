#include "../Server.hpp"

void Server::userCmd(User &user, std::string msg)
{
	std::string username;
	
	username = msg.substr(5, msg.size() - 5);

	if (!username.size()) 
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS); 
		return;
	}
	if (user.getFirstConnexion() == false)
	{
		this->clientMessage(user, ERR_ALREADYREGISTRED);
		return ;
	}
	user.setUserName(username);
}
	