#ifndef SERVER_HPP
#define SERVER_HPP

#   define BUFFER_SIZE 4096
#   define DELIMITER "\r\n"

#   include <iostream>
#   include <sys/socket.h>
#   include <errno.h>
#   include <netinet/in.h>
#   include <unistd.h>
#   include <arpa/inet.h> 
#   include <vector>
#   include <cstring>
#   include <poll.h>
#   include <map>
#   include <fcntl.h>
#   include <ctime>
#   include <sstream>

#   include "User.hpp"
#   include "ClientMessage.hpp"

class User;

class Server {

    public :

        Server();
        ~Server();

        /*------  methods Server ------ */

        void init_server(const char *port, const char *password);
        void error(std::string error);
        void connect();
        void intercept();
        void sendMessage();
        void clientMessage(User &user, std::string cmd);
        void checker(User &user, std::vector<std::string> messages);
        void disconnected(User &user);
        void firstConnexion(User &user, std::vector<std::string> messages);
        void dispatcher(User &user, std::vector<std::string> messages);


        /*------- utils -------*/

        std::vector<std::string> split(std::string msg, char delimiter);


        /*------ getters and setters ----- */

        int getServerFd() const;
        void setServerFd(int server_fd);
        std::string getPassword() const;
        void setPassword(std::string password);
        std::vector<pollfd> getPollFds() const;
        void setPollFds(pollfd poll_fd);
        std::vector<std::string> getChannelList() const;
        void setChannelList(std::string new_channel);
        


    protected :

        //init
        int server_fd;
        sockaddr_in my_addr;
        socklen_t peer_addr_size;
        std::string password;
        const std::string server_name = "ft_irc";

        //connect
        std::vector<pollfd> poll_fds;
        std::map<int, User> users_list;

        //all channel
        std::vector<std::string> channels_list;


        /*------  virtual methods CmdServer ------ */

        virtual std::string passCmd(User &user, std::vector<std::string> data, bool first);
        virtual std::string nickCmd(User &user, std::vector<std::string> data, bool first);
        virtual std::string userCmd(User &user,std::vector<std::string> data, bool first);
        virtual void modeCmd(User &user, std::vector<std::string> data);
        virtual void quitCmd(User &user, std::vector<std::string> data);
        virtual void pingCmd(User &user, std::vector<std::string> data);
        virtual void joinCmd(User &user, std::vector<std::string> data);
};

#endif