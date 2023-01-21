#include "../Server/Server.hpp"

extern bool run;

void Server::squitCmd(User &user, std::vector<std::string> data)
{
    if (data.size() < 3)
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

    run = false;
    std::cout << "🌙 🌙 closing with squitCmd command 🌙 🌙" << std::endl;
}
