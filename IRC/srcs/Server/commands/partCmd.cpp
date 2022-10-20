#include "../Server.hpp"

void Server::partCmd(User &user, std::vector<std::string> data)
{
	if (data.size() != 2) { this->clientMessage(user, ERR_NEEDMOREPARAMS); return; } 
		// check if channops list, to delete inside

	std::vector<std::string> channels_list = this->split(data[1], ',');
	std::vector<std::string>::iterator end = channels_list.end();
	bool find;

	for (std::vector<std::string>::iterator itlist = channels_list.begin(); itlist != end; itlist++)
	{
		find = false;
		for (std::vector<std::string>::iterator itc = user.channels_list_by_user.begin(); itc != user.channels_list_by_user.end();)
		{
			if ((*itc).compare("#" + *itlist) == 0)
			{
				find = true;
				itc = user.channels_list_by_user.erase(itc);
			}
			else
				++itc;
			if (find == false)
				this->clientMessage(user, ERR_NOTONCHANNEL, *itlist);
		}
	}
}
