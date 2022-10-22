#include "../Server.hpp"

void Server::partCmd(User &user, std::vector<std::string> data)
{
	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return;
	} 
	
	std::vector<std::string> channels = this->split(data[1], ',');
	std::vector<std::string>::iterator end = channels.end();

	for (std::vector<std::string>::iterator itc = channels.begin(); itc != end; itc++)
	{
		std::string channel = *itc;
		
		if (this->channelExists(channel) == false)
		{
			this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
			return ;
		}
	
		if (user.isInChannel(channel) == false)
		{
			this->clientMessage(user, ERR_NOTONCHANNEL, channel);
			return ;
		}
		
		user.delUserToChan(channel);
		this->delUserToChan(user, channel);
	}
}

//envoyer une notif aux gens du channel (channeljoinnotifleave) ?
//quitte pas vraiment si on reste sur le channel ne se ferme pas
//bizarre