#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h> 
class Server {

    public :
        Server();
        ~Server();
        void init_server();

        int getNewSocket();
        int getServerFd();
        /*
        void setServerFd(int server_fd);

        void setNewSocket(int new_socket);
        */

    private :

        int server_fd, new_socket;
        sockaddr_in my_addr;
        socklen_t peer_addr_size;

};

#endif