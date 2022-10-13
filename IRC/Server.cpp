#include "Server.hpp"

void Server::checker(User &user, std::vector<std::string> messages)
{
	std::cout << "----- checker ------" << std::endl;

	switch (user.getFirstConnexion())
	{
		case true : this->firstConnexion(user, messages); commandResponces(user, "RPL_WELCOME"); break ;
		//case false : dispatcher(user, message_protocole); break ;
	}
	 
}

void Server::commandResponces(User &user, std::string cmd)
{
	(void)cmd;
	std::stringstream result; 

	result << "001" << " ";
	result << ":Welcome to the Internet Relay Chat Network, " << user.getNickName();
	result << DELIMITER;

	user._outputMessage += result.str();
	send(user.getFd(), user._outputMessage.c_str(), user._outputMessage.size(), 0); 
	//result.clear();
	//this->sendMessage();
}

void Server::dispatcher(User &user, std::string message_protocole)
{
	(void)user;
	(void)message_protocole;
}

void Server::sendMessage(void)
{
	std::cout << "----- sendMessage ------" << std::endl;
	for (std::map<int, User>::iterator itb = users_list.begin(); itb != users_list.end(); itb++)
	{
		if (itb->second._outputMessage.size() > 0)
			std::cout << "Sending fd: " << itb->first << " : >" << itb->second._outputMessage << "<" << std::endl;

		if(send(itb->first, itb->second._outputMessage.c_str(), itb->second._outputMessage.length(), 0) == -1)
			std::cout << "Send error " << std::endl; 
		// std::cout << "Finished sending User._outputMessage to fd : " << itb->first << std::endl;
		itb->second._outputMessage.clear();
	}
}

void Server::disconnected(User &user)
{
	getpeername(user.getFd(), (struct sockaddr *)&my_addr, (socklen_t *)&peer_addr_size);
	std::cout << "Host disconnected , ip " << inet_ntoa(my_addr.sin_addr) << " , port " << ntohs(my_addr.sin_port) << std::endl;
	close(user.getFd());
	users_list.erase(user.getFd());
}

static std::vector<std::string> split(std::string msg)
{
	std::vector<std::string> temp;
	temp.clear(); // verifier si utile
	int increm = 0;
	int mem = 0;
	std::string::iterator it;

	for(it = msg.begin(); it != msg.end(); it++)
	{
		if (*it == ' ') {
			temp.push_back(msg.substr(mem , increm - mem));
			increm++;
			mem = increm;
		}
		else
			increm++;
	}
	if (it == msg.end())
		temp.push_back(msg.substr(mem , increm - mem));
	return (temp);
}

// /connect localhost 6667 coco

void Server::firstConnexion(User &user, std::vector<std::string> messages) 
{
	std::string password = ""; //if password == "" after ALL return this and disconneted ?
	std::string nickname = "";
	std::string username = "";

	std::vector<std::string>::iterator itm;

	for (itm = messages.begin() ; itm != messages.end(); itm++)
	{
		std::cout << "vector_message_protocole = >" << *itm << "<" << std::endl; 
		std::string msg = *itm;
		std::vector<std::string> data = split(msg);
		msg.clear();
		std::cout << "data[0] = " << data[0] << std::endl;
		
		//PASS
		if (data[0].compare("PASS") == 0) {
			password = data[1];
			if (password == this->getPassword())
				std::cout << "great password" << std::endl;
			else {
				std::cout << "Invalid password" << std::endl;
				this->disconnected(user); return ; }}
		//NICK
		else if (data[0].compare("NICK") == 0) {
			nickname = data[1];
			if (nickname.size() > 9) {
				std::cout << "Please tape '/set NICK <nickname>' cause it has more than 9 characters >"<< nickname << "<" <<  std::endl;
				this->disconnected(user); return ;}
			else {
				std::map<int, User>::iterator itv;
				for (itv = users_list.begin(); itv != users_list.end(); itv++) {
					if (nickname == itv->second.getNickName()) {
						std::cout << "You have the same Nickname than aan other user, please change : >" << itv->second.getNickName() << "<" << std::endl;
						this->disconnected(user); return ; }}}}
		//USER
		else if (data[0].compare("USER") == 0)
		{
			std::vector<std::string>::iterator d;
			for (d = ++data.begin(); d != data.end(); d++)
			username.append(*d);
		}
	
		data.clear();
	}
		
	if (nickname == "" || password == "" || username == "") {
	{
		std::cout << "ICI" << std::endl;
		this->disconnected(user); return ;}}
	else {
		user.setNickName(nickname); 
		user.setUserName(username);
		user.setFirstConnexion(false);
		messages.clear(); return ; } //return necessaire ?
	}
