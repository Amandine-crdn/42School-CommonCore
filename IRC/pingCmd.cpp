#include "Server.hpp"

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