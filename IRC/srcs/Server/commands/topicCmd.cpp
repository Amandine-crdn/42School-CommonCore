#include "../Server.hpp"

void Server::topicCmd(User &user, std::string msg, std::vector<std::string> data) { 

	std::string topic;
	std::string channel_name;

	if (data.size() < 2) { this->clientMessage(user, ERR_NEEDMOREPARAMS); return; } 

	if (data.size() == 2) {
		
		if (data[1] == "") { this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }
		
		else {
			channel_name = data[1];
			for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {
				if (itc->getChannelName() == ('#' + channel_name)) { itc->setTopic(""); return ; } }
				this->clientMessage(user, ERR_NOSUCHCHANNEL, channel_name); }}
	else {
		channel_name = data[1];
		topic = this->split(msg, ':')[1];
	
		for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {
			if (itc->getChannelName() == ('#' + channel_name)) {
				itc->setTopic(topic);
				this->clientMessage(user, RPL_TOPIC, itc->getChannelName(), itc->getTopic()); }}}
}
