 #include "../Server.hpp"

void Server::nickCmd(User &user, std::string msg, std::vector<std::string> data)
{
	if (user.getAllow() == false)
		return ;

	if (data.size() == 1)
	{
		this->clientMessage(user, ERR_NONICKNAMEGIVEN);
		return ;
	}

	std::string nickname = msg.substr(5, msg.size() - 5);

	if (nickname.size() > 9)
	{
		this->clientMessage(user, ERR_ERRONEUSNICKNAME, nickname);
		return ;
	}

	for (std::vector<User>::iterator itv = utilisateurs_list.begin(); itv != utilisateurs_list.end(); itv++)
	{
		if (nickname == itv->getNickName())
		{
			this->clientMessage(user, ERR_NICKNAMEINUSE, nickname);
			return ;
		}
	}
	
	user.setNickName(nickname);
}