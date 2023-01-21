#include "../Server/Server.hpp"

void Server::namesCmd(User &user, std::vector<std::string> data)
{
    std::vector<std::string> channels = this->split(data[1], ',');

    bool accept = false;


    for(std::vector<std::string>::iterator itv = channels.begin(); itv != channels.end(); itv++)
    {
        if (this->channelExists(*itv) == false);
        else
        {
            std::vector<Channel>::iterator ci = this->findChannelIt(*itv);

            for (std::vector<User>::iterator it = ci->users_list.begin(); it != ci->users_list.end(); it++)
            {
                if (user.getNickName() == it->getNickName())
                    accept = true;
            }

            for (std::vector<User>::iterator itu = ci->users_list.begin(); itu != ci->users_list.end(); itu++)
            {
                if (accept == false && itu->getVisibility() == false);
                else
                    this->clientMessage(user, RPL_NAMREPLY, ci->getChannelName(), "@" + itu->getNickName());
            }

            this->clientMessage(user, RPL_ENDOFNAMES, ci->getChannelName());
        }
    }
}