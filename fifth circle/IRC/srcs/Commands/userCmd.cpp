#include "../Server/Server.hpp"

void Server::userCmd(User &user, std::string msg, std::vector<std::string> data)
{
	if (user.getAllowPass() == false || user.getAllowNick() == false)
	{
		this->littleMessage(user, "Error USER : not accepted");
		return ;
	}

	if (data.size() < 2) 
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]); 
		return;
	}

	if (user.getFirstConnexion() == false)
	{
		this->clientMessage(user, ERR_ALREADYREGISTRED);
		return ;
	}

	std::string username = data[1];

	if (data[1].find(':') == 0)
	{
		std::string realname = this->split(msg, ':')[1];
		user.setRealName(realname);
	}

	user.setUserName(username);
}
	