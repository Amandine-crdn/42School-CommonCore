#include "../Server/Server.hpp"

bool Server::channelExists(std::string channel)
{
    for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (channel == itc->getChannelName())
			return true;
	}
    return false;
}

void Server::clearAllChannel()
{
	for (std::vector<Channel>::iterator itu = this->channels_list.begin(); itu != this->channels_list.end();)
	{
		this->channels_list.erase(itu);
	}
}

void Server::setTopic(std::string channel, std::string topic) 
{
	std::vector<Channel>::iterator ci = this->findChannelIt(channel);
	ci->setTopic(topic);
}

std::string Server::getTopic(std::string channel)
{
	std::vector<Channel>::iterator ci = this->findChannelIt(channel);

	if (channel == ci->getChannelName() && ci->getTopic() != "")
		return ci->getTopic();
	
	return "";
}

void Server::toBeChannops(std::string nickname, std::string channel)
{
	std::vector<Channel>::iterator ci = this->findChannelIt(channel);
    
	for (std::vector<std::string>::iterator itu = ci->channops_list.begin(); itu != ci->channops_list.end(); itu++)
	{
		if (nickname == *itu) //deja channops
			return ;
	}
	ci->channops_list.push_back(nickname); // devient un des channops
}

void Server::eraseChannops(std::string nickname, std::string channel)
{
	std::vector<Channel>::iterator ci = this->findChannelIt(channel);

	for (std::vector<std::string>::iterator itu = ci->channops_list.begin(); itu != ci->channops_list.end();)
	{
		if (nickname == *itu)
			ci->channops_list.erase(itu);
		else
			itu++;
	}
      
}

bool Server::isChannops(std::string nickname, std::string channel)
{
	std::vector<Channel>::iterator ci = this->findChannelIt(channel);

	for (std::vector<std::string>::iterator itu = ci->channops_list.begin(); itu != ci->channops_list.end(); itu++)
	{
		if (nickname == *itu) //deja channops
			return true ;
	}
    return false;
}

void Server::addNewChannel(std::string new_channel)
{
	this->channels_list.push_back(Channel(new_channel));
}


void Server::delUserToChan(std::string nickname, std::string channel_name)
{
	std::vector<Channel>::iterator ci = this->findChannelIt(channel_name);
	
	for (std::vector<User>::iterator itu = ci->users_list.begin(); itu != ci->users_list.end();)
	{
		if (itu->getNickName() == nickname)
		{
			itu = ci->users_list.erase(itu);
			ci->delNbUser();
			if (ci->getNbUser() == 0)
				this->eraseChannel(channel_name);
			return ;
		}
		else
			itu++;
	}	
}

void Server::eraseChannel(std::string channel_name)
{
	for (std::vector<Channel>::iterator itc = channels_list.begin(); itc != channels_list.end();)
	{
		
		if (itc->getChannelName() == channel_name)
		{
			itc = this->channels_list.erase(itc);
			return ;
		}
		else
			itc++;
	}
}

bool Server::isaChannel(std::string channel)
{
	if (channel[0] == '#')
		return true;
	return false;
}
