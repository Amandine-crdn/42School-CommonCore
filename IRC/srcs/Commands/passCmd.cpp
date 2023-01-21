#include "../Server/Server.hpp"

extern bool run;

void Server::passCmd(User &user, std::vector<std::string> data)
{
	if (data.size() == 0)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]); 
		return;
	}

	if (user.getFirstConnexion() == true)
	{
		if (data[1].compare(this->getPassword()) == 0)
		{
			std::cout << "\t\t✅ Great password" << std::endl;
			user.setAllowPass(true);
		}
		else
		{
			this->clientMessage(user, ERR_PASSWDMISMATCH);
			this->littleMessage(user, "ERROR :Not good password ; Server close the connexion");
			//close the connexion
			getpeername(user.getFd(), (struct sockaddr *)&_sin, (socklen_t *)&_sizeofsin);
			std::cout << "Host disconnected , ip " << inet_ntoa(_sin.sin_addr) << " , port " << ntohs(_sin.sin_port) << std::endl;
			user.setAllowPass(false);
			return ;
		}
	}
	else
		this->clientMessage(user, ERR_ALREADYREGISTRED);
}