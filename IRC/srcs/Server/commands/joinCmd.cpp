#include "../Server.hpp"

void User::addChannel(Channel &channel)
{
	this->channelsJoin.push_back(channel);
}

void Server::joinCmd(User &user, std::vector<std::string> data)
{
	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS);
		return;
	}

	std::vector<std::string> new_data = this->split(data[1], ',');
	

	for (std::vector<std::string>::iterator itd = new_data.begin(); itd != new_data.end(); itd++)
	{
		bool correspondance = false;
		bool find = false;

		for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
		{
			std::string channel = itc->getChannelName();

			if (this->channelExists(channel) == false) // le creer et l'ajouter a ses channels
			{
				this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
				this->setChannelList(channel);
				
				user.addChannel(*itc);
				std::cout << "\n 🍑 The channel " << channel << " was created" << std::endl;
				
				this->clientMessage(user, RPL_NOTOPIC, channel, "No topic");
				std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << *itd << " 🍀 " << std::endl; 
				
				user.toBeChannops(channel);
				std::cout << "\t 🎈 You're channel's operator 🎈" << std::endl;
				return ;
			}

			if (user.isInChannel(channel) == false) //channel existe forcement, est-il dedans, // ajouter si pas dedans
			{
				this->clientMessage(user, RPL_TOPIC, itc->getChannelName(), itc->getTopic()); 
				user.addChannel(*itc);
				std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << *itd << " 🍀 " << std::endl; 
				
				this->notificationJoinChannel(user, *itd); // a revoir
				this->notificationsUsersInChannel(user, *itd);  // a revoir

				return ;
			}
		}	
	}	
				
}

