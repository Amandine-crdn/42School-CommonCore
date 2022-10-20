#include "../Server.hpp"

void Server::userCmd(User &user, std::string msg)
{
	std::string username;
	
	username = msg.substr(5, msg.size() - 5);

	if (!username.size()) 
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS); 
		return;
	}
	if (user.getFirstConnexion() == false)
	{
		this->clientMessage(user, ERR_ALREADYREGISTRED);
		std::cout << "🇸🇯 30\n";
		return ;
	}
	user.setUserName(username);

//	std::cout << std::endl;
}
	
	
	
		/*if (first == true)
		{
			std::cout << "🇸🇯 3\n";
			this->quitCmd(user);
		}*/