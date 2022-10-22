#include "../Server.hpp"

void Server::joinCmd(User &user, std::vector<std::string> data)
{
	/*	Once a user has joined a channel, he receives information about
   all commands his server receives affecting the channel.  This
   includes JOIN, MODE, KICK, PART, QUIT and of course PRIVMSG/NOTICE.*/

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
			this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
			this->addNewChannel(channel);
			this->addUserToChan(user, channel);
			user.addChannel(channel);
			this->toBeChannops(user, channel);
			this->clientMessage(user, RPL_NOTOPIC, channel, "No topic");

			std::cout << "\n 🍑 The channel " << channel << " was created" << std::endl;
			std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << channel << " 🍀 " << std::endl; 
			std::cout << "\t 🎈 You're channel's operator 🎈" << std::endl;

		}

		else if (this->channelExists(channel) == true && user.isInChannel(channel) == false)
		{
			this->clientMessage(user, RPL_TOPIC, channel, this->getTopic(channel)); 
			this->addUserToChan(user, channel);
			user.addChannel(channel);

			std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << channel << " 🍀 " << std::endl; 
		}

		this->notificationJoinChannel(user, channel);
		this->notificationsUsersInChannel(user, channel);
	}	
				
}

