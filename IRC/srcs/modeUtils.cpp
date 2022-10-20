#include "Server/Server.hpp"

bool Server::channelExists(std::string channel)
{
    for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (channel == itc->getChannelName())
			return true;
	}
    return false;
}

bool User::isInChannel(std::string channel)
{
    for (std::vector<Channel>::iterator itc = this->channelsJoin.begin(); itc !=  this->channelsJoin.end(); itc++)
    {
    	if (channel == itc->getChannelName())
            return true;
    }
    return false;
}

bool User::isChannops(std::string channel)
{
    for (std::vector<Channel>::iterator itb = this->OPSforchans.begin(); itb != this->OPSforchans.end(); itb++)
	{
		if (channel == itb->getChannelName())
			return true;
	}
    return false;
}

void User::toBeChannops(std::string channel)
{
    for (std::vector<Channel>::iterator itb = this->OPSforchans.begin(); itb != this->OPSforchans.end(); itb++)
	{
		if (channel == itb->getChannelName())
		{
            this->OPSforchans.push_back(*itb);
        }
	}
}

bool Server::userExists(std::string nickname)
{
    for (std::vector<User>::iterator itu = this->utilisateurs_list.begin(); itu != this->utilisateurs_list.end(); itu++)
    {
        if (itu->getNickName() == nickname)
            return true;
    }
    return false;
}
