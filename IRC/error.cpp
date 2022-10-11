#include "Server.hpp"

void Server::error(std::string error)
{
    std::cout << error << std::endl; //cf norme des erreurs
    //close and exit

    // closing the connected socket
    close(this->getNewSocket());
    // closing the listening socket
    shutdown(this->getServerFd(), SHUT_RDWR);
    std::cout << "close with error" << std::endl;
    // prk destructor server no called when close ?
    exit (-1);
}