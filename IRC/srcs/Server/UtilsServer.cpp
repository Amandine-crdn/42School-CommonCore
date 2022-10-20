#   include "Server.hpp"

std::vector<User>::iterator Server::beginVectorUser()
{
	std::vector<User>::iterator itb;

	itb = utilisateurs_list.begin();
	return (itb);
}

std::vector<User>::iterator Server::endVectorUser()
{
	std::vector<User>::iterator ite;

	ite = utilisateurs_list.end();
	return (ite);
}

std::vector<User>::iterator Server::getUserByFd(int fd)
{ 
	std::vector<User>::iterator itb;

	for (itb = this->beginVectorUser(); itb != this->endVectorUser(); itb++)
	{
		if (itb->getFd() == fd)
			break ;
	}
	return (itb);
}

void Server::setUser(int fd)
{
	utilisateurs_list.push_back(User(fd));
}

void Server::clearUser(User &user)
{
	this->utilisateurs_list.erase(getUserByFd(user.getFd()));
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
	for (std::vector<User>::iterator itu = utilisateurs_list.begin(); itu != utilisateurs_list.end(); itu++) {
	for (std::vector<std::string>::iterator iterator = itu->channels_list_by_user.begin(); iterator != itu->channels_list_by_user.end(); iterator++) {
		if ((*iterator).compare(channel_name) == 0 && user.getNickName() != itu->getNickName()) { // pas a lui-meme
			
			std::stringstream result_chan;
			result_chan << ":" << user.getFullClientIdentifier() << " JOIN " << channel_name << DELIMITER;
			std::string test = result_chan.str(); 
			send(itu->getFd(), test.c_str(), test.length(), 0); }}}
}

void Server::notificationsUsersInChannel(User &user, std::string channel_name)
{
	std::string users = "";

	for (std::vector<User>::iterator itu = utilisateurs_list.begin(); itu != utilisateurs_list.end(); itu++) {
		for (std::vector<std::string>::iterator iterator = itu->channels_list_by_user.begin(); iterator != itu->channels_list_by_user.end(); iterator++) {
			if ((*iterator).compare(channel_name) == 0) {
				users += "@";
				users += itu->getNickName();
				users += " "; }}}
	(void)user;
	this->clientMessage(user, RPL_NAMREPLY, channel_name, users);
	this->clientMessage(user, RPL_ENDOFNAMES, channel_name, users); // ?
}
