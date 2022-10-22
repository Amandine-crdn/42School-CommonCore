#include "Server.hpp"

void Server::notificationJoinChannel(User &user, std::string channel_name) 
{
	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (itc->getChannelName()== channel_name)
		{
			for (std::vector<std::string>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
			{
				for (std::vector<User>::iterator itx = utilisateurs_list.begin(); itx != utilisateurs_list.end(); itx++)
				{
					if (itx->getNickName() == *itu && user.getNickName() != itx->getNickName()) // pas à lui-même
					{
						std::stringstream result_chan;
						result_chan << ":" << user.getFullClientIdentifier() << " JOIN " << channel_name << DELIMITER;
						std::string test = result_chan.str(); 
						send(itx->getFd(), test.c_str(), test.length(), 0);
					}
				}
			}
		}
	}
}

void Server::notificationsUsersInChannel(User &user, std::string channel_name)
{
	std::string users;

	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (itc->getChannelName()== channel_name)
		{
			for (std::vector<std::string>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
			{		 
				users += "@";
				users += *itu;
				users += " ";
			}
		}
	}

	this->clientMessage(user, RPL_NAMREPLY, channel_name, users);
	this->clientMessage(user, RPL_ENDOFNAMES, channel_name, users);
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

bool Server::channelExists(std::string channel)
{
    for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (channel == itc->getChannelName())
			return true;
	}
    return false;
}


void Server::setTopic(std::string channel, std::string topic) 
{
	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (channel == itc->getChannelName())
		{
			itc->setTopic(topic);
		}
	}
}

std::string Server::getTopic(std::string channel)
{
	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (channel == itc->getChannelName())
			return itc->getTopic();
	}
	return "No topic";
}


			/*--- Utils Channels -----*/

void Server::toBeChannops(User &user, std::string channel)
{
    for (std::vector<Channel>::iterator itb = this->channels_list.begin(); itb != this->channels_list.end(); itb++)
	{
		if (channel == itb->getChannelName())
		{
			for (std::vector<std::string>::iterator itu = itb->channops_list.begin(); itu != itb->channops_list.end(); itu++)
			{
				if (user.getNickName() == *itu) //deja channops
					return ;
			}
			itb->channops_list.push_back(user.getNickName()); // devient un des channops
           	itb->setChannop(true); // poubelle
        }
	}
}

bool Server::isChannops(User &user, std::string channel)
{
    for (std::vector<Channel>::iterator itb = this->channels_list.begin(); itb != this->channels_list.end(); itb++)
	{
		if (channel == itb->getChannelName())
		{
			for (std::vector<std::string>::iterator itu = itb->channops_list.begin(); itu != itb->channops_list.end(); itu++)
			{
				if (user.getNickName() == *itu) //deja channops
					return true ;
			}
        }
	}
    return false;
}

void Server::addNewChannel(std::string new_channel)
{
	this->channels_list.push_back(Channel(new_channel));
}

void Server::addUserToChan(User &user,std::string channel_name)
{
	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (channel_name == itc->getChannelName())
		{
			itc->users_list.push_back(user.getNickName());
			return ;
		}
	}
}

void Server::delUserToChan(User &user, std::string channel_name)
{
	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (channel_name == itc->getChannelName())
		{
			for (std::vector<std::string>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end();)
			{
				if (*itu == user.getNickName())
				{
					std::cout << "delete" << std::endl;
					itu = itc->users_list.erase(itu);
					if (itc->users_list.size() == 0)
						this->eraseChannel(channel_name);
					return ;
				}
				else
					itu++;
			}
		}
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

//

bool Server::isInChannel(std::string channel, std::string nickname)
{
    for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc !=  this->channels_list.end(); itc++)
    {
		if (channel == itc->getChannelName())
		{
			for (std::vector<std::string>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
			{
				if (nickname == *itu)
					return true;
			}
		}
    }
    return false;
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

void Server::clearUser(User &user)
{
	this->utilisateurs_list.erase(getUserByFd(user.getFd()));
}

void Server::check_connexion(User &user)
{
	if (user.getFirstConnexion() == true && user.getNickName() != "" && user.getUserName() != "")
	{
		user.setFirstConnexion(false);
		this->clientMessage(user, RPL_WELCOME);
	}	
}
//

std::vector<std::string> Server::split(std::string msg, char delimiter)
{
	std::vector<std::string> temp;
	if (msg.find(delimiter) == 0) {
		temp.push_back(msg);
		return (temp); }

	int increm = 0;
	int mem = 0;

	for(std::string::iterator it = msg.begin(); it != msg.end(); it++) {
		if (*it == delimiter) {
			temp.push_back(msg.substr(mem , increm - mem));
			mem = ++increm; }
		else
			increm++; }
		
	temp.push_back(msg.substr(mem , increm - mem));
	return temp;
}

void Server::error(std::string error) //change for error send ?
{
    //close and exit
    std::cout << "🔥 " << error << std::endl; //cf norme des erreurs
    
    // close tous les fd poll ??  close(itp->fd); ?

    // closing the connected socket   /// nned des 2 ?
    close(this->getServerFd());
    // closing the listening socket
    shutdown(this->getServerFd(), SHUT_RDWR);
    std::cout << "close with error" << std::endl;
    // prk destructor server no called when close ?
    exit (-1);
}

