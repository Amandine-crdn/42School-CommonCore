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

void Server::check_connexion(User &user)
{
	if (user.getFirstConnexion() == true && user.getNickName() != "" && user.getUserName() != "")
	{
		user.setFirstConnexion(false);
		this->clientMessage(user, RPL_WELCOME);
	}	
}

void Server::eraseChannel(std::string channel_name)
{
	for (std::vector<Channel>::iterator itc = channels_list.begin(); itc != channels_list.end(); itc++)
	{
		if (itc->getChannelName() == channel_name)
		{
			this->channels_list.erase(itc);
			return ;
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

