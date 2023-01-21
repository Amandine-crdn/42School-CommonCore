#   include "Server.hpp"

void Server::checker() 
{
	for (std::vector<User>::iterator itb = this->beginVectorUser(); itb != this->endVectorUser(); itb++)
	{
		std::vector<std::string> msg = itb->getMsg();
		for (std::vector<std::string>::iterator itv = msg.begin(); itv != msg.end(); itv++)
		{
			std::cout << "\t🍇 IRSSI = >" << *itv << "<" << std::endl;
			this->dispatcher(*itb, *itv);
		}
		itb->clearMsg();
		msg.clear();
	}
	std::cout << std::endl;
}

void Server::dispatcher(User &user, std::string msg)
{
	std::vector<std::string> data = this->split(msg, ' ');

	if (user.getAllowCAP() == false)
	{
		if (data[0].compare("CAP") == 0)
			user.setAllowCAP(true);
		return ;
	}
	else
	{
		if (data[0].compare("PASS") == 0)
			this->passCmd(user, data);
		else if (data[0].compare("NICK") == 0)
			this->nickCmd(user, msg);
		else if (data[0].compare("USER") == 0)
			this->userCmd(user, msg, data); 
		else if (data[0].compare("PING") == 0)
			this->pingCmd(user, data);
		else if (data[0].compare("MODE") == 0 && this->isaChannel(data[1]) == true)
			this->modeChannelCmd(user, data);
		else if (data[0].compare("MODE") == 0 && this->isaChannel(data[1]) == false)
			this->modeUserCmd(user, data);
		else if (data[0].compare("userhost") == 0)
			this->userCmd(user, msg, data);
		else if (data[0].compare("QUIT") == 0) 
			this->quitCmd();
		else if (data[0].compare("JOIN") == 0)
			this->joinCmd(user, data);
		else if (data[0].compare("PART") == 0) 
			this->partCmd(user, data);
		else if (data[0].compare("PRIVMSG") == 0) 
			this->privMsgCmd(user, msg);
		else if (data[0].compare("OPER") == 0)
			this->operCmd(user, data); 
		else if (data[0].compare("TOPIC") == 0)
			this->topicCmd(user, msg, data); 
		else if (data[0].compare("die") == 0)
			this->dieCmd(user);
		else if (data[0].compare("admin") == 0)
			this->adminCmd(user, data);
		else if (data[0].compare("INVITE") == 0)
			this->invitCmd(user, data);
		else if (data[0].compare("NAMES") == 0)
			this->namesCmd(user, data);
		else if (data[0].compare("LIST") == 0)
			this->listCmd(user, data);
		else if (data[0].compare("squit") == 0)
			this->squitCmd(user, data);
		else if (data[0].compare("KICK") == 0)
			this->kickCmd(user, data); 
		else if (data[0].compare("time") == 0)
			this->timeCmd(user, data); 
		else if (data[0].compare("WHO") == 0)
			this->whoCmd(user, data); 
		else if (data[0].compare("WHOIS") == 0)
			this->whoisCmd(user, data); 
		else
		{
			std::cout << "Unknowcommand" << std::endl;
			this->clientMessage(user, ERR_UNKNOWNCOMMAND, data[0]);
		}
		this->check_connexion(user);
	}
	data.clear();
}
