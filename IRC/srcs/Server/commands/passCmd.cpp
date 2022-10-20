#include "../Server.hpp"

void Server::passCmd(User &user, std::vector<std::string> data)
{
	if (data.size() < 2)
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);

	if (user.getFirstConnexion() == true)
	{
		if (data[1].compare(this->getPassword()) == 0)
		{
			std::cout << "\t\t✅ Great password" << std::endl;
			user.setAllow(true);
		}
		else
		{
			this->clientMessage(user, ERR_PASSWDMISMATCH);
			return ;
		}
	}
	else
		this->clientMessage(user, ERR_ALREADYREGISTRED);
}