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

		if (this->channelExists(channel) == false) // le creer et l'ajouter a ses channels
		{
			this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
			this->setChannelList(channel);
			user.addChannel(channel);
			std::cout << "\n 🍑 The channel " << channel << " was created" << std::endl;

			this->clientMessage(user, RPL_NOTOPIC, channel, "No topic");
			std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << *itd << " 🍀 " << std::endl; 

			user.toBeChannops(channel);
			std::cout << "\t 🎈 You're channel's operator 🎈" << std::endl;

			this->notificationJoinChannel(user, *itd); // notif ici aussi ?
			this->notificationsUsersInChannel(user, *itd);  // a revoir

			return ;
		}

		if (user.isInChannel(channel) == false) //channel existe forcement, est-il dedans, // ajouter si pas dedans
		{
			if (this->getTopic(channel) == "")
				this->clientMessage(user, RPL_NOTOPIC, channel, "No topic");
			else
				this->clientMessage(user, RPL_TOPIC, channel, this->getTopic(channel)); 
			user.addChannel(channel);
			std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << *itd << " 🍀 " << std::endl; 

			this->notificationJoinChannel(user, *itd); // a revoir
			this->notificationsUsersInChannel(user, *itd);  // a revoir

			return ;
		}	
	}	
				
}

