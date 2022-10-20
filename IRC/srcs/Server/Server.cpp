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
}

void Server::dispatcher(User &user, std::string msg) //voir pour pointeur sur fonction + switch ?
{
	static int allow = 0; 

	std::vector<std::string> data = this->split(msg, ' ');

	if (allow == 0)
	{
		if (data[0].compare("CAP") == 0)
			allow = 1;
		return ;
	}
	else
	{
		if (data[0].compare("PASS") == 0)
			this->passCmd(user, data);
		else if (data[0].compare("NICK") == 0)
			this->nickCmd(user, msg, data);
		else if (data[0].compare("USER") == 0)
			this->userCmd(user, msg, data); 
		else if (data[0].compare("PING") == 0)
			this->pingCmd(user, data);
		else if (data[0].compare("MODE") == 0 && data[1][0] == '#')
			this->modeChannelCmd(user, data);
		else if (data[0].compare("MODE") == 0 && data[1][0] != '#')
			this->modeUserCmd(user, data);
		else if (data[0].compare("userhost") == 0) // ambigu avec USER
			this->userCmd(user, msg, data); //manque : "myusername myusername localhost :my real name"
		else if (data[0].compare("QUIT") == 0) 
			this->quitCmd(user);
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
			this->dieCmd(user, data);
		else if (data[0].compare("admin") == 0)
			this->adminCmd(user, data);
		else if (data[0].compare("INVITE") == 0)
			this->invitCmd(user, data);
		//else if (data[0].compare("KICK") == 0) 
		//	this->topicCmd(user, data); 
		else
		{
			std::cout << "ICI" << std::endl;
			this->clientMessage(user, ERR_UNKNOWNCOMMAND, data[0]);
		}
		this->check_connexion(user);
		// /connect localhost 6667 coco*/
	}

	data.clear();

	  std::vector<User>::iterator it = utilisateurs_list.begin();

        while (it != utilisateurs_list.end())
        {
            if (it->getFirstConnexion() == true && it->getDelete() == true)
            {
                close(it->getFd());
                it = utilisateurs_list.erase(it);
            }
            else
                it++;
        }
	
	std::cout << std::endl;
}
