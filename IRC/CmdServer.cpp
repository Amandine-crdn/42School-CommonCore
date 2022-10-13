#	include "CmdServer.hpp"

/* ------ Methods ------*/


std::string Server::passCmd(User &user, std::vector<std::string> data, bool first)
{
    std::string password = "";
	if (first == true) {
		if (data[1].compare(this->getPassword()) == 0) {
			password = data[1];
			std::cout << "\t\t✅ Great password" << std::endl; }
		else {
			this->clientMessage(user, ERR_PASSWDMISMATCH);
			this->disconnected(user);}}

	else if (first == false) {
		clientMessage(user, ERR_ALREADYREGISTRED); }

    return password; 
}

std::string Server::nickCmd(User &user, std::vector<std::string> data, bool first)
{
	std::string nickname = "";
	std::vector<std::string>::iterator d;

	for (d = ++data.begin(); d != data.end(); d++){
		nickname.append(*d);
		if (d != data.end() - 1)
			nickname.push_back(' ');}
	if (nickname.size() > 9) {
		this->clientMessage(user, ERR_ERRONEUSNICKNAME);
		if (first == true) {
			this->disconnected(user); return ""; }}
	else {
		std::map<int, User>::iterator itv;
		for (itv = users_list.begin(); itv != users_list.end(); itv++) {
			if (nickname == itv->second.getNickName()) {
				std::cout << "🥶 " << std::endl; // message erreur ne se voit pas??
				this->clientMessage(user, ERR_NICKNAMEINUSE);
				if (first == true) {
					this->disconnected(user); return ""; }}}}
	if (first == false)
		user.setNickName(nickname);
    return nickname;
}

std::string Server::userCmd(User &user, std::vector<std::string> data, bool first)
{ 
	std::string username = "";
	if (first == true) {
    std::vector<std::string>::iterator d;
	for (d = ++data.begin(); d != data.end(); d++){
		username.append(*d);
		if (d != data.end() - 1)
			username.push_back(' '); }}

	else if (first == false)
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
		clientMessage(user, ERR_NOSUCHNICK);
	else if (data[0].compare("MODE") == 0 && data[1].compare(user.getNickName()) != 0)
		clientMessage(user, ERR_USERSDONTMATCH);
	else if (data[0].compare("MODE") == 0 && data[1].compare(user.getNickName()) == 0 && \
		data[2].compare("+i") == 0) {
		clientMessage(user, RPL_UMODEIS);
		user.setVisibility(false); }
}

void Server::quitCmd(User &user, std::vector<std::string> data)
{
	std::cout << "🌙 " << std::endl;
	(void)data;
	clientMessage(user, ERROR);
	// close fd and disconnected hote
}

void Server::pingCmd(User &user, std::vector<std::string> data)
{
	std::stringstream result; 
	std::string response;

	if (data.size() == 1)
		clientMessage(user, ERR_NEEDMOREPARAMS);
	else { // comment etre sur que cela repond bien au ping ?
		result << server_name << " PONG :" << data[1] << DELIMITER; 
		response += result.str();
		send(user.getFd(), response.c_str(), response.size(), 0); }
}

void Server::joinCmd(User &user, std::vector<std::string> data)
{
	std::vector<std::string>::iterator itd;
	std::vector<std::string>::iterator itc;
	std::vector<std::string>::iterator itu;

	std::vector<std::string> new_data = this->split(data[1], ',');
	
	// 1 check si la liste des input  existe dans la liste des channels
	for (itd = new_data.begin(); itd != new_data.end(); itd++) {
		bool correspondance = false;
		for (itc = this->getChannelList().begin(); itc != this->getChannelList().end(); itc++) {			
			if (*itd == *itc) {
				std::cout << "find !" << std::endl; // check sil existe pour le user pour le add
				correspondance = true;
				for (itu = user.getChannelList().begin(); itu != user.getChannelList().end() && *itd != *itu; itu++) ;
				if (itu != user.getChannelList().end()) {
					std::cout << "add for this user = " << *itu << std::endl;
					user.setChannelList(*itd); }} //channel is add to channellist for this user

		if (correspondance == false) {
			// thischannel <channel_name> is created now
			// <nickname> you join thischannel <channel_name>
			std::cout << "not find => " << *itd << std::endl;
			this->setChannelList(*itd); }}} //channel is add to channellist for server
}
