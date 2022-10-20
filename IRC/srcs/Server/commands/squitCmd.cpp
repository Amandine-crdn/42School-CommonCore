#include "../Server.hpp"

void Server::squitCmd(User &user, std::vector<std::string> data)
{
    if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[1]);
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
    exit(-1); // squit doit exit() ?

}
