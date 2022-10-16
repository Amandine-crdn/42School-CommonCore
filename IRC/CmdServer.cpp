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
		this->clientMessage(user, ERR_ERRONEUSNICKNAME); return ""; }
	else {
		std::map<int, User>::iterator itv;
		for (itv = users_list.begin(); itv != users_list.end(); itv++) {
			if (nickname == itv->second.getNickName()) {
				this->clientMessage(user, ERR_NICKNAMEINUSE);
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

void Server::modeCmd(User &user, std::vector<std::string> data)
{
	bool correspondance = false;
	std::map<int, User>::iterator itv;
    for (itv = users_list.begin(); itv != users_list.end(); itv++) {
    	if (data[1] == itv->second.getNickName()) {
			correspondance = true; }}

	if (data[0].compare("MODE") == 0 && correspondance == false)
		this->clientMessage(user, ERR_NOSUCHNICK);
	else if (data[0].compare("MODE") == 0 && data[1].compare(user.getNickName()) != 0)
		this->clientMessage(user, ERR_USERSDONTMATCH);
	else if (data[0].compare("MODE") == 0 && data[1].compare(user.getNickName()) == 0 && \
		data[2].compare("+i") == 0) {
		this->clientMessage(user, RPL_UMODEIS);
		user.setVisibility(false); }
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

	if (data.size() == 1)
		this->clientMessage(user, ERR_NEEDMOREPARAMS);
	else { // comment etre sur que cela repond bien au ping ?
		result << server_name << " PONG :" << data[1] << DELIMITER; 
		response += result.str();
		send(user.getFd(), response.c_str(), response.size(), 0); }
}

void Server::joinCmd(User &user, std::vector<std::string> data)
{
	std::vector<std::string>::iterator itd;
	std::vector<Channel>::iterator itc;
	std::vector<std::string>::iterator itu;

	std::vector<std::string> new_data = this->split(data[1], ',');
	
	if (data.size() < 2){
		this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }

	for (itd = new_data.begin(); itd != new_data.end(); itd++)
	{
		bool correspondance = false;
		bool find = false;

		for (itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {		
			if (itc->getChannelName() == *itd) {
				correspondance = true;
				for (itu = user.channels_list_by_user.begin(); itu != user.channels_list_by_user.end(); itu++) {
					if (*itu == *itd) {
						find = true; }}
				if (find == false) {
					user.setChannelListByUser(*itd); }}}//clientMessage(user, RPL_TOPIC, *itd, itc->getTopic()); // get topic a donner : "Topic for : "
				 
		if (correspondance == false) {
			this->clientMessage(user, ERR_NOSUCHCHANNEL, *itd, ""); 
			this->setChannelList(*itd);
			std::cout << "\n 🍑 The channel " << *itd << " was created" << std::endl; }
			
		if (correspondance == false || find == false) {
			user.setChannelListByUser(*itd);
			this->notificationJoinChannel(user, *itd);
			std::cout << "\t 🍀 " << user.getNickName() << "! Welcome to "  << *itd << " 🍀 " << std::endl; //std::cout << "\t 🎈 🎈  🎈 Congratulations you're channel's operator 🎈 🎈 🎈" << std::endl;
			this->clientMessage(user, RPL_NOTOPIC, *itd, "");
			this->notificationsUsersInChannel(user, *itd); }

			// add topic
			for (itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {		
			if (itc->getChannelName() == *itd)
				itc->setTopic(""); } // ou le set dans le constructeur de channel (verifi si constructeur appeler)
	}
}

///RMRECONNS !!

// /connect localhost 6667 coco

void Server::privMsgCmd(User &user, std::string data) {

	std::string message = this->split(data, ':')[1];
	std::string clients = this->split(data.substr(8), ' ')[0];
	std::vector<std::string> client = this->split(clients, ',');

	if (!client.size() || !message.size()) {
		clientMessage(user, ERR_NEEDMOREPARAMS); return; }
		
		for (std::vector<std::string>::iterator itc = client.begin(); itc != client.end(); itc++)
		{
			//envoyer message aux clients
			for (std::map<int, User>::iterator itv = users_list.begin(); itv != users_list.end(); itv++) {
				if (itv->second.getNickName().compare(*itc) == 0 && user.getNickName() != itv->second.getNickName()) {
					std::stringstream result;
					result << ":" << user.getNickName() << " PRIVMSG " << *itc << " :" << message << DELIMITER;
					std::string test = result.str(); 
					send(itv->first, test.c_str(), test.length(), 0); }} // proteger send -1 🖕

			//envoyer message au channel
			for (std::vector<Channel>::iterator itchan = this->channels_list.begin(); itchan != this->channels_list.end(); itchan++) {				
				if (itchan->getChannelName().compare(*itc) == 0) { // pracourir les user si channel envoyer avec son fd					
					for (std::map<int, User>::iterator itu = users_list.begin(); itu != users_list.end(); itu++) {
						for (std::vector<std::string>::iterator iterator = itu->second.channels_list_by_user.begin(); iterator != itu->second.channels_list_by_user.end(); iterator++) {
							if ((*iterator).compare(*itc) == 0 && user.getNickName() != itu->second.getNickName()) {// sauf a lui-même
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


	if (data.size() < 2){
		this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }

	if (name != opername || pass != operpass) {
		this->clientMessage(user, ERR_PASSWDMISMATCH); return; }

	user.setIRCOper(true);
	this->clientMessage(user, RPL_YOUREOPER);
} 


void Server::topicCmd(User &user, std::string msg, std::string channel_name) { 

	std::string topic = this->split(msg, ':')[1];

	std::vector<Channel>::iterator itc;
	for (itc = this->channels_list.begin(); itc != this->channels_list.end(); itc++) {
			if (itc->getChannelName() == '#' + channel_name) { 
				itc->setTopic(topic);
			 	this->clientMessage(user, RPL_TOPIC, channel_name, topic); }}
}

// /connect localhost 6667 coco
 


void Server::partCmd(User &user, std::vector<std::string> data)
{
	if (data.size() > 2) {
		this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }

	std::vector<std::string> channels_list = this->split(data[1], ',');
	std::vector<std::string>::iterator end = channels_list.end();

	for (std::vector<std::string>::iterator itlist = channels_list.begin(); itlist != end; itlist++) {
		for (std::vector<std::string>::iterator itc = user.channels_list_by_user.begin(); itc != user.channels_list_by_user.end();) {
			if ((*itc).compare("#" + *itlist) == 0) {
				itc = user.channels_list_by_user.erase(itc); } // supprimer le channel de la liste des channel du user
			else {
				++itc; }}}
}