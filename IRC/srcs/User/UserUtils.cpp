#include "User.hpp"

			/*--- Utils Users -----*/

std::vector<User>::iterator Server::beginVectorUser()
{
	std::vector<User>::iterator itb;

	itb = utilisateurs_list.begin();
	return (itb);
}

std::vector<User>::iterator Server::endVectorUser()
{
	std::vector<User>::iterator ite;

	ite = utilisateurs_list.end();
	return (ite);
}

std::vector<User>::iterator Server::getUserByFd(int fd)
{ 
	std::vector<User>::iterator itb;

	for (itb = this->beginVectorUser(); itb != this->endVectorUser(); itb++)
	{
		if (itb->getFd() == fd)
			break ;
	}
	return (itb);
}


bool User::isInChannel(std::string channel)
{
    for (std::vector<std::string>::iterator itc = this->channelsJoin.begin(); itc !=  this->channelsJoin.end(); itc++)
    {
    	if (channel == *itc)
        {
            return true;
        }
    }
    return false;
}

void User::addChannel(std::string channel_name) //just allow to know if channops after
{
	this->channelsJoin.push_back(channel_name);	
}

void User::delUserToChan(std::string channel_name)
{
	for (std::vector<std::string>::iterator itc = this->channelsJoin.begin(); itc != this->channelsJoin.end();)
	{
		if (channel_name == *itc)
		{
            this->channelsJoin.erase(itc);
			return ;
		}
        else
            itc++;
	}
}

