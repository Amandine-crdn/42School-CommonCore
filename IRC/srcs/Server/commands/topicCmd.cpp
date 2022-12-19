#include "../Server.hpp"

void Server::topicCmd(User &user, std::string msg, std::vector<std::string> data)
{ 
	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]); // check erreur bizarre : You're not on that channel...
		return;
	} 

	std::string channel_name = data[1];
	
	if (user.isInChannel(channel_name) == false)
	{
		this->clientMessage(user, ERR_NOTONCHANNEL, channel_name);
		return ;
	}

	if (data.size() == 2)
	{
		if (this->getTopic(channel_name) == "No topic")
			this->clientMessage(user, RPL_NOTOPIC, channel_name);
		else
			this->clientMessage(user, RPL_TOPIC, channel_name, this->getTopic(channel_name));
		return ;
	}

	if (this->isChannops(user, channel_name) == false) // fait quitter le client de la fenetre du channel!! et apres ecrit no top
	{ // les notif de join se font apres surt le terminal... // et apres 2eme essai indique le msg
		this->clientMessage(user, ERR_CHANOPRIVSNEEDED, channel_name);
		return ;
	}

	std::string topic = this->split(msg, ':')[1];
	this->setTopic(channel_name, topic);
	//this->clientMessage(user, RPL_TOPIC, channel_name, this->getTopic(channel_name));
	
	//change poour les autres (channel origine ok), channel meme (joinchannel ne semble pas le changer)
}
