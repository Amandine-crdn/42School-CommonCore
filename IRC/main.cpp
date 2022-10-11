#include "Server.hpp"

int main()
{
    Server server;
    server.init_server();
    while (1) ;
   
    // closing the connected socket
    close(server.getNewSocket());
    // closing the listening socket
    shutdown(server.getServerFd(), SHUT_RDWR);
    std::cout << "close" << std::endl;

}
//send, recv (read and write), close