#include "../Server.hpp"

void Server::operCmd(User &user, std::vector<std::string> data) {

	std::string opername = "opername";
	std::string operpass = "operpass";

	std::string name = data[1];
	std::string pass = data[2];


	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return;
	}

	if (name != opername || pass != operpass)
	{
		this->clientMessage(user, ERR_PASSWDMISMATCH);
		return;
	}

	user.setIRCOper(true);
	this->clientMessage(user, RPL_YOUREOPER);
} 
