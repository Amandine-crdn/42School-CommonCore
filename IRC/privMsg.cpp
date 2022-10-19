#include "Server.hpp"

void Server::privMsgCmd(User &user, std::string data) {

	std::string message = this->split(data, ':')[1];
	std::string clients = this->split(data.substr(8), ' ')[0];
	std::vector<std::string> client = this->split(clients, ',');

	if (!client.size() || !message.size()) { clientMessage(user, ERR_NEEDMOREPARAMS); return; }
		
		for (std::vector<std::string>::iterator itc = client.begin(); itc != client.end(); itc++)
		{
			//envoyer message aux clients
			for (std::map<int, User>::iterator itv = users_list.begin(); itv != users_list.end(); itv++) {
				if (itv->second.getNickName().compare(*itc) == 0 && user.getNickName() != itv->second.getNickName()) {
					std::stringstream result;
					result << ":" << user.getNickName() << " PRIVMSG " << itv->second.getNickName() << " :" << message << DELIMITER;
					std::string test = result.str(); 
					send(itv->first, test.c_str(), test.length(), 0);}}

			//envoyer message au channel
			for (std::vector<Channel>::iterator itchan = this->channels_list.begin(); itchan != this->channels_list.end(); itchan++) {				
				if (itchan->getChannelName().compare(*itc) == 0) {				
					for (std::map<int, User>::iterator itu = users_list.begin(); itu != users_list.end(); itu++) {
						for (std::vector<std::string>::iterator iterator = itu->second.channels_list_by_user.begin(); iterator != itu->second.channels_list_by_user.end(); iterator++) {
							if ((*iterator).compare(*itc) == 0 && user.getNickName() != itu->second.getNickName()) {
								std::stringstream result_chan;
								result_chan << ":" << user.getNickName() << " PRIVMSG " << itchan->getChannelName() << " :" << message << DELIMITER;
								std::string test = result_chan.str(); 
								send(itu->first, test.c_str(), test.length(), 0); }}}}}
		}
}