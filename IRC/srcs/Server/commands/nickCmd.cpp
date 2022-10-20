 #include "../Server.hpp"

void Server::nickCmd(User &user, std::string msg)
{
		std::string nickname;
	
	nickname = msg.substr(5, msg.size() - 5);

	if (!nickname.size())
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS);
			std::cout << "🇸🇯 4\n";	
		return ;
	}
	if (nickname.size() > 9)
	{
		this->clientMessage(user, ERR_ERRONEUSNICKNAME, nickname);
			std::cout << "🇸🇯 1\n";
		return ;
	}
	for (std::vector<User>::iterator itv = utilisateurs_list.begin(); itv != utilisateurs_list.end(); itv++)
	{
		if (nickname == itv->getNickName())
		{
			std::stringstream result;

			result << ": 433";
			result << user.getNickName() << " " << nickname << " :Nickname is already in use";
			result << DELIMITER;

			std::cout << "NICKNAME = " << nickname << std::endl;
			std::cout << "NICKNAME GET = " << itv->getNickName() << std::endl;
			//this->clientMessage(user, ERR_NICKNAMEINUSE, nickname);
				std::cout << "🇸🇯 2\n";
			return ;
		}
	}
	user.setNickName(nickname);
}