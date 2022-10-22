#include "../Server.hpp"

void Server::kickCmd(User &user, std::vector<std::string> data)
{
    if (data.size() < 3)
    {
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
        return ;
    }

    std::vector<std::string> channels = this->split(data[1], ',');
    std::vector<std::string> users = this->split(data[2], ',');

    if (channels.size() != users.size())
    {
        this->clientMessage(user, ERR_BADCHANMASK, data[0]);
        return ;
    }

    if (channels.size() == 1) //1 channel , 1 ou plusieurs users
    {
        for (std::vector<std::string>::iterator itc = channels.begin(); itc != channels.end(); itc++)
        {
            std::string channel = *itc;

            if (user.isInChannel(channel) == false)
                this->clientMessage(user, ERR_NOTONCHANNEL, channel);
            
            if (this->channelExists(channel) == false)
                this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);

            if (this->isInChannel(channel, user.getNickName()) == false)
                this->clientMessage(user, ERR_USERNOTINCHANNEL, data[0]);


            if (user.getOpServer() == false) // voir quel privilege , channops ?? ou grace a oper ou les 2
                this->clientMessage(user, ERR_CHANOPRIVSNEEDED, data[0]);

            for (std::vector<std::string>::iterator itu = users.begin(); itu != users.end(); itu++)
            {
                this->delUserToChan(*itu, channel);
            }
        }
    }
    else if (channels.size() > 1) // plusieurs channels, 1 user par channel
    {
        std::vector<std::string>::iterator itc;
        std::vector<std::string>::iterator itu;
        for (itc = channels.begin(), itu = users.begin() ; itc != channels.end() && itu != users.end() ; itc++, itu++)
        {
            std::string channel = *itc;

            if (user.isInChannel(channel) == false)
                this->clientMessage(user, ERR_NOTONCHANNEL, channel);
            
            if (this->channelExists(channel) == false)
                this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);

            if (this->isInChannel(channel, user.getNickName()) == false)
                this->clientMessage(user, ERR_USERNOTINCHANNEL, data[0]);

            if (user.getOpServer() == false) // voir quel privilege , channops ?? ou grace a oper ou les 2
                this->clientMessage(user, ERR_CHANOPRIVSNEEDED, data[0]);

            this->delUserToChan(*itu, channel);
        }
    }
}