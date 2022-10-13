#   include "Server.hpp"

void Server::checker(User &user, std::vector<std::string> messages)
{
	switch (user.getFirstConnexion())
	{
		case true : this->firstConnexion(user, messages); commandResponces(user, "RPL_WELCOME"); break ;
		case false : dispatcher(user, messages); break ;
	}
}

void Server::firstConnexion(User &user, std::vector<std::string> messages) 
{
	std::vector<std::string>::iterator itm;
	std::string password = "";
	std::string nickname = "";
	std::string username = "";

	for (itm = messages.begin() ; itm != messages.end(); itm++)
	{
		std::string msg = *itm;
		std::vector<std::string> data = this->split(msg);
		
		std::cout << "\t🪶  🖥️  IRSSI = >" << *itm << "<" << std::endl;
		if (data[0].compare("PASS") == 0){
			if (this->passCmd(user, data) == ""){
				this->disconnected(user); return ; }}
		else if (data[0].compare("NICK") == 0) {
			nickname = this->nickCmd(user, data);
			if (nickname == "") {
				this->disconnected(user); return ; }}
		else if (data[0].compare("USER") == 0)
			username = this->userCmd(data);

		data.clear();
	}
		
	if (nickname == "" || username == "") {
		this->disconnected(user); }
	else {
		user.setNickName(nickname); 
		user.setUserName(username);
		user.setFirstConnexion(false);}

	messages.clear();
	std::cout << std::endl;
}

void Server::dispatcher(User &user, std::vector<std::string> messages)
{
	(void)user;
	(void)messages;
}


// /connect localhost 6667 coco

void Server::disconnected(User &user)
{
	getpeername(user.getFd(), (struct sockaddr *)&my_addr, (socklen_t *)&peer_addr_size);
	std::cout << "Host disconnected , ip " << inet_ntoa(my_addr.sin_addr) << " , port " << ntohs(my_addr.sin_port) << std::endl;
	close(user.getFd());
	users_list.erase(user.getFd());
}