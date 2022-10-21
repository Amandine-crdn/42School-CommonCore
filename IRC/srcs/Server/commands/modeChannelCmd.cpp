#include "../Server.hpp"

void Server::modeChannelCmd(User &user, std::vector<std::string> data)
{

			/*------- numerics replies for channel mode--------*/

	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return ;
	}

	std::string channel = data[1];
	std::cout << "channel = " << channel << std::endl;

	if (data.size() == 2)
	{
		this->clientMessage(user, ERR_NOCHANMODES, channel);
		return ;
	}

	if (this->channelExists(channel) == false)
	{
		this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
		return ;
	}

	if (user.isInChannel(channel) == false)
	{
		this->clientMessage(user, ERR_USERNOTINCHANNEL, channel, user.getNickName());
		return ;
	}

	if (user.isChannops(channel) == false)
	{
		this->clientMessage(user, ERR_CHANOPRIVSNEEDED, channel);
		return ;
	}

	if (data[2].compare("+o") != 0)
	{
		std::string str;
		if (data[2].size() == 2)
		{
			str.insert(0, 1, data[2][1]);
			this->clientMessage(user, ERR_UNKNOWNMODE, str);
		}
		else
		{
			str.insert(0, 1, data[2][0]);
			this->clientMessage(user, ERR_UNKNOWNMODE, str);
		}
		return ;
	}


					/*------------- MODE + o ---------------*/

	if (data.size() == 4)
	{
		std::string nickname = data[3];
		//si le nickname existe dans le serveur
		for (std::vector<User>::iterator itu = utilisateurs_list.begin(); itu != utilisateurs_list.end(); itu++) //findByNickname()
		{
			if (itu->isInChannel(channel) == false) //si le nickname fait parti du channel
			{
				this->clientMessage(user, ERR_USERNOTINCHANNEL, channel, itu->getNickName());
				return ;
			}
			if (itu->isChannops(channel) == false) //devient channops
			{
				itu->toBeChannops(channel);
				return ;
			}
		}	
	}
}
