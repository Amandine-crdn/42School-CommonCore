#include "../Server.hpp"

void Server::passCmd(User &user, std::vector<std::string> data, bool first)
{
	if (first == true)
	{
		if (data[1].compare(this->getPassword()) == 0)
			std::cout << "\t\t✅ Great password" << std::endl; 
		else
		{
			this->clientMessage(user, ERR_PASSWDMISMATCH);
			this->quitCmd(user);
		}
	}
	else if (first == false)
		this->clientMessage(user, ERR_ALREADYREGISTRED);
}