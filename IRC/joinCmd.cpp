#include "Server.hpp"

void Server::joinCmd(User &user, std::vector<std::string> data)
{
	std::vector<std::string> new_data = this->split(data[1], ',');
	
	if (data.size() < 2){ this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }

	for (std::vector<std::string>::iterator itd = new_data.begin(); itd != new_data.end(); itd++)
	{
		bool correspondance = false;
		bool find = false;

		for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {		
			if (itc->getChannelName() == *itd) {
				correspondance = true;
				clientMessage(user, RPL_TOPIC, itc->getChannelName(), itc->getTopic()); // get topic a donner : "Topic for : 
				for (std::vector<std::string>::iterator itu = user.channels_list_by_user.begin(); itu != user.channels_list_by_user.end(); itu++) {
					if (*itu == *itd) { find = true; }}}}	
		
		if (correspondance == false) {
			this->clientMessage(user, ERR_NOSUCHCHANNEL, *itd); 
			this->setChannelList(*itd);
			this->clientMessage(user, RPL_NOTOPIC, *itd, "No topic");
			//why erro no such nick en plus ??
			std::cout << "\n 🍑 The channel " << *itd << " was created" << std::endl; }
			
		if (correspondance == false || find == false) {
			user.setChannelListByUser(*itd); 
			this->notificationJoinChannel(user, *itd); // a revoir
			std::cout << "\t 🎈 You're channel's operator 🎈" << std::endl;
			user.setChannops(*itd);
			std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << *itd << " 🍀 " << std::endl; 
			this->notificationsUsersInChannel(user, *itd); } // a revoir
	}
}
