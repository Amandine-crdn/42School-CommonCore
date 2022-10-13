#   include "Server.hpp"

void Server::commandResponces(User &user, std::string cmd)
{
	(void)cmd;
	std::stringstream result; 
	std::string response;

	result << "001" << " ";
	result << user.getNickName() << ":Welcome to the Internet Relay Chat Network, " ;
	result << DELIMITER;

	response += result.str();
	send(user.getFd(), response.c_str(), response.size(), 0); 
	//result.clear();
	//response.clear();
	//this->sendMessage();
}

std::vector<std::string> Server::split(std::string msg)
{
	std::vector<std::string> temp;
	int increm = 0;
	int mem = 0;
	std::string::iterator it;

	for(it = msg.begin(); it != msg.end(); it++)
	{
		if (*it == ' ') {
			temp.push_back(msg.substr(mem , increm - mem));
			mem = ++increm;
		}
		else
			increm++;
	}
	if (it == msg.end())
		temp.push_back(msg.substr(mem , increm - mem));
	return temp;
}

/*
void Server::sendMessage(void)
{
	std::cout << "----- sendMessage ------" << std::endl;
	for (std::map<int, User>::iterator itb = users_list.begin(); itb != users_list.end(); itb++)
	{
		if (itb->second._outputMessage.size() > 0)
			std::cout << "Sending fd: " << itb->first << " : >" << itb->second._outputMessage << "<" << std::endl;

		if(send(itb->first, itb->second._outputMessage.c_str(), itb->second._outputMessage.length(), 0) == -1)
			std::cout << "Send error " << std::endl; 
		// std::cout << "Finished sending User._outputMessage to fd : " << itb->first << std::endl;
		itb->second._outputMessage.clear();
	}
}*/