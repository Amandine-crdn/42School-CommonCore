 #include "Server.hpp"

void Server::nickCmd(User &user, std::string msg, bool first)
{
	std::map<int, User>::iterator itb;
	std::string nickname;
	
	nickname = msg.substr(5, msg.size() - 5);

	if (!nickname.size())
	{
		this->clientMessage(user, ERR_NEEDMOREPARAMS);
		if (first == true)
			this->disconnected(user);
		return ;
	}
	if (nickname.size() > 9)
	{
		this->clientMessage(user, ERR_ERRONEUSNICKNAME, nickname);
		if (first == true)
			this->disconnected(user);
		return ;
	}
	for (itb = users_list.begin(); itb != users_list.end(); itb++)
	{
		if (nickname.find(itb->second.getNickName()) == 0)
		{
			this->clientMessage(user, ERR_NICKNAMEINUSE, nickname);
			if (first == true)
				this->disconnected(user);
			return ;
		}
	}
	user.setNickName(nickname);
}