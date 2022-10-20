#   include "Server.hpp"

void Server::checker() 
{
	for (std::vector<User>::iterator itb = this->beginVectorUser(); itb != this->endVectorUser(); itb++)
	{
		std::cout << "User n ° : " << itb->getFd() << std::endl;
		std::cout << "Size Msg : " << itb->getMsg().size() << std::endl;
		
		std::vector<std::string> msg = itb->getMsg();
		for (std::vector<std::string>::iterator itv = msg.begin(); itv != msg.end(); itv++)
		{
			std::cout << "\t🌈send by user n °" << itb->getFd() << " : IRSSI = >" << *itv << "<" << std::endl;
			this->dispatcher(*itb, *itv);
		}
		itb->clearMsg();
		msg.clear();
		//this->quitCmd(*itb);
       // close(this->getServerFd()); // closing the connected socket
       // shutdown(this->getServerFd(), SHUT_RDWR); // closing the listening socket
       // std::cout << "🌙 🌙 closing with die command 🌙 🌙" << std::endl;
	}
}

void Server::dispatcher(User &user, std::string msg) //voir pour pointeur sur fonction + switch ?
{
	static int allow = 0; 

	std::vector<std::string> data = this->split(msg, ' ');

	if (data[0].compare("CAP") == 0)
		allow = 1;
	if (allow == 1)
	{
		if (data[0].compare("PASS") == 0)
			this->passCmd(user, data);
		else if (data[0].compare("NICK") == 0)
			this->nickCmd(user, msg);
		else if (data[0].compare("USER") == 0)
			this->userCmd(user, msg);
	
	if (user.getFirstConnexion() == true && user.getNickName() != "" && user.getUserName() != "")
	{
		user.setFirstConnexion(false);
		clientMessage(user, RPL_WELCOME);
	}	

		std::cout << "🍇 DISPATCHERRRR \n";


		if (data[0].compare("PING") == 0)
			this->pingCmd(user, data);
		/*if (data[0].compare("MODE") == 0)
			this->modeCmd(user, data);
		else if (data[0].compare("userhost") == 0) // ambigu avec USER
			this->userCmd(user, msg, 0); //manque : "myusername myusername localhost :my real name"
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
			this->clientMessage(user, ERR_UNKNOWNCOMMAND, data[0]);*/
		// /connect localhost 6667 coco*/
	}

	data.clear();

	
	
	std::cout << std::endl;
}
