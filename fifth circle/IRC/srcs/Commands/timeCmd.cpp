#include "../Server/Server.hpp" 

void Server::timeCmd(User &user, std::vector<std::string> data)
{
    if (data.size() == 2 && data[1] != server_name)
        this->clientMessage(user, ERR_NOSUCHSERVER);
    
    this->clientMessage(user, RPL_TIME);
}
