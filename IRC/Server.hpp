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
#include <fcntl.h>
#include <ctime>
#include <sstream>

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
        void intercept();
        void sendMessage();
        void commandResponces(User &user, std::string cmd);
        void checker(User &user, std::vector<std::string> messages);
        void disconnected(User &user);
        void firstConnexion(User &user, std::vector<std::string> messages);
        void dispatcher(User &user, std::string message_protocole);

        /* getters and setters */

        //serverfd
        int getServerFd() const;
        void setServerFd(int server_fd);

        //password
        std::string getPassword() const;
        void setPassword(std::string password);

        //pollfds
        std::vector<pollfd> getPollFds() const;
        void setPollFds(pollfd poll_fd);
        
    private :

        //init
        int server_fd;
        sockaddr_in my_addr;
        socklen_t peer_addr_size;
        std::string password;
        const std::string server_name = "ft_irc";

        //connect
        std::vector<pollfd> poll_fds;
        std::map<int, User> users_list;

};

#endif