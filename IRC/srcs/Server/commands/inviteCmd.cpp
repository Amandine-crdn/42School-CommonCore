#include "../Server.hpp"

void Server::invitCmd(User &user, std::vector<std::string> data) {

	if (data.size() < 3) {
		this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }
	
	/*std::string username = data[1];
	std::string channel = data[2];
	bool find = false;
	std::map<int, User>::iterator itu; // refaire avec vector

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
	this->clientMessage(user, ERR_NOTONCHANNEL);*/
//RPL_AWAY
}
