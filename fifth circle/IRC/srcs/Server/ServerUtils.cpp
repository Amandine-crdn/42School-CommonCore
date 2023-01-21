#include "Server.hpp"

void Server::notificationJoinChannel(User &user, std::string channel_name) 
{
	for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++)
	{
		if (itc->getChannelName()== channel_name)
		{
			for (std::vector<User>::iterator itx = utilisateurs_list.begin(); itx != utilisateurs_list.end(); itx++)		
			{
				if (itx->getAllowPass() == true)
					this->littleMessage(*itx, ":" + user.getMask() + " JOIN " + channel_name); //meme a lui-même
			}
		}
	}
}

void Server::notificationPartChannel(User &user, std::string channel_name) 
{
	std::vector<Channel>::iterator ci = this->findChannelIt(channel_name);

	for (std::vector<User>::iterator itu = ci->users_list.begin(); itu != ci->users_list.end(); itu++)
	this->littleMessage(*itu, ":" + user.getMask() + " PART " + channel_name);	


}

void Server::notificationKickChannel(User &user, std::string channel_name, std::string nickname) 
{
	std::vector<Channel>::iterator ci = this->findChannelIt(channel_name);

	for (std::vector<User>::iterator itu = ci->users_list.begin(); itu != ci->users_list.end(); itu++)
	this->littleMessage(*itu, ":" + user.getMask() + " KICK " +  channel_name + " " + nickname);	
}

void Server::check_connexion(User &user)
{
	if (user.getFirstConnexion() == true && user.getNickName() != "" && user.getUserName() != "")
	{
		user.setFirstConnexion(false);
		this->clientMessage(user, RPL_WELCOME);

		std::stringstream params;
		std::string mask;

		params << user.getNickName() + "!" + user.getUserName() + "@localhost" ;
		mask += params.str();

		user.setMask(mask);
		this->littleMessage(user, ":" + user.getMask() + " NICK " + user.getNickName());
	}	
}

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

void Server::error(std::string error)
{
    std::cout << "🔥 " << error << std::endl;

// _pollfds.clear();

	for (std::vector<pollfd>::iterator it = this->_pollfds.begin(); it != this->_pollfds.end(); it++)
	{
		close(it->fd);
		// _pollfds.erase(it);

		/*else
			it++;*/
	}
	this->clearAllChannel();
	this->clearAllUser();
}
