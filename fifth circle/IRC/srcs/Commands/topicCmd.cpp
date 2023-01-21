#include "../Server/Server.hpp"

void Server::topicCmd(User &user, std::string msg, std::vector<std::string> data)
{ 

	std::string channel_name = data[1];

	if (this->channelExists(channel_name) == false)
	{
		this->clientMessage(user, ERR_NOSUCHCHANNEL, channel_name);
		return ;
	}

	if (data.size() == 2 && channel_name.compare("") == 0)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return;
	} 
	
	if (this->isInChannel(channel_name, user.getNickName()) == false)
	{
		this->clientMessage(user, ERR_NOTONCHANNEL,channel_name);
		return ;
	}

	if (data.size() == 2)
	{
		if (this->getTopic(channel_name) == "")
			this->clientMessage(user, RPL_NOTOPIC, channel_name);
		else if (this->getTopic(channel_name) != "")
			this->clientMessage(user, RPL_TOPIC,channel_name, this->getTopic(channel_name));
		return ;
	}

	std::string topic = this->split(msg, ':')[1];
	std::vector<Channel>::iterator ci = this->findChannelIt(channel_name);

	if (ci->getTopicProtec() == true && this->isChannops(user.getNickName(), channel_name) == false)  
	{
		this->clientMessage(user, ERR_CHANOPRIVSNEEDED,channel_name, "channel operator");
		return ;
	}
	this->setTopic(channel_name, topic);

	for (std::vector<User>::iterator itu = ci->users_list.begin(); itu != ci->users_list.end(); itu++)
	this->clientMessage(*itu, RPL_TOPIC, channel_name, this->getTopic(channel_name));
	
}
