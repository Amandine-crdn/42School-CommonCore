#include "../Server/Server.hpp"

void Server::kickCmd(User &user, std::vector<std::string> data)
{
    if (data.size() < 3)
    {
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
        return ;
    }
    std::string channel = data[1];

    std::cout << YELLOW << "channel: " << channel << END << std::endl;

    if (user.getIRCOper() == false)
    {
        this->clientMessage(user, ERR_CHANOPRIVSNEEDED, data[0], "irc operator");
        return ;
    }

    if (this->isaChannel(channel) == false)
    {
        this->clientMessage(user, ERR_BADCHANMASK, channel);
        return ;
    }

    if (this->channelExists(channel) == false)
    {
        this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
        return ;
    }

    if (this->isInChannel(channel, user.getNickName()) == false)
    {
        this->clientMessage(user, ERR_NOTONCHANNEL, channel);
        return ;
    }


    std::vector<std::string> users = this->split(data[2], ',');

    for (std::vector<std::string>::iterator itu = users.begin(); itu != users.end(); itu++)
    {
        if (this->isInChannel(channel, *itu) == false)
            this->clientMessage(user, ERR_USERNOTINCHANNEL, data[0]);
        else
        {
            this->notificationKickChannel(user, channel, *itu);
            this->delUserToChan(*itu, channel);
        }
    }
}