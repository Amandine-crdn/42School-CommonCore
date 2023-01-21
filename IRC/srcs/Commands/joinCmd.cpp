#include "../Server/Server.hpp"

void Server::joinCmd(User &user, std::vector<std::string> data)
{
	/*	Once a user has joined a channel, he receives information about
   all commands his server receives affecting the channel.  This
   includes JOIN, MODE, KICK, PART, QUIT and of course PRIVMSG/NOTICE.*/


	/* /connect localhost 6667 coco */

	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return;
	}

	std::vector<std::string> new_data = this->split(data[1], ',');

	for (std::vector<std::string>::iterator itd = new_data.begin(); itd != new_data.end(); itd++)
	{

		std::string channel = *itd;
		
		if (this->channelExists(channel) == false)
		{
			this->addNewChannel(channel);
			this->toBeChannops(user.getNickName(), channel);
		}
		
		if (isInChannel(channel, user.getNickName()) == true)
			return ;

		this->setNbUser(user, channel);
		this->notificationJoinChannel(user, channel);

		std::vector<Channel>::iterator ci = this->findChannelIt(channel);

		if (ci->getTopic() != "")
			this->clientMessage(user, RPL_TOPIC, channel, this->getTopic(channel));
		
		this->notificationsUsersInChannel(user, channel);
	}				
}
