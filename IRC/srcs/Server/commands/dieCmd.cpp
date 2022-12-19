#include "../Server.hpp"

void Server::dieCmd(User &user)
{ 
	if (user.getIRCOper() == false)
    {
		this->clientMessage(user, ERR_NOPRIVILEGES);
		return;
    }

	close(this->getServerFd()); // closing the connected socket
    shutdown(this->getServerFd(), SHUT_RDWR); // closing the listening socket

    std::cout << "🌙 🌙 closing with die command 🌙 🌙" << std::endl;
    exit(0);
}
