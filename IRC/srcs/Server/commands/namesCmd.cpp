#include "../Server.hpp"

void Server::namesCmd(User &user, std::vector<std::string> data) // pas du tout fini avec les multi channel
{
    std::vector<std::string> channels = this->split(data[1], ',');

    std::string users;
    std::string final_string;

    for(std::vector<std::string>::iterator itv = channels.begin(); itv != channels.end(); itv++)
    {
       for (std::vector<Channel>::iterator itc = channels_list.begin(); itc != channels_list.end(); itc++)
        {
            if (itc->getChannelName() == *itv)
            {
                std::cout << "entrer" << std::endl;
                for (std::vector<std::string>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
                {
                    users += "@";
                    users += *itu;
                    users += " ";
                }
            }
            this->clientMessage(user, RPL_NAMREPLY, itc->getChannelName(), users);
            this->clientMessage(user, RPL_ENDOFNAMES, itc->getChannelName());
        }
        
           // this->notificationsUsersInChannel(user, channel);

    /* if (this->channelExists(channel) == false)
        {
            this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
            return ;
        }*/
    }
}