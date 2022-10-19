#include "Server.hpp"

void Server::adminCmd(User &user, std::vector<std::string> data) { 

	if (data.size() == 2) {
		if (data[1].compare(server_name)) {
			this->clientMessage(user, ERR_NOSUCHSERVER); return; }}
	this->clientMessage(user, RPL_ADMINME);
	this->clientMessage(user, RPL_ADMINLOC1);
	this->clientMessage(user, RPL_ADMINEMAIL);
}