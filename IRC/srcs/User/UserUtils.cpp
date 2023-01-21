#include "User.hpp"

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

void Server::notificationsUsersInChannel(User &user, std::string channel_name)
{
	std::string utilisateur;
	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (itc->getChannelName()== channel_name)
		{
			for (std::vector<User>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
			{ 
				utilisateur += " " + itu->getNickName();
			}
		}
	}

	this->clientMessage(user, RPL_NAMREPLY, channel_name, utilisateur);
	this->clientMessage(user, RPL_ENDOFNAMES, channel_name);
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

void Server::setNbUser(User &user, std::string channel)
{
	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (channel == itc->getChannelName())
		{
			itc->setNbUser();
			itc->users_list.push_back(user);
		}
	}
}

int Server::getNbUser(std::string channel)
{
	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (channel == itc->getChannelName())
			return itc->getNbUser();
	}
	return 0;
}

bool Server::userExist(std::string username)
{
	for (std::vector<User>::iterator itu = utilisateurs_list.begin(); itu != utilisateurs_list.end(); itu++)
	{
		if (itu->getNickName() == username)
		{
			return true ;
		}
	}
	return false ;
}

void Server::setUser(int fd)
{
	utilisateurs_list.push_back(User(fd));
}

void Server::clearAllUser()
{
	for (std::vector<User>::iterator itu = this->utilisateurs_list.begin(); itu != this->utilisateurs_list.end();)
	{
		this->utilisateurs_list.erase(itu);
	}
}

void Server::clearUser(User &user)
{
	for (std::vector<User>::iterator itu = this->utilisateurs_list.begin(); itu != this->utilisateurs_list.end();)
	{
		if (itu->getNickName() == user.getNickName())
		{
			this->utilisateurs_list.erase(itu);
		}
		else
			itu++;
	}

}

bool Server::isInChannel(std::string channel, std::string nickname)
{
    for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc !=  this->channels_list.end(); itc++)
    {
		if (channel == itc->getChannelName())
		{
			for (std::vector<User>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
			{
				if (nickname == itu->getNickName())
					return true;
			}
		}
    }
    return false;
}

std::vector<User>::iterator Server::findUserIt(std::string nickname)
{
	std::vector<User>::iterator itu;
	for (itu = utilisateurs_list.begin(); itu != utilisateurs_list.end();itu++)
	{
		if (itu->getNickName() == nickname)
			return (itu);
	}
	return (itu);
}

std::vector<Channel>::iterator Server::findChannelIt(std::string channel)
{
	std::vector<Channel>::iterator itu;
	for (itu = channels_list.begin(); itu != channels_list.end();itu++)
	{
		if (itu->getChannelName() == channel)
			return (itu);
	}
	return (itu);
}


