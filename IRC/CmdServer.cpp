#include "Server.hpp"

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
			if (first == true)
				this->disconnected(user);
			return "";}
		else {
			std::map<int, User>::iterator itv;
			for (itv = users_list.begin(); itv != users_list.end(); itv++) {
				if (nickname == itv->second.getNickName()) {
				{
					std::cout << "🥶 " << std::endl;
					this->clientMessage(user, ERR_NICKNAMEINUSE);
					if (first == true)
						this->disconnected(user);
					return ""; }}}}

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