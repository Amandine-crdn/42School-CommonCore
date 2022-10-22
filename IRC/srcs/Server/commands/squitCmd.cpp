#include "../Server.hpp"

void Server::squitCmd(User &user, std::vector<std::string> data)
{
    if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return;
	}

    if (user.getIRCOper() == false)
    {
		this->clientMessage(user, ERR_NOPRIVILEGES);
		return;
    }

    if (data[1] != server_name)
	{
        this->clientMessage(user, ERR_NOSUCHSERVER);
        return ;
    }

    close(this->getServerFd()); // closing the connected socket
    shutdown(this->getServerFd(), SHUT_RDWR); // closing the listening socket
    
    std::cout << "🌙 🌙 closing with squitCmd command 🌙 🌙" << std::endl;

    exit(-1); // squit doit exit() ?
    
    //donc erase tous les user ou non necessaire a lafermeture

}
