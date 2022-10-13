#include "Server.hpp"

void Server::error(std::string error)
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