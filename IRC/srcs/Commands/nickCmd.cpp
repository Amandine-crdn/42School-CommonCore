 #include "../Server/Server.hpp"

void Server::nickCmd(User &user, std::string msg)
{
	if (user.getAllowPass() == false)
	{
		this->littleMessage(user, "Error NICK : not accepted");
		return ;
	}

	std::string nickname = msg.substr(5, msg.size() - 5);
	if (userExist(nickname) == true && user.getFirstConnexion() == true)
	{
		this->littleMessage(user, "Error NICK : not accepted");
		user.setAllowNick(false);
		return ;
	}

	for (std::vector<User>::iterator itv = utilisateurs_list.begin(); itv != utilisateurs_list.end(); itv++)
	{
		if (nickname == itv->getNickName())
		{
			if (user.getFirstConnexion() == true)
				user.setAllowPass(false);
			this->clientMessage(user, ERR_NICKNAMEINUSE, nickname);
			return ;
		}
	}

	if (nickname.size() > 9)
	{
		this->clientMessage(user, ERR_ERRONEUSNICKNAME, nickname);
		return ;
	}

	if (user.getFirstConnexion() == false)
	{
		std::stringstream params;
		std::stringstream params2;

		for (std::vector<Channel>::iterator itc = this->channels_list.begin() ; itc != this->channels_list.end(); itc++)
		{
			for (std::vector<User>::iterator itu = itc->users_list.begin(); itu != itc->users_list.end(); itu++)
			{
				if (itu->getNickName() == user.getNickName())
				{
					itu->setNickName(nickname);
				}
			}
			for (std::vector<std::string>::iterator its = itc->channops_list.begin(); its != itc->channops_list.end(); its++)
			{
				if (*its == user.getNickName())
				{
					*its = nickname;
				}
			}
		}

		params << user.getNickName() + "!" + user.getUserName() + "@" + this->host;
		this->littleMessage(user, ":" + params.str() + " NICK " + nickname);
		user.setNickName(nickname);
		params2 << user.getNickName() + "!" + user.getUserName() + "@" + this->host;
		
		user.setMask(params2.str());
		
	}
	else
	{
		user.setNickName(nickname);
		user.setAllowNick(true);
	}
}
/*CAP LS 
PASS coco
NICK glavio
USER glavio: glaviette*/