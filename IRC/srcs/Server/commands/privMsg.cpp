#include "../Server.hpp"

void Server::privMsgCmd(User &user, std::string data)
{
	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NORECIPIENT, "PRIVMSG");
		return ;
	}

	if (data.size() < 3)
	{
		this->clientMessage(user, ERR_NOTEXTTOSEND);
		return ;
	}

	std::string message = this->split(data, ':')[1];
	std::string clients = this->split(data.substr(8), ' ')[0];
	std::vector<std::string> client = this->split(clients, ',');
		
	for (std::vector<std::string>::iterator itc = client.begin(); itc != client.end(); itc++)
	{
		//envoyer message aux clients
		if (this->userExist(*itc) == false)
			this->clientMessage(user, ERR_NOSUCHNICK);
		
		for (std::vector<User>::iterator itv = utilisateurs_list.begin(); itv != utilisateurs_list.end(); itv++)
		{
			if (itv->getNickName() == *itc && user.getNickName() != itv->getNickName()) // sauf a lui-même
			{
				std::stringstream result;
				result << ":" << user.getNickName() << " PRIVMSG " << itv->getNickName() << " :" << message << DELIMITER;
				std::string test = result.str(); 
				send(itv->getFd(), test.c_str(), test.length(), 0);
				//this->clientMessage(user, RPL_AWAY, *itc); utile ? role ?
			}
		}

		//envoyer message au channel
		for (std::vector<Channel>::iterator itv = this->channels_list.begin(); itv != this->channels_list.end(); itv++)
		{			
			if (channelExists(*itc) == false)
				this->clientMessage(user, ERR_CANNOTSENDTOCHAN, *itc);
				
			if (itv->getChannelName() == *itc)
			{				
				for (std::vector<std::string>::iterator itu = itv->users_list.begin(); itu != itv->users_list.end(); itu++)
				{
					for (std::vector<User>::iterator itd = this->utilisateurs_list.begin(); itd != this->utilisateurs_list.end(); itd++)
					{
						if (*itu == itd->getNickName() && user.getNickName() != itd->getNickName())
						{
							std::stringstream result_chan;
							result_chan << ":" << user.getNickName() << " PRIVMSG " << itv->getChannelName() << " :" << message << DELIMITER;
							std::string test = result_chan.str(); 
							send(itd->getFd(), test.c_str(), test.length(), 0); 
							//this->clientMessage(user, RPL_AWAY, *itc); utile ? role ?
						}
					}
				}
			}
		}
	}
}