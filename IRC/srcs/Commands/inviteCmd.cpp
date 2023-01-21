#include "../Server/Server.hpp"

void Server::invitCmd(User &user, std::vector<std::string> data)
{
	if (data.size() < 3)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return;
	}


	std::string nickname = data[1];
	std::string channel = data[2];
	
	if (this->channelExists(channel) == false)
	{
		this->clientMessage(user, ERR_NOSUCHCHANNEL);
		return ;
	}

	if (this->isInChannel(channel, user.getNickName()) == false)
	{
		this->clientMessage(user, ERR_NOTONCHANNEL);
		return ;
	}

	if (this->isInChannel(channel,nickname) == true)
	{
		this->clientMessage(user, ERR_USERONCHANNEL, channel, nickname);
		return ;
	}

	if (this->isChannops(user.getNickName(), channel) == false)
	{
		this->clientMessage(user, ERR_CHANOPRIVSNEEDED, channel, "channel operator");
		return ;
	}

	this->clientMessage(user, RPL_INVITING, channel, nickname); 

	std::vector<User>::iterator ui = this->findUserIt(nickname);
	this->littleMessage(*ui, ":" + user.getNickName() + " INVITE " + nickname + " " + channel);

}
