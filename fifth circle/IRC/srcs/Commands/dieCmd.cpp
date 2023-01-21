#include "../Server/Server.hpp"

extern bool run;

void Server::dieCmd(User &user)
{ 
    if (user.getIRCOper() == false)
    {
        this->clientMessage(user, ERR_NOPRIVILEGES);
        return;
    }

    run = false;
    std::cout << "🌙 🌙 closing with die command 🌙 🌙" << std::endl;
}
