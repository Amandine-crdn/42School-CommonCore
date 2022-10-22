#include "../Server.hpp"

void Server::invitCmd(User &user, std::vector<std::string> data)
{
	if (data.size() < 3)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return;
	}
	
	std::string nickname = data[1];
	std::string channel = data[2];

	if (this->userExist(nickname) == false)
	{
		this->clientMessage(user, ERR_NOSUCHNICK);
		return ;
	}

	if (user.isInChannel(channel) == false)
	{
		this->clientMessage(user, ERR_NOTONCHANNEL);
		return ;
	}

	if (this->isChannops(user, channel) == false)
	{
		this->clientMessage(user, ERR_CHANOPRIVSNEEDED);
		return ;
	}

	if (this->isInChannel(channel, nickname) == true)
	{
		this->clientMessage(user, ERR_USERONCHANNEL);
		return ;
	}

	this->clientMessage(user, RPL_INVITING, channel, nickname); 
	this->clientMessage(user, RPL_AWAY, channel);
}
