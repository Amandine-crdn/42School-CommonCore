#include "../Server.hpp" 

void Server::timeCmd(User &user, std::vector<std::string> data)
{
    if (data.size() == 1)
       this->clientMessage(user, RPL_TIME);
    else if (data.size() == 2)
    {
        if (data[1] != server_name)
            this->clientMessage(user, ERR_NOSUCHSERVER);
        else
            this->clientMessage(user, RPL_TIME);
    }
}
