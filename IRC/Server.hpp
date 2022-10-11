#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <vector>
#include <cstring>

class Server {

    public :
        Server();
        ~Server();
        void init_server(const char *port, const char *password);
        void error(std::string error);
        //serverfd
        int getServerFd();
        void setServerFd(int server_fd);
        //newsocket
        int getNewSocket();
        void setNewSocket(int new_socket);
        //password
        std::string getPassword();
        void setPassword(std::string password);
        

        

    private :

        int server_fd, new_socket;
        sockaddr_in my_addr;
        socklen_t peer_addr_size;
        std::string password;

};

#endif