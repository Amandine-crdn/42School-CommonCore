#include "../Server.hpp"

void Server::dieCmd(User &user, std::vector<std::string> data) { 

	(void)data;
	//if (data.size() > 1) { this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }

	//if (user.getIRCOper() == false) { this->clientMessage(user, ERR_NOPRIVILEGES); return; }

	//erase all users
	this->quitCmd(user);
	close(this->getServerFd()); // closing the connected socket
    shutdown(this->getServerFd(), SHUT_RDWR); // closing the listening socket
    std::cout << "🌙 🌙 closing with die command 🌙 🌙" << std::endl;
	exit (0);
}
