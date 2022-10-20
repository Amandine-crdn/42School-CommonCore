#include "../Server.hpp"

void Server::userCmd(User &user, std::string msg, std::vector<std::string> data)
{
	if (user.getAllowPass() == false)
		return ;

	if (data.size() < 2) 
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]); 
		return;
	}

	std::string username = data[1];
	std::string realname = this->split(msg, ':')[1];

	if (user.getFirstConnexion() == false)
	{
		this->clientMessage(user, ERR_ALREADYREGISTRED);
		return ;
	}

	user.setUserName(username);
	user.setRealName(realname);
}
	