#	include "CmdServer.hpp"

/* ------ Methods ------*/


std::string Server::passCmd(User &user, std::vector<std::string> data, bool first)
{
    std::string password = "";
	if (first == true) {
		if (data[1].compare(this->getPassword()) == 0) {
			std::cout << "\t\t✅ Great password" << std::endl; 
			return data[1]; }
		else {
			this->clientMessage(user, ERR_PASSWDMISMATCH);
			this->disconnected(user);}}

	else if (first == false) {
		this->clientMessage(user, ERR_ALREADYREGISTRED); }

    return password; 
}

// /connect localhost 6667 coco
std::string Server::nickCmd(User &user, std::string msg, bool first)
{
	std::string nickname = msg.substr(5, msg.size() - 5);

	if (!nickname.size()) {
		this->clientMessage(user, ERR_NEEDMOREPARAMS); return "";}

	if (nickname.size() > 9) {
		this->clientMessage(user, ERR_ERRONEUSNICKNAME, nickname); return ""; }
	else {
		std::map<int, User>::iterator itv;
		for (itv = users_list.begin(); itv != users_list.end(); itv++) {
			if (nickname == itv->second.getNickName()) {
				this->clientMessage(user, ERR_NICKNAMEINUSE, nickname);
				return ""; }}}
	if (first == false)
		user.setNickName(nickname);
    return nickname;
}

std::string Server::userCmd(User &user, std::string msg, bool first)
{
	std::string username = msg.substr(5, msg.size() - 5);

	if (!username.size()) {
		this->clientMessage(user, ERR_NEEDMOREPARAMS); return "";}

	if (first == false)
		this->clientMessage(user, ERR_ALREADYREGISTRED);

    return username;
}
// /connect localhost 6667 coco

void Server::modeCmd(User &user, std::vector<std::string> data)
{
	if (data.size() < 2) {
		this->clientMessage(user, ERR_NEEDMOREPARAMS); }

	/*#### channel mode #### */ 

	if (data[1][0] == '#')
	{
		std::string channel = data[1];
		std::string username = data[3];

		if (username.compare(user.getNickName()) == 0)
			return ; //no error for that ?

		bool correspondanceChannel = false;

		for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {
			if (channel == itc->getChannelName()) { correspondanceChannel = true; }}

		if (correspondanceChannel == false) { this->clientMessage(user, ERR_NOSUCHCHANNEL); return ;}
		
		if (data.size() <= 2) { this->clientMessage(user, RPL_CHANNELMODEIS, channel); return ; } //bien ler eturn ?

		/*---- mode #toto +o user ---- */ 

		if (data.size() == 4 && correspondanceChannel == true && data[2].compare("+o") == 0) 
		{
			//check si c'est un IRCOPERATOR pour effectuer cette manoeuvre
			if (user.getIRCOper() == false) { this->clientMessage(user, ERR_NOPRIVILEGES); }
			else {
				for (std::vector<User>::iterator itv = this->getUserList().begin(); itv != this->getUserList().end(); itv++) {
					
					std::cout << "*itv = " << itv->getNickName() << std::endl;
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
							std::cout << username << " devient Channops de : " << channel << std::endl; return ;}
						std::cout << "pas egale au suivant" << std::endl;}
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
		
		for (std::vector<User>::iterator itv = this->getUserList().begin(); itv != this->getUserList().end(); itv++) {
			if (data[1] == itv->getNickName()) { correspondanceUser = true; }}
		
		if (correspondanceUser == false) { this->clientMessage(user, ERR_NOSUCHNICK); }
		
		else if (data[1].compare(user.getNickName()) != 0) { this->clientMessage(user, ERR_USERSDONTMATCH); }
		
		else if (data[0].compare("MODE") == 0 && data[1].compare(user.getNickName()) == 0 && \
			data[2].compare("+i") == 0) {
			this->clientMessage(user, RPL_UMODEIS);
			user.setVisibility(false); return ;}
	}
}

void Server::quitCmd(User &user) 
{
	this->clientMessage(user, ERROR);
	this->disconnected(user);
}

void Server::pingCmd(User &user, std::vector<std::string> data)
{
	std::stringstream result; 
	std::string response;

	if (data.size() == 1) { this->clientMessage(user, ERR_NOORIGIN); }

	if (data[1] != "localhost") { this->clientMessage(user, ERR_NOSUCHSERVER); }
	
	else {
		result << server_name << " PONG :" << data[1] << DELIMITER; 
		response += result.str();
		send(user.getFd(), response.c_str(), response.size(), 0); }
}

void Server::joinCmd(User &user, std::vector<std::string> data)
{
	std::vector<std::string> new_data = this->split(data[1], ',');
	
	if (data.size() < 2){ this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }

	for (std::vector<std::string>::iterator itd = new_data.begin(); itd != new_data.end(); itd++)
	{
		bool correspondance = false;
		bool find = false;

		for (std::vector<Channel>::iterator itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {		
			if (itc->getChannelName() == *itd) {
				correspondance = true;
				clientMessage(user, RPL_TOPIC, itc->getChannelName(), itc->getTopic()); // get topic a donner : "Topic for : 
				for (std::vector<std::string>::iterator itu = user.channels_list_by_user.begin(); itu != user.channels_list_by_user.end(); itu++) {
					if (*itu == *itd) { find = true; }}}}	
		
		if (correspondance == false) {
			this->clientMessage(user, ERR_NOSUCHCHANNEL, *itd); 
			this->setChannelList(*itd);
			this->clientMessage(user, RPL_NOTOPIC, *itd, "No topic");
			//why erro no such nick en plus ??
			std::cout << "\n 🍑 The channel " << *itd << " was created" << std::endl; }
			
		if (correspondance == false || find == false) {
			user.setChannelListByUser(*itd); 
			this->notificationJoinChannel(user, *itd); // a revoir
			std::cout << "\t 🎈 You're channel's operator 🎈" << std::endl;
			user.setChannops(*itd);
			std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << *itd << " 🍀 " << std::endl; 
			this->notificationsUsersInChannel(user, *itd); } // a revoir
	}
}

///RMRECONNS !!

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

void Server::operCmd(User &user, std::vector<std::string> data) {

	std::string opername = "opername";
	std::string operpass = "operpass";

	std::string name = data[1];
	std::string pass = data[2];


	if (data.size() < 2){ this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }

	if (name != opername || pass != operpass) { this->clientMessage(user, ERR_PASSWDMISMATCH); return; }

	user.setIRCOper(true);
	this->clientMessage(user, RPL_YOUREOPER);
} 

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


void Server::partCmd(User &user, std::vector<std::string> data)
{
	if (data.size() != 2) { this->clientMessage(user, ERR_NEEDMOREPARAMS); return; } 
		// check if channops list, to delete inside

	std::vector<std::string> channels_list = this->split(data[1], ',');
	std::vector<std::string>::iterator end = channels_list.end();
	bool find;

	for (std::vector<std::string>::iterator itlist = channels_list.begin(); itlist != end; itlist++) {
		find = false;
		for (std::vector<std::string>::iterator itc = user.channels_list_by_user.begin(); itc != user.channels_list_by_user.end();) {
			if ((*itc).compare("#" + *itlist) == 0) {
				find = true;
				itc = user.channels_list_by_user.erase(itc); }
			else { ++itc; }
		if (find == false) { this->clientMessage(user, ERR_NOTONCHANNEL, *itlist); }}}
}

void Server::dieCmd(User &user, std::vector<std::string> data) { 

	if (data.size() > 1) { this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }

	if (user.getIRCOper() == false) { this->clientMessage(user, ERR_NOPRIVILEGES); return; }

	close(this->getServerFd()); // closing the connected socket
    shutdown(this->getServerFd(), SHUT_RDWR); // closing the listening socket
    std::cout << "🌙 🌙 closing with die command 🌙 🌙" << std::endl;
	exit (0);
}

void Server::adminCmd(User &user, std::vector<std::string> data) { 

	if (data.size() == 2) {
		if (data[1].compare(server_name)) {
			this->clientMessage(user, ERR_NOSUCHSERVER); return; }}
	this->clientMessage(user, RPL_ADMINME);
	this->clientMessage(user, RPL_ADMINLOC1);
	this->clientMessage(user, RPL_ADMINEMAIL);
}
 // /connect localhost 6667 coco

void Server::invitCmd(User &user, std::vector<std::string> data) {

	if (data.size() < 3) {
		this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }
	
	std::string username = data[1];
	std::string channel = data[2];
	bool find = false;
	std::map<int, User>::iterator itu;

	for (itu = users_list.begin(); itu != users_list.end(); itu++) {
		if (itu->second.getNickName().compare(username) == 0) { find = true; break; }}
	if (find == false) {
		this->clientMessage(user, ERR_NOSUCHNICK); return ; }

	//check si demandeur est sur le channel
	for (std::vector<std::string>::iterator itc = user.channels_list_by_user.begin(); itc != user.channels_list_by_user.end(); itc++)
	{
		if (("#" +  channel).compare(*itc) == 0) {
			//check si user est deja dessus
			for (std::vector<std::string>::iterator itl = itu->second.channels_list_by_user.begin(); itl != itu->second.channels_list_by_user.end(); itl++) {
				if (("#" + channel).compare(*itl) == 0) {
					this->clientMessage(user, ERR_USERONCHANNEL, channel, itu->second.getNickName()); return ; }}
			//c'est good
			this->clientMessage(user, RPL_INVITING, channel, username); return ;}
	}
	this->clientMessage(user, ERR_NOTONCHANNEL);
//RPL_AWAY
}

/*void Server::kickCmd(User &user, std::vector<std::string> data) {
	
	std::cout << "1" << std::endl;

	if (data.size() < 3) {
		this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }
	std::cout << "2" << std::endl;

	std::vector<std::string> channels_list = this->split(data[1], ',');
	std::vector<std::string> users_list = this->split(data[2], ',');

	std::cout << "yes" << std::endl;


}*/
//kick command : if OPERATOR == true , /KICK channel user (part un user d'un channel)
