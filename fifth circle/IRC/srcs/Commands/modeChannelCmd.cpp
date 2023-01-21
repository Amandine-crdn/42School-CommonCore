#include "../Server/Server.hpp"

void Server::modeChannelCmd(User &user, std::vector<std::string> data)
{

/* 🍿🍿🍿 ------- Numerics Replies -------- 🍿🍿🍿*/

	if (data.size() < 2)
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS, data[0]);
		return ;
	}

	std::string channel = data[1];
	std::vector<Channel>::iterator ci = findChannelIt(channel); //tester avec channel qui n'existe pas

	std::string flag;
	std::string nickname;

	if (this->channelExists(channel) == false)
	{
		this->clientMessage(user, ERR_NOSUCHCHANNEL, channel);
		return ;
	}

	if (data.size() == 2)
	{
		for (std::vector<Channel>::iterator itc = channels_list.begin(); itc != channels_list.end(); itc++)
		{
			if (itc->getTopicProtec() == true)
				flag = "+t";
			else
				flag = "-t";
		}
		this->clientMessage(user, RPL_CHANNELMODEIS, channel, flag);
		return ;
	}

	if (isChannops(user.getNickName(), channel) == false)
	{
		this->clientMessage(user, ERR_CHANOPRIVSNEEDED, channel, "channops operator");
		return ;
	}





/* 🍿🍿🍿 ------- Messages -------- 🍿🍿🍿*/

	if (data.size() == 3) // +t -t
	{
		
		flag = data[2];
		
		if (flag == "+t")
		{
			ci->setTopicProtec(true);
			for (std::vector<User>::iterator itu = ci->users_list.begin(); itu != ci->users_list.end(); itu++)
			this->clientMessage(*itu, RPL_CHANNELMODEIS, channel, flag);
		}
		else if (flag == "-t")
		{
			ci->setTopicProtec(false);
			for (std::vector<User>::iterator itu = ci->users_list.begin(); itu != ci->users_list.end(); itu++)
			this->clientMessage(*itu, RPL_CHANNELMODEIS, channel, flag);
		}
		else
			this->clientMessage(user, ERR_UNKNOWNMODE, channel);
			
	}

	else if (data.size() == 4) // +o -o
	{
		flag = data[2];
		nickname = data[3];

		std::vector<User>::iterator ui = this->findUserIt(nickname);

		if (this->userExist(nickname) == false)
		{
			this->clientMessage(user, ERR_NOSUCHNICK, channel, nickname);
			return ;
		}

		if (this->isInChannel(channel, nickname) == false)
		{
			this->clientMessage(user, ERR_USERNOTINCHANNEL, channel, nickname);
			return ;
		}

		if (flag == "+o")
		{
			bool find = false;

			for (std::vector<std::string>::iterator its = ci->channops_list.begin(); its != ci->channops_list.end(); its++)
			{
				if (*its == nickname)
					find = true;
			}
			if (find == false)
			{	
				this->toBeChannops(ui->getNickName(), ci->getChannelName());

				for (std::vector<User>::iterator itt = ci->users_list.begin(); itt != ci->users_list.end(); itt++)
           		this->littleMessage(*itt, ": " + nickname + " is a new operator for " + channel);
			}
		}

		else if (flag == "-o")
		{
			for (std::vector<std::string>::iterator its2 = ci->channops_list.begin(); its2 != ci->channops_list.end();)
			{
				if (*its2 == nickname)
				{
					this->eraseChannops(ui->getNickName(), ci->getChannelName());

					for (std::vector<User>::iterator itx = ci->users_list.begin(); itx != ci->users_list.end(); itx++)
           			this->littleMessage(*itx, ": " + nickname + " is no longer operator for " + channel);
				}
				else
					its2++;
			}				
		}

		else
			this->clientMessage(user, ERR_UNKNOWNMODE, channel);
	}		
}
