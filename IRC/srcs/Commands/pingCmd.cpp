#include "../Server/Server.hpp"

void Server::pingCmd(User &user, std::vector<std::string> data)
{

	if (data.size() == 0)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS);
		return ;
	}
	
	if (data.size() == 1)
	{
		this->clientMessage(user, ERR_NOORIGIN);
		return ;
	}

	if (data[1] != "localhost")
	{
		this->clientMessage(user, ERR_NOSUCHSERVER);
		return ;
	}
	

	this->littleMessage(user, server_name + " PONG :" + data[1]);
}