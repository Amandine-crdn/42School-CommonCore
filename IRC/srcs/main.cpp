#include "Server/Server.hpp"

int main(int argc, const char **argv)
{
    Server server;
    if (argc != 3)
       server.error("need this format: /ircserv <port> <password>");
    server.init_server(argv[1], argv[2]);
    
    while (1)
    {
        server.connect(); //poll + accept
        server.intercept(); //protocole msg
        server.checker(); //first co or next
    }

    //1 ou les 2 ?
    //close(server.getServerFd()); // closing the connected socket
    //shutdown(server.getServerFd(), SHUT_RDWR); // closing the listening socket
    std::cout << "close" << std::endl;

}
//send, recv (read and write), close