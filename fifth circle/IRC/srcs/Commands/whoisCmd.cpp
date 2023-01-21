#include "../Server/Server.hpp"

void Server::whoisCmd(User &user, std::vector<std::string> data)
{
    if (data.size() < 2)
    {
		this->littleMessage(user, ":No nickname given");
        return ;
    }
    
    std::string nickname = data[1];

    if (this->isaChannel(nickname) == false && this->userExist(nickname) == false)
        this->clientMessage(user, ERR_NOSUCHNICK);
    else
    {
        this->clientMessage(user, RPL_WHOISREGNICK);
        this->clientMessage(user, RPL_WHOISUSER);
        if (user.getIRCOper() == true)
            this->clientMessage(user, RPL_WHOISOPERATOR);
        this->clientMessage(user, RPL_WHOISHOST);
        this->clientMessage(user, RPL_WHOISMODES);
        this->clientMessage(user, RPL_ENDOFWHOIS);
    }
}