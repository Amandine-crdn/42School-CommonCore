#   include "Server.hpp"

void Server::checker(User &user, std::vector<std::string> messages)
{
	switch (user.getFirstConnexion())
	{
		case true : {
			this->firstConnexion(user, messages);
			clientMessage(user, RPL_WELCOME); break ; }
		case false : dispatcher(user, messages); break ;
	}
}

void Server::firstConnexion(User &user, std::vector<std::string> messages) 
{
	std::vector<std::string>::iterator itm;
	std::string password = "";
	std::string nickname = "";
	std::string username = "";
	static int allow = 0; 

	for (itm = messages.begin() ; itm != messages.end(); itm++)
	{
		std::string msg = *itm;
		std::vector<std::string> data = this->split(msg, ' ');
		
		std::cout << "\t🪶  🖥️  IRSSI = >" << *itm << "<" << std::endl;
		if (data[0].compare("CAP") == 0)
			allow = 1;
		if (allow == 1)
		{
			if (data[0].compare("PASS") == 0)
				password = this->passCmd(user, data, 1);
			else if (data[0].compare("NICK") == 0)
				nickname = this->nickCmd(user, msg, 1);
			else if (data[0].compare("USER") == 0)
				username = this->userCmd(user, msg, 1);
		}
	}
		
	if (nickname == "" || username == "" || password == "")
		this->disconnected(user);
	else {
		user.setNickName(nickname); 
		user.setUserName(username);
		user.setFirstConnexion(false); }

	std::cout << std::endl;
}

// /connect localhost 6667 coco

void Server::dispatcher(User &user, std::vector<std::string> messages)
{
	std::vector<std::string>::iterator itm;

	for (itm = messages.begin() ; itm != messages.end(); itm++)
	{
		std::string msg = *itm;
		std::vector<std::string> data = this->split(msg, ' ');
		
		std::cout << "\t🪶  🖥️  IRSSI = >" << *itm << "<" << std::endl;

		if (data[0].compare("MODE") == 0)
			this->modeCmd(user, data);
		else if (data[0].compare("PASS") == 0)
			this->passCmd(user, data, 0);
		else if (data[0].compare("NICK") == 0)
			this->nickCmd(user, msg, 0);
		else if (data[0].compare("userhost") == 0)
			this->userCmd(user, msg, 0); //manque : "myusername myusername localhost :my real name"
		else if (data[0].compare("QUIT") == 0) 
			this->quitCmd(user);
		else if (data[0].compare("PING") == 0)
			this->pingCmd(user, data);
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
		/*else if (data[0].compare("KICK") == 0)
			this->topicCmd(user, data); */
		else
			this->clientMessage(user, ERR_UNKNOWNCOMMAND, data[0]);
	
		data.clear();
	}

	messages.clear();
	std::cout << std::endl;

}


void Server::disconnected(User &user)
{
	getpeername(user.getFd(), (struct sockaddr *)&my_addr, (socklen_t *)&peer_addr_size);
	std::cout << "🌙 " << user.getNickName() << " was disconnected , ip " << inet_ntoa(my_addr.sin_addr) << " , port " << ntohs(my_addr.sin_port) << std::endl;
	close(user.getFd());
	users_list.erase(user.getFd());
}