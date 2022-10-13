#   include "Server.hpp"

std::vector<std::string> Server::split(std::string msg, char delimiter)
{
	std::vector<std::string> temp;
	int increm = 0;
	int mem = 0;
	std::string::iterator it;

	for(it = msg.begin(); it != msg.end(); it++)
	{
		if (*it == delimiter) {
			temp.push_back(msg.substr(mem , increm - mem));
			mem = ++increm;
		}
		else
			increm++;
	}
	if (it == msg.end())
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