#include "../Server.hpp"

void Server::namesCmd(User &user, std::vector<std::string> data)
{
    std::vector<std::string> channels = this->split(data[1], ',');

    std::string users;

    for(std::vector<std::string>::iterator itv = channels.begin(); itv != channels.end(); itv++)
    {
       for (std::vector<Channel>::iterator itc = channels_list.begin(); itc != channels_list.end(); itc++)
        {
            if (itc->getChannelName() == *itv)
            {
                for (std::vector<std::string>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
                {
                    users += "@";
                    users += *itu;
                    users += " ";
                }
                this->clientMessage(user, RPL_NAMREPLY, itc->getChannelName(), users);
                this->clientMessage(user, RPL_ENDOFNAMES, itc->getChannelName());
            }
        }
    }
}