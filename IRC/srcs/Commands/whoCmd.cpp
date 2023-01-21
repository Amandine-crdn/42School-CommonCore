#include "../Server/Server.hpp"

void Server::whoCmd(User &user, std::vector<std::string> data)
{
    std::string client = data[1];
    bool accept = false;

    if (this->channelExists(client) == false && this->userExist(client) == false)
    {
        this->clientMessage(user, ERR_NOSUCHSERVER, client);
        return ;
    }

    if (this->channelExists(client) == true)
    {
        std::vector<Channel>::iterator ci = findChannelIt(client);
        for (std::vector<User>::iterator it = ci->users_list.begin(); it != ci->users_list.end(); it++)
        {
            if (user.getNickName() == it->getNickName())
                accept = true;
        }

        for (std::vector<User>::iterator itu = ci->users_list.begin(); itu != ci->users_list.end(); itu++)
        {
            if (accept == true || itu->getVisibility() == true)
                this->littleMessage(user, "352 " + user.getNickName() + " " + client + " " + itu->getUserName() + " " + this->host + " " + this->server_name + " " + itu->getNickName() + " H :1 " + itu->getRealName());
        }
        
        this->clientMessage(user, RPL_ENDOFWHO, data[1]);
    }

    if (this->userExist(client) == true)
    {
        std::vector<User>::iterator ui = findUserIt(client);
        if (ui->getVisibility() == true)
            this->littleMessage(user, "311 " + user.getNickName() + " " + ui->getNickName() + " " + ui->getUserName() + " localhost 127.0.0.1*" + " :" + ui->getRealName());
    }

}