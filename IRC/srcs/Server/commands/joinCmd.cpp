#include "../Server.hpp"

void Server::joinCmd(User &user, std::vector<std::string> data)
{
	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return;
	}

	std::vector<std::string> new_data = this->split(data[1], ',');

	for (std::vector<std::string>::iterator itd = new_data.begin(); itd != new_data.end(); itd++)
	{
		std::string channel = *itd;

		if (this->channelExists(channel) == true && user.isInChannel(channel) == true)
		{
			this->clientMessage(user, RPL_TOPIC, channel, this->getTopic(channel));
		}

		else if (this->channelExists(channel) == false)
		{
			this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
			this->addUserToChan(channel);
			this->setChannelList(channel);
			user.addChannel(channel);
			user.toBeChannops(channel);//
			this->clientMessage(user, RPL_NOTOPIC, channel, "No topic");

			this->notificationJoinChannel(user, channel);
			this->notificationsUsersInChannel(user, channel);  // marche car premiere fois apres plus rien
			

			std::cout << "\n 🍑 The channel " << channel << " was created" << std::endl;
			std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << channel << " 🍀 " << std::endl; 
			std::cout << "\t 🎈 You're channel's operator 🎈" << std::endl;

		}

		else if (this->channelExists(channel) == true && user.isInChannel(channel) == false)
		{
			this->clientMessage(user, RPL_TOPIC, channel, this->getTopic(channel)); 
			this->addUserToChan(channel); //pour part
			user.addChannel(channel);

			this->notificationJoinChannel(user, channel);
			this->notificationsUsersInChannel(user, channel);  // marche que pour la 1ere fois
			std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << channel << " 🍀 " << std::endl; 
		}	
	}	
				
}

