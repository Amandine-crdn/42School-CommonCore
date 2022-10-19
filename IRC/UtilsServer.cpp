#   include "Server.hpp"

std::map<int, User>::iterator Server::beginMap()
{
	std::map<int, User>::iterator itb;

	itb = users_list.begin();
	return (itb);
}

std::map<int, User>::iterator Server::endMap()
{
	std::map<int, User>::iterator ite;

	ite = users_list.end();
	return (ite);
}

User &Server::getUserByFd(int fd)
{
	std::map<int, User>::iterator itb;

	for (itb = this->beginMap(); itb != this->endMap(); itb++)
	{
		if (itb->first == fd)
			break ;
	}
	return (itb->second);
}

void Server::setUserFd(int fd)
{
	this->users_list[fd];
}


void Server::eraseUser(int fd)
{
	std::map<int, User>::iterator itb;

	for (itb = this->beginMap(); itb != this->endMap(); itb++)
	{
		if (itb->first == fd)
		{
			close(itb->first);
			itb = this->users_list.erase(itb);
		}
	}
}


std::vector<std::string> Server::split(std::string msg, char delimiter)
{
	std::vector<std::string> temp;
	if (msg.find(delimiter) == 0) {
		temp.push_back(msg);
		return (temp); }

	int increm = 0;
	int mem = 0;

	for(std::string::iterator it = msg.begin(); it != msg.end(); it++) {
		if (*it == delimiter) {
			temp.push_back(msg.substr(mem , increm - mem));
			mem = ++increm; }
		else
			increm++; }
	temp.push_back(msg.substr(mem , increm - mem));
	return temp;
}

void Server::error(std::string error) //change for error send ?
{
    //close and exit
    std::cout << "🔥 " << error << std::endl; //cf norme des erreurs
    
    // close tous les fd poll ??  close(itp->fd); ?

    // closing the connected socket   /// nned des 2 ?
    close(this->getServerFd());
    // closing the listening socket
    shutdown(this->getServerFd(), SHUT_RDWR);
    std::cout << "close with error" << std::endl;
    // prk destructor server no called when close ?
    exit (-1);
}


void Server::notificationJoinChannel(User &user, std::string channel_name) 
{
	for (std::map<int, User>::iterator itu = users_list.begin(); itu != users_list.end(); itu++) {
	for (std::vector<std::string>::iterator iterator = itu->second.channels_list_by_user.begin(); iterator != itu->second.channels_list_by_user.end(); iterator++) {
		if ((*iterator).compare(channel_name) == 0 && user.getNickName() != itu->second.getNickName()) { // pas a lui-meme
			
			std::stringstream result_chan;
			result_chan << ":" << user.getFullClientIdentifier() << " JOIN " << channel_name << DELIMITER;
			std::string test = result_chan.str(); 
			send(itu->first, test.c_str(), test.length(), 0); }}}
}

void Server::notificationsUsersInChannel(User &user, std::string channel_name)
{
	std::string users = "";

	for (std::map<int, User>::iterator itu = users_list.begin(); itu != users_list.end(); itu++) {
		for (std::vector<std::string>::iterator iterator = itu->second.channels_list_by_user.begin(); iterator != itu->second.channels_list_by_user.end(); iterator++) {
			if ((*iterator).compare(channel_name) == 0) {
				users += "@";
				users += itu->second.getNickName();
				users += " "; }}}
	(void)user;
	this->clientMessage(user, RPL_NAMREPLY, channel_name, users);
	this->clientMessage(user, RPL_ENDOFNAMES, channel_name, users); // ?
}
