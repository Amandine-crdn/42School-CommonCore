#include "Server/Server.hpp"

void User::addChannel(std::string channel_name)
{
	this->channelsJoin.push_back(Channel(channel_name));
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

void Server::notificationJoinChannel(User &user, std::string channel_name) 
{
	for (std::vector<User>::iterator itu = utilisateurs_list.begin(); itu != utilisateurs_list.end(); itu++) {
	for (std::vector<std::string>::iterator iterator = itu->channels_list_by_user.begin(); iterator != itu->channels_list_by_user.end(); iterator++) {
		if ((*iterator).compare(channel_name) == 0 && user.getNickName() != itu->getNickName()) { // pas a lui-meme
			
			std::stringstream result_chan;
			result_chan << ":" << user.getFullClientIdentifier() << " JOIN " << channel_name << DELIMITER;
			std::string test = result_chan.str(); 
			send(itu->getFd(), test.c_str(), test.length(), 0); }}}
}

void Server::notificationsUsersInChannel(User &user, std::string channel_name)
{
	std::string users = "";

	for (std::vector<User>::iterator itu = utilisateurs_list.begin(); itu != utilisateurs_list.end(); itu++)
	{
		for (std::vector<Channel>::iterator itc = itu->channelsJoin.begin(); itc != itu->channelsJoin.end(); itc++)
		{
			if (itc->getChannelName() == channel_name)
			{
				users += "@";
				users += itu->getNickName();
				users += " ";
			}
		}
	}

	this->clientMessage(user, RPL_NAMREPLY, channel_name, users);
	this->clientMessage(user, RPL_ENDOFNAMES, channel_name, users);
}
