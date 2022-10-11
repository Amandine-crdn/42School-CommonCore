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
#include <poll.h>
#include <map>

#include "User.hpp"
class User;

class Server {

    public :

        Server();
        ~Server();

        //method
        void init_server(const char *port, const char *password);
        void error(std::string error);
        void connect();

        /* getters and setters */

        //serverfd
        int getServerFd();
        void setServerFd(int server_fd);
        //newsocket
        int getNewSocket();
        void setNewSocket(int new_socket);
        //password
        std::string getPassword();
        void setPassword(std::string password);
        //pollfds
        std::vector<pollfd> getPollFds();
        void setPollFds(pollfd poll_fd);
        

    private :

        //init
        int server_fd, new_socket;
        sockaddr_in my_addr;
        socklen_t peer_addr_size;
        std::string password;
        const std::string server_name = "ft_irc";

        //connect
        std::vector<pollfd> poll_fds;
        std::map<int, User> users_list;

};

#endif