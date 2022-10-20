#include "../Server.hpp"

void Server::modeCmd(User &user, std::vector<std::string> data)
{
	if (data.size() < 2) {
		this->clientMessage(user, ERR_NEEDMOREPARAMS); }

	/*#### channel mode #### */ 

	if (data[1][0] == '#')
	{
		std::string channel = data[1];


		bool correspondanceChannel = false;

		for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {
			if (channel == itc->getChannelName()) { correspondanceChannel = true; }}

		if (correspondanceChannel == false) { this->clientMessage(user, ERR_NOSUCHCHANNEL); return ;}
		
		if (data.size() <= 2) { this->clientMessage(user, RPL_CHANNELMODEIS, channel); return ; } //bien ler eturn ?

		/*---- mode #toto +o user ---- */ 

		if (data.size() == 4 && correspondanceChannel == true && data[2].compare("+o") == 0) 
		{
			std::string username = data[3];
			//check si c'est un IRCOPERATOR pour effectuer cette manoeuvre
			if (user.getIRCOper() == false) { this->clientMessage(user, ERR_NOPRIVILEGES); }
			else {
				for (std::vector<User>::iterator itv = utilisateurs_list.begin(); itv != utilisateurs_list.end(); itv++) {
					if (username == itv->getNickName()) {

						//si le new user a deja join le channel
						for (std::vector<std::string>::iterator itu = itv->channels_list_by_user.begin(); itu != itv->channels_list_by_user.end(); itu++) {
						if (channel == *itu) {
							//check s'il est deja channops de ce channel
							for (std::vector<std::string>::iterator itch = itv->channops.begin(); itch != itv->channops.end(); itch++) {
							std::cout <<  "itch = " <<*itch << "itu = " << *itu << std::endl;
							if (*itch == *itu) { std::cout << username << " est déjà Channops de : " << channel << std::endl; return ; }}	}} // est deja channops
							//donne les droits channops
							itv->channops.push_back(channel); //itv->setChannops(channel);
							itv->getChannops();
							std::cout << username << " devient Channops de : " << channel << std::endl; return ;}}
						//user non trouver
						this->clientMessage(user, ERR_USERNOTINCHANNEL, channel, username); }
		}
	}
//connect localhost 6667 coco
//OPER opername operpass
//mode #toto +o polain

	/*#### user mode #### */ 
	else
	{
		bool correspondanceUser = false;
		
		for (std::vector<User>::iterator itv = utilisateurs_list.begin(); itv != utilisateurs_list.end(); itv++) {
			if (data[1] == itv->getNickName()) { correspondanceUser = true; }}
		
		if (correspondanceUser == false) { this->clientMessage(user, ERR_NOSUCHNICK); }
		
		else if (data[1].compare(user.getNickName()) != 0) { this->clientMessage(user, ERR_USERSDONTMATCH); }
		
		else if (data[0].compare("MODE") == 0 && data[1].compare(user.getNickName()) == 0 && \
			data[2].compare("+i") == 0) {
			this->clientMessage(user, RPL_UMODEIS);
			user.setVisibility(false); return ;}
	}
	std::cout << "fail" << std::endl;
}
