#include "../Server/Server.hpp"

/* The server will process this command as though the client had sent a PART
command for each channel they are a member of.*/

void Server::partCmd(User &user, std::vector<std::string> data)
{
	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return;
	} 
	
	std::vector<std::string> channels = this->split(data[1], ',');

	for (std::vector<std::string>::iterator itc = channels.begin(); itc != channels.end(); itc++)
	{
		std::string channel = *itc;

		if (this->channelExists(channel) == false)
			this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
		else if (this->isInChannel(channel, user.getNickName()) == false)
			this->clientMessage(user, ERR_NOTONCHANNEL, channel);
		else
		{
			this->notificationPartChannel(user, channel);
			this->delUserToChan(user.getNickName(), channel);
		}
	}
}
