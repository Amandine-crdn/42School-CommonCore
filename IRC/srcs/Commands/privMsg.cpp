#include "../Server/Server.hpp"

void Server::privMsgCmd(User &user, std::string data)
{
	if (data.size() < 1)
	{
		this->clientMessage(user, ERR_NORECIPIENT, "PRIVMSG");
		return ;
	}

	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NOTEXTTOSEND);
		return ;
	}



	std::string message = this->split(data, ':')[1];
	std::string clients = this->split(data.substr(8), ' ')[0];
	std::vector<std::string> client = this->split(clients, ',');
	
	for (std::vector<std::string>::iterator itc = client.begin(); itc != client.end(); itc++)
	{
		bool isachan = this->isaChannel(*itc);

		if (isachan == false && this->userExist(*itc) == false)
		{
			this->clientMessage(user, ERR_NOSUCHNICK);
			return ;
		}

		if (isachan == true && channelExists(*itc) == false)
		{
			this->clientMessage(user, ERR_CANNOTSENDTOCHAN, *itc);
			return ;
		}

		//envoyer message aux clients
		if (isachan == false)
		{
			std::vector<User>::iterator ui = this->findUserIt(*itc);

			if (user.getNickName() != ui->getNickName())
				this->littleMessage(*ui, ":" + user.getNickName() + " PRIVMSG " + ui->getNickName() + " :" + message);
		}

		//envoyer message au channel
		else if (isachan == true)
		{
			std::vector<Channel>::iterator ci = this->findChannelIt(*itc);
			for (std::vector<User>::iterator itu = ci->users_list.begin(); itu != ci->users_list.end(); itu++)
			{
				if (user.getNickName() != itu->getNickName() && this->isInChannel(ci->getChannelName(), user.getNickName()) == true)
					this->littleMessage(*itu, ":" + user.getNickName() + " PRIVMSG " + ci->getChannelName() + " :" + message);	
			}		
		}
	}
}