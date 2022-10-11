#include "Server.hpp"

int main(int argc, const char **argv)
{
    Server server;
    if (argc != 3)
       server.error("need this format: /ircserv <port> <password>");
    
    server.init_server(argv[1], argv[2]);
    while (1) ;
   
    // closing the connected socket
    close(server.getNewSocket());
    // closing the listening socket
    shutdown(server.getServerFd(), SHUT_RDWR);
    std::cout << "close" << std::endl;

}
//send, recv (read and write), close