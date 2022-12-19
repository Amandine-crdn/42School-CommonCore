#include "../Server.hpp"       

void Server::listCmd(User &user, std::vector<std::string> data)
{
    if (data.size() == 1 || data[1].compare("-YES") == 0)
    {
        for (std::vector<Channel>::iterator itc = channels_list.begin(); itc != channels_list.end(); itc++)
        {
            this->clientMessage(user, RPL_LIST, itc->getChannelName(), itc->getTopic());
        }
        this->clientMessage(user, RPL_LISTEND);
    }
    else
    {
        std::vector<std::string> channels = this->split(data[1], ',');

        for(std::vector<std::string>::iterator itv = channels.begin(); itv != channels.end(); itv++)
        {
            if (this->channelExists(*itv) == true)
            {
                for (std::vector<Channel>::iterator itc = channels_list.begin(); itc != channels_list.end(); itc++)
                {
                    if (itc->getChannelName() == *itv)
                        this->clientMessage(user, RPL_LIST, itc->getChannelName(), itc->getTopic());
                }
            }
        }
        this->clientMessage(user, RPL_LISTEND);
    }
}
