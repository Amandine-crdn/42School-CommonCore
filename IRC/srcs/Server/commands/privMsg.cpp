#include "../Server.hpp"

void Server::privMsgCmd(User &user, std::string data) {

	std::string message = this->split(data, ':')[1];
	std::string clients = this->split(data.substr(8), ' ')[0];
	std::vector<std::string> client = this->split(clients, ',');

	if (!client.size() || !message.size()) { clientMessage(user, ERR_NEEDMOREPARAMS); return; }
		
	/*	for (std::vector<std::string>::iterator itc = client.begin(); itc != client.end(); itc++)
		{
			//envoyer message aux clients
			for (std::vector<User>::iterator itv = utilisateurs_list.begin(); itv != utilisateurs_list.end(); itv++) {
				if (itv->getNickName().compare(*itc) == 0 && user.getNickName() != itv->getNickName()) {
					std::stringstream result;
					result << ":" << user.getNickName() << " PRIVMSG " << itv->getNickName() << " :" << message << DELIMITER;
					std::string test = result.str(); 
					send(itv->getFd(), test.c_str(), test.length(), 0);}}

			//envoyer message au channel
			for (std::vector<Channel>::iterator itchan = this->channels_list.begin(); itchan != this->channels_list.end(); itchan++) {				
				if (itchan->getChannelName().compare(*itc) == 0) {				
					for (std::vector<User>::iterator itu = utilisateurs_list.begin(); itu != utilisateurs_list.end(); itu++) {
						for (std::vector<std::string>::iterator iterator = itu->channels_list_by_user.begin(); iterator != itu->channels_list_by_user.end(); iterator++) {
							if ((*iterator).compare(*itc) == 0 && user.getNickName() != itu->getNickName()) {
								std::stringstream result_chan;
								result_chan << ":" << user.getNickName() << " PRIVMSG " << itchan->getChannelName() << " :" << message << DELIMITER;
								std::string test = result_chan.str(); 
								send(itu->getFd(), test.c_str(), test.length(), 0); }}}}}
		}*/
}