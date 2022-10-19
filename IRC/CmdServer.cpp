// /connect localhost 6667 coco

///RMRECONNS !!




 // /connect localhost 6667 coco


/*void Server::kickCmd(User &user, std::vector<std::string> data) {
	
	std::cout << "1" << std::endl;

	if (data.size() < 3) {
		this->clientMessage(user, ERR_NEEDMOREPARAMS); return; }
	std::cout << "2" << std::endl;

	std::vector<std::string> channels_list = this->split(data[1], ',');
	std::vector<std::string> users_list = this->split(data[2], ',');

	std::cout << "yes" << std::endl;


}*/
//kick command : if OPERATOR == true , /KICK channel user (part un user d'un channel)
